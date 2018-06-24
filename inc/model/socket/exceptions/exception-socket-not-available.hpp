/*
 * exception-port-in-use.hpp
 *
 *  Created on: Jun 23, 2018
 *      Author: hugo
 */

#ifndef INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_COULD_NOT_CREATE_SOCKET_HPP_
#define INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_COULD_NOT_CREATE_SOCKET_HPP_

#include <exception>

class ExceptionSocketNotAvailable : public std::exception
{

public:

	virtual const char* what() const throw()
	{
		return "Could not create socket";
	}
};

#endif /* INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_COULD_NOT_CREATE_SOCKET_HPP_ */
