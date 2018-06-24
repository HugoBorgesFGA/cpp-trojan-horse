/*
 * server.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#include "model/socket/server.hpp"
#include "model/socket/exceptions/exception-socket-not-available.hpp"
#include "model/socket/exceptions/exception-port-in-use.hpp"
#include "model/socket/exceptions/exception-cannot-listen.hpp"
#include "model/socket/exceptions/exception-cannot-accept-connection.hpp"

#include <string>

using namespace std;

SocketServer::SocketServer(uint16_t port, Logger &logger) : logger(logger)
{

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

	// Forcefully attaching socket to the port 8080
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

	int addrlen = sizeof(this->address);
	int new_socket = accept(this->socket_fd, (struct sockaddr *) &address, (socklen_t*) &addrlen);

	if (new_socket < 0)
	{
		throw ExceptionCannotAcceptConnections();
	}

	char buffer[1024];

	uint32_t read_bytes = read( new_socket , buffer, sizeof(buffer));
	this->logger.debug(string(buffer));

	char accept_msg[] = "You just connected to server...";
	send(new_socket , accept_msg , strlen(accept_msg) , 0);
}

void SocketServer::stop()
{

}

list<uint32_t> SocketServer::get_connections()
{

}
