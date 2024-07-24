cmake_minimum_required(VERSION 3.14)

project(sender VERSION 1.0.0 LANGUAGES CXX)



#add_compile_options(-Wall)
add_subdirectory(test)

add_subdirectory(src)

target_link_libraries(test_message_1 PRIVATE message)


