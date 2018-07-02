/*
 * connection.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#include "model/socket/connection.hpp"

#include <iostream>

struct ConnectionInfo Connection::getConnectionInfo(Connection &connection){

	struct ConnectionInfo result = {
		.connection = connection.get_fd(),
		.client_ip = "127.0.0.1"
	};

	return result;
}

Connection::Connection(
		uint32_t connection_fd,
		struct sockaddr_in address,
		Event<DataReceivedArgs> &on_data_received,
		Event<ConnectionInfo> &on_connection_close
) :
on_data_received(on_data_received),
on_connection_close(on_connection_close)
{

	this->buffer = new uint8_t[connections_buffer_size];
	this->connection_fd = connection_fd;
	this->address = address;
}

Connection::~Connection()
{

	delete this->buffer;
}

uint32_t Connection::get_fd()
{
	return this->connection_fd;
}

void Connection::send(string message)
{

	const char *_message = message.c_str();
	::send(this->connection_fd , _message, strlen(_message) , 0);
}

void Connection::_thread_function()
{
	while(true){

		uint32_t read_bytes = read(this->get_fd() , this->buffer, connections_buffer_size);
		if (read_bytes == 0) {
			break;
		}

		this->buffer[read_bytes] = '\0';

		string received = string((char *) this->buffer);
		this->buffer[0] = '\0';

		struct DataReceivedArgs args = {
				.connection_info = getConnectionInfo(*this),
				.message = received
		};

		this->on_data_received.fire(args);
	}

	this->on_connection_close.fire(getConnectionInfo(*this));
	delete this;
}

void Connection::detach()
{
	thread connection_thread([this] { this->_thread_function(); });
	connection_thread.detach();
}

void Connection::close()
{

}
