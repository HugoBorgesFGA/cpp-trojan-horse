/*
 * context.hpp
 *
 *  Created on: Jul 1, 2018
 *      Author: hugo
 */

#ifndef INC_CONTROLLER_CONTEXT_HPP_
#define INC_CONTROLLER_CONTEXT_HPP_

#include <cstdint>

#include "model/socket/connection.hpp"
#include "model/socket/server.hpp"
#include "model/loggers/console-logger.hpp"

namespace Context {

	// Constants
	const uint16_t server_attacker_port = 12345;
	const uint16_t server_victims_port = 6666;
	const bool debug_enable = true;

	// Loggers
	extern Logger *logger_app;
	extern Logger *logger_attacker;
	extern Logger *logger_victims;

	// Servers
	extern SocketServer *server_attacker;
	extern SocketServer *server_victims;

	void init_resources();
}


#endif /* INC_CONTROLLER_CONTEXT_HPP_ */
