/*
 * console-logger.hpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#ifndef INC_MODEL_LOGGERS_CONSOLE_LOGGER_HPP_
#define INC_MODEL_LOGGERS_CONSOLE_LOGGER_HPP_

#include "model/logger.hpp"

class ConsoleLogger : public Logger
{

public:

	ConsoleLogger(string module_name, bool debug_enable);

	void info(string message);
	void error(string message);
	void warning(string message);
	void debug(string message);
};



#endif /* INC_MODEL_LOGGERS_CONSOLE_LOGGER_HPP_ */
