/*
 * server_attacker.hpp
 *
 *  Created on: Jul 1, 2018
 *      Author: hugo
 */

#ifndef INC_CONTROLLER_SERVER_ATTACKER_HPP_
#define INC_CONTROLLER_SERVER_ATTACKER_HPP_

namespace Attacker{

	void on_connection_open_callback(struct ConnectionInfo &connection_info);
	void on_connection_received_data_callback(struct DataReceivedArgs &args);
	void on_connection_close_callback(struct ConnectionInfo &connection_info);
}



#endif /* INC_CONTROLLER_SERVER_ATTACKER_HPP_ */
