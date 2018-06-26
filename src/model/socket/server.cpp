/*
 * server.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#include "model/socket/server.hpp"
#include "model/socket/connection.hpp"
#include "model/socket/exceptions/exception-socket-not-available.hpp"
#include "model/socket/exceptions/exception-port-in-use.hpp"
#include "model/socket/exceptions/exception-cannot-listen.hpp"
#include "model/socket/exceptions/exception-cannot-accept-connection.hpp"

#include <string>

using namespace std;

SocketServer::SocketServer(uint16_t port, Logger &logger) : logger(logger)
{

	this->is_running = false;
	this->socket_opt = 0;
	this->socket_fd = 0;
	this->port = port;
}

uint16_t SocketServer::get_port()
{
	return this->port;
}

void SocketServer::start()
{

	// Creating socket file descriptor
	this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket_fd == 0)
	{
		throw ExceptionSocketNotAvailable();
	}

	if (setsockopt(this->socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &(this->socket_opt), sizeof(socket_opt)))
	{
		throw ExceptionPortInUse(this->port);
	}

	this->address.sin_family = AF_INET;
	this->address.sin_addr.s_addr = INADDR_ANY;
	this->address.sin_port = htons(this->port);

	if (bind(this->socket_fd, (struct sockaddr *) &(this->address), sizeof(this->address)) < 0)
	{
		throw ExceptionPortInUse(this->port);
	}

	if (listen(this->socket_fd, 3) < 0)
	{
		throw ExceptionCannotListen();
	}

	this->on_start_listening.fire("Started listening");

	this->is_running = true;

	while(this->is_running)
	{

		int addrlen = sizeof(this->address);
		int connection_fd = accept(this->socket_fd, (struct sockaddr *) &address, (socklen_t*) &addrlen);

		if (connection_fd < 0)
		{
			throw ExceptionCannotAcceptConnections();
		}

		// Create and bind events
		Connection *connection = new Connection(connection_fd, address);

		this->connections_add(*connection);

		this->on_connection_open.fire(*connection);
		connection->detach();
	}
}

void SocketServer::connections_add(Connection connection)
{
	this->connections.insert(pair<uint32_t, Connection>(connection.get_fd(), connection));
}

void SocketServer::connections_remove(Connection connection)
{
	this->connections.erase(connection.get_fd());
}

void SocketServer::stop()
{

}

list<uint32_t> SocketServer::get_connections()
{
	list<uint32_t> result;

	for(auto const& imap: this->connections)
	{
	    result.push_back(imap.first);
	}

	return result;
}
