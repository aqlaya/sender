#pragma once


#include <netinet/in.h>
#include <sys/socket.h>
#include <exception>
#include <fstream>
#include <arpa/inet.h>


#include <condition_variable>
#include <thread>
#include <mutex>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "message.hpp"
#include "threadsafe_queue.hpp"

/* 
    IPv4 socket address is stored in sockaddr_in structrue, 
    defined in <netiner/in.h>
*/

struct sockaddr_in; 
// IPv4


class Udp_Socket {

private:
    static const inline unsigned short open_port = 62564;
    static const inline size_t max_length = 255;

private:

    /* socket descriptor */
    int _fd; 

public:
    Udp_Socket();

    
//    void send(sockaddr_in&, std::string&);

//    void recieve_message(threadsafe_queue<Message>& queue);

//    void recieve_message(char* raw_ptr);

    /* rules of create */
    Udp_Socket(Udp_Socket& obj) = delete;
    Udp_Socket& operator=(Udp_Socket& obj) = delete;
};