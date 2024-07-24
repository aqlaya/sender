#include <iostream>
#include <memory>
#include "message.hpp"
#include "threadsafe_queue.hpp"
#include <arpa/inet.h>

#include "peer_socket.hpp"


int main() {

    int max_length = 255;
    unsigned short open_port = 62564;

    char* raw_message = new char[max_length];
    sockaddr_in my_host, sender_host;
    socklen_t len;

    in_addr addr_any;
    addr_any.s_addr = INADDR_ANY;

    std::memset( (void*) (&my_host), 0, sizeof(sockaddr_in));
    my_host.sin_family = AF_INET;
    my_host.sin_addr   = addr_any;
    my_host.sin_port   = htons(open_port);

    // create IPv4 socket
    int _fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (_fd == -1) 
    {
        throw std::logic_error("error function socket") ;
    }
 

    if (  bind(_fd, reinterpret_cast<sockaddr*>(&my_host), sizeof(my_host))  == -1) 
    {
        throw std::logic_error("Not bind to socket");
    } 

//    std::thread reciever_thread(&Udp_Socket::recieve_message, this, std::ref(qu)); 
//    std::thread reciever_thread(&Udp_Socket::recieve_message, this);

//    reciever_thread.detach();

    for (;;) {
       
        if (int byte =  recvfrom(_fd, raw_message, max_length, 0, (sockaddr*) &sender_host, &len);
                                                                                             byte <= 0) 
        {
            std::cout << byte << std::endl;
            throw std::logic_error("Recieve error");
        }
        else {
            std::cout << byte;
        }

        std::cout << "Yes" << std::endl;
    }
    
    return 0;
}


