add_executable(server

	app.cpp
	
	model/server.cpp
	model/connection.cpp
)

# set (LIBS hal core)
# target_link_libraries(server ${LIBS})