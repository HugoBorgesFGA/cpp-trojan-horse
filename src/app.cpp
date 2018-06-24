#include <cstdint>
#include <iostream>

#include "config.hpp"

#include "model/socket/server.hpp"
#include "model/loggers/console-logger.hpp"

using namespace std;

int main(int argc, char *argv[]){

	Logger *logger_app = new ConsoleLogger("APP", CONFIG_DEBUG);
	Logger *logger_server = new ConsoleLogger("SERVER", CONFIG_DEBUG);

	SocketServer server(CONFIG_PORT, *logger_server);

	try
	{

		server.start();
	}
	catch(exception &ex)
	{
		logger_app->error(string(ex.what()));
	}

	return 0;
}
