#ifndef H_SOCKET_SERVER
#define H_SOCKET_SERVER

#include <cstdint>
#include <map>
#include <list>

#include "event.hpp"
#include "connection.hpp"

using namespace std;

class SocketServer
{

private:

	uint32_t seed;
	map<uint32_t, Connection&> connections;

public:

	SocketServer(uint16_t port);

	void start();
	void stop();
	list<uint32_t> get_connections();

	Event<uint32_t> on_connection_open;
	Event<uint32_t> on_connection_close;
	Event<string> on_start_listening;
	Event<string> on_stop_listening;
};

#endif
