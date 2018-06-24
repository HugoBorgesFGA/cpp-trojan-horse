#ifndef INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_CANNOT_ACCEPT_CONNECTIONS_HPP_
#define INC_MODEL_SOCKET_EXCEPTIONS_EXCEPTION_CANNOT_ACCEPT_CONNECTIONS_HPP_

#include <exception>

class ExceptionCannotAcceptConnections : public std::exception
{

public:

	const char* what() const throw()
	{
		return "Could not listen to socket";
	}
};

#endif
