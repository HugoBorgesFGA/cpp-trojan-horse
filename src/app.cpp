#include <cstdint>

#include "config.hpp"
#include "model/server.hpp"

int main(int argc, char *argv[]){

	SocketServer server(12345);
	uint16_t port = CONFIG_PORT;
	return 0;
}
