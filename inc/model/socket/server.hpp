#ifndef H_SOCKET_SERVER
#define H_SOCKET_SERVER

#include <cstdint>
#include <list>

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "model/event.hpp"
#include "model/connection.hpp"

#include "model/loggers/console-logger.hpp"

using namespace std;

class SocketServer
{

private:

	uint32_t seed;
	map<uint32_t, Connection&> connections;
	uint16_t port;

	uint32_t socket_fd, socket_opt;
	struct sockaddr_in address;

	Logger &logger;

public:

	SocketServer(uint16_t port, Logger &logger);

	uint16_t get_port();

	void start();
	void stop();
	list<uint32_t> get_connections();

	Event<uint32_t> on_connection_open;
	Event<uint32_t> on_connection_close;
	Event<string> on_start_listening;
	Event<string> on_stop_listening;
};

#endif
