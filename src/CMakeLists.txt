cmake_minimum_required(VERSION 3.16)

project(sender)


#target in test
add_executable(test_udp_socket test.cxx peer_socket.cxx )

