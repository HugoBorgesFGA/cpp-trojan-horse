#ifndef INC_MODEL_CONNECTION_HPP_
#define INC_MODEL_CONNECTION_HPP_

#include <pthread.h>
#include <cstdint>

#include "config.hpp"

class Connection
{

private:
	uint8_t bytes[CONFIG_CONNECTION_BUFFER_SIZE];


public:


};

#endif /* INC_MODEL_CONNECTION_HPP_ */
