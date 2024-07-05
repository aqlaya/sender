#pragma once


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

/* 
    IPv4 socket address is stored in sockaddr_in structrue, 
    defined in <netiner/in.h>
*/

struct sockaddr_in; 
// IPv4


class Udp_Socket {


    static const inline unsigned short open_port = 62564;

    private:


        /* keep address and names */
        std::map<std::string, std::string> _name_to_ipv4;

        /* socket descriptor */
        int _fd; 

    public:
        Udp_Socket();

        
        void send(sockaddr_in&, std::string&);

        void add_receiver(std::string&&, std::string&&);

        void recieve_message();

        void allocate_in_node();


        /* rules of create */
        Udp_Socket(Udp_Socket& obj) = delete;
        Udp_Socket& operator=(Udp_Socket& obj) = delete;
};