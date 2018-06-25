add_executable(server

	app.cpp
	
	model/socket/connection.cpp
	model/socket/server.cpp
	model/loggers/console-logger.cpp

)

set (LIBS pthread)
target_link_libraries(server ${LIBS})