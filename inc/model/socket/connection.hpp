#ifndef INC_MODEL_CONNECTION_HPP_
#define INC_MODEL_CONNECTION_HPP_

#include <cstdint>
#include <string>
#include <thread>
#include <tuple>

#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "config.hpp"
#include "model/event.hpp"

using namespace std;

class Connection
{

private:

	uint8_t *buffer;
	uint32_t connection_fd;
	struct sockaddr_in address;

	void _thread_function();
public:

	Connection(uint32_t connection_fd, struct sockaddr_in address);

	uint32_t get_fd();

	void detach();
	void send(string message);
	void close();

	~Connection();
};

#endif /* INC_MODEL_CONNECTION_HPP_ */
