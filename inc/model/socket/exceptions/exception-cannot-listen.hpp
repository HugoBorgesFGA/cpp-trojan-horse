/*
 * exception-port-in-use.hpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#ifndef INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_CANNOT_LISTEN_HPP_
#define INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_CANNOT_LISTEN_HPP_

#include <exception>

class ExceptionCannotListen : public std::exception
{

public:

	const char* what() const throw()
	{
		return "Could not listen to socket";
	}
};

#endif /* INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_CANNOT_LISTEN_HPP_ */
