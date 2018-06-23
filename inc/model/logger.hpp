/*
 * logger.hpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#ifndef INC_MODEL_LOGGER_HPP_
#define INC_MODEL_LOGGER_HPP_

#include <sstream>

using namespace std;

class Logger {

protected:

	string module_name;
	bool is_debug_enable;

	string _default_log_line(string module_name, string message)
	{
		stringstream log_line;

		log_line << "[" << module_name << "] : " << message;

		return log_line.str();
	}

public:

	Logger(string module_name, bool debug_enable)
	{

		this->module_name = module_name;
		this->is_debug_enable = debug_enable;
	}

	virtual void info(string message) = 0;
	virtual void error(string message) = 0;
	virtual void warning(string message) = 0;
	virtual void debug(string message) = 0;
};


#endif /* INC_MODEL_LOGGER_HPP_ */
