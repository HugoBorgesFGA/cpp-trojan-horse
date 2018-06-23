/*
 * server.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#include "model/socket/server.hpp"

SocketServer::SocketServer(uint16_t port)
{

	this->port = port;
}

uint16_t SocketServer::get_port()
{
	return this->port;
}

void SocketServer::start()
{

}

void SocketServer::stop()
{

}

list<uint32_t> SocketServer::get_connections()
{

}
