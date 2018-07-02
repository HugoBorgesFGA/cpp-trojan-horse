/*
 * server_attacker.cpp
 *
 *  Created on: Jul 1, 2018
 *      Author: hugo
 */

#include <sstream>

#include "controller/context.hpp"
#include "controller/server_attacker.hpp"

#include "model/socket/connection.hpp"
#include "model/socket/server.hpp"
#include "model/loggers/console-logger.hpp"

// When a connection is open, exec the following method
void Attacker::on_connection_open_callback(struct ConnectionInfo &connection_info){

	stringstream ss_message;
	ss_message << "New connection (" << connection_info.connection << ") opened...";

	Context::logger_attacker->info(ss_message.str());
}

void Attacker::on_connection_received_data_callback(struct DataReceivedArgs &args){

	stringstream ss_message;
	ss_message << "Connection (" << args.connection_info.connection << "): " << args.message;

	Context::logger_attacker->info(ss_message.str());
}

void Attacker::on_connection_close_callback(struct ConnectionInfo &connection_info){

	stringstream ss_message;
	ss_message << "Connection " << connection_info.connection << " just closed...";

	Context::logger_attacker->info(ss_message.str());
}
