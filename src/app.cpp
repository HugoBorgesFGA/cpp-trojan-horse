#include <cstdint>
#include <iostream>

#include "config.hpp"

#include "model/socket/server.hpp"
#include "model/socket/exceptions/exception-port-in-use.hpp"

#include "model/loggers/console-logger.hpp"

using namespace std;

int main(int argc, char *argv[]){

	SocketServer server(CONFIG_PORT);
	Logger *logger_app = new ConsoleLogger("APP", CONFIG_DEBUG);

	try
	{

		server.start();
	}
	catch(ExceptionPortInUse &ex)
	{
		logger_app->error(ex.what());
	}

	return 0;
}
