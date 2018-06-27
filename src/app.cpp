#include <cstdint>
#include <iostream>
#include <sstream>

#include "config.hpp"

#include "model/socket/connection.hpp"
#include "model/socket/server.hpp"
#include "model/loggers/console-logger.hpp"

using namespace std;

Logger *logger_app;
Logger *logger_server;

SocketServer *server;

// When a connection is open, exec the following method
void on_connection_open_callback(struct ConnectionInfo &connection_info){

	stringstream ss_message;
	ss_message << "New connection (" << connection_info.connection << ") opened...";

	logger_app->info(ss_message.str());
}

void on_connection_received_data_callback(struct DataReceivedArgs &args){

	stringstream ss_message;
	ss_message << "Connection (" << args.connection_info.connection << "): " << args.message;

	logger_app->info(ss_message.str());
}

void on_connection_close_callback(struct ConnectionInfo &connection_info){

	stringstream ss_message;
	ss_message << "Connection " << connection_info.connection << " just closed...";

	logger_app->info(ss_message.str());
}

// When receive something


int main(int argc, char *argv[]){

	logger_app = new ConsoleLogger("APP", CONFIG_DEBUG);
	logger_server = new ConsoleLogger("SERVER", CONFIG_DEBUG);

	server = new SocketServer(CONFIG_PORT, *logger_server);
	server->on_connection_open.add(on_connection_open_callback);
	server->on_data_received.add(on_connection_received_data_callback);
	server->on_connection_close.add(on_connection_close_callback);

	try
	{
		server->start();
	}
	catch(exception &ex)
	{
		logger_app->error(string(ex.what()));
	}

	return 0;
}
