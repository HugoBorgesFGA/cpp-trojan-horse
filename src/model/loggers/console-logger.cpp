#include "model/loggers/console-logger.hpp"

#include <iostream>

ConsoleLogger::ConsoleLogger(string module_name, bool debug_enable) : Logger(module_name, debug_enable)
{

	if (this->is_debug_enable)
	{
		this->debug("Initializing logger...");
	}
}

void ConsoleLogger::info(string message)
{

	cout << Logger::_default_log_line("INFO", message);
}

void ConsoleLogger::error(string message)
{

	cout << Logger::_default_log_line("ERROR", message);
}

void ConsoleLogger::warning(string message)
{

	cout << Logger::_default_log_line("WARNING", message);
}

void ConsoleLogger::debug(string message)
{

	cout << Logger::_default_log_line("DEBUG", message);
}

