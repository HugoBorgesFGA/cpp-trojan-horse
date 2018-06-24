/*
 * exception-port-in-use.hpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#ifndef INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_PORT_IN_USE_HPP_
#define INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_PORT_IN_USE_HPP_

#include <exception>
#include <cstdint>
#include <sstream>

class ExceptionPortInUse : public std::exception
{
private:

	std::string message;
	uint16_t port;

public:

	ExceptionPortInUse(uint16_t port)
	{
		std::stringstream ss_builder;

		this->port = port;
		ss_builder << "The chosen port (" << this->port << ") is already in use!";

		this->message = ss_builder.str();
	}

	const char* what() const throw()
	{

		return this->message.c_str();
	}
};

#endif /* INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_PORT_IN_USE_HPP_ */
