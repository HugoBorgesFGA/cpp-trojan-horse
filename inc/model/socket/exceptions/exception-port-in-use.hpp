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

	uint16_t port;

public:

	ExceptionPortInUse(uint16_t port)
	{

		this->port = port;
	}

	virtual const char* what() const throw()
	{

		std::stringstream description;

		description << "The chosen TCP port (" << this->port << ") is already in use";

		return description.str().c_str();
	}
};

#endif /* INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_PORT_IN_USE_HPP_ */
