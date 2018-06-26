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
void on_connection_open_callback(Connection &connection){

	stringstream ss_message;
	ss_message << "New connection (" << connection.get_fd() << ") opened...";

	logger_app->info(ss_message.str());
}

// When receive something


int main(int argc, char *argv[]){

	logger_app = new ConsoleLogger("APP", CONFIG_DEBUG);
	logger_server = new ConsoleLogger("SERVER", CONFIG_DEBUG);

	server = new SocketServer(CONFIG_PORT, *logger_server);
	server->on_connection_open.add(on_connection_open_callback);

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
