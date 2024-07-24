add_executable(test main.cxx)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_compile_options("-std=c++17")

add_library(message STATIC message.cxx)
add_library(peer_socket STATIC peer_socket.cxx)


target_link_libraries(test PRIVATE message PRIVATE peer_socket)



