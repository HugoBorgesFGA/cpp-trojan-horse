/*
 * server_victims.cpp
 *
 *  Created on: Jul 1, 2018
 *      Author: hugo
 */

#include <sstream>

#include "controller/context.hpp"
#include "controller/server_victims.hpp"

#include "model/socket/connection.hpp"
#include "model/socket/server.hpp"
#include "model/loggers/console-logger.hpp"

// When a connection is open, exec the following method
void Victims::on_connection_open_callback(struct ConnectionInfo &connection_info){

	stringstream ss_message;
	ss_message << "New connection (" << connection_info.connection << ") opened...";

	Context::logger_victims->info(ss_message.str());
}

void Victims::on_connection_received_data_callback(struct DataReceivedArgs &args){

	stringstream ss_message;
	ss_message << "Connection (" << args.connection_info.connection << "): " << args.message;

	Context::logger_victims->info(ss_message.str());
}

void Victims::on_connection_close_callback(struct ConnectionInfo &connection_info){

	stringstream ss_message;
	ss_message << "Connection " << connection_info.connection << " just closed...";

	Context::logger_victims->info(ss_message.str());
}
