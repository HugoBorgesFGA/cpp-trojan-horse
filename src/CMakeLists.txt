add_executable(server

	app.cpp
	
	model/connection.cpp
	model/socket/server.cpp
	model/loggers/console-logger.cpp

)

# set (LIBS hal core)
# target_link_libraries(server ${LIBS})