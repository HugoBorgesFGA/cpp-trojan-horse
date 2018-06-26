/*
 * connection.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#include "model/socket/connection.hpp"

#include <iostream>

Connection::Connection(uint32_t connection_fd, struct sockaddr_in address)
{

	this->buffer = new uint8_t[CONFIG_CONNECTION_BUFFER_SIZE];
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

		uint32_t read_bytes = read(this->get_fd() , this->buffer, CONFIG_CONNECTION_BUFFER_SIZE);
		if (read_bytes == 0) {
			cout << "Ending thread..." << endl;
			break;
		}

		this->buffer[read_bytes] = '\0';

		string received = string((char *) this->buffer);
		this->buffer[0] = '\0';

		cout << "Connection (" << this->get_fd() << ") received: " << received;
	}
}

void Connection::detach()
{
	thread connection_thread([this] { this->_thread_function(); });
	connection_thread.detach();
}

void Connection::close()
{

}
