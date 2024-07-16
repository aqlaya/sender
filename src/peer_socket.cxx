#include "peer_socket.hpp"
#include <netinet/in.h>
#include <sys/socket.h>
#include <exception>

#include <arpa/inet.h>

void Udp_Socket::recieve_message() 
{   
    for (size_t i = 0; i < 1000; ++i ) {
        std::cout << i << std::endl;
    }
}

void Udp_Socket::add_receiver(std::string&& name, std::string&& ipv4) 
{
    std::thread new_thread(&Udp_Socket::recieve_message, this);
    for (size_t i = 0; i < 100; ++i)
    {
        std::cout << i << std::endl;
    }
    new_thread.detach();
}

Udp_Socket::Udp_Socket() 
{
    sockaddr_in my_host;

    in_addr addr_any;
    addr_any.s_addr = INADDR_ANY;

    std::memset( (void*) (&my_host), 0, sizeof(sockaddr_in));
    my_host.sin_family = AF_INET;
    my_host.sin_addr   = addr_any;
    my_host.sin_port   = htons(open_port);

    // create IPv4 socket
    _fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (  bind(_fd, reinterpret_cast<sockaddr*>(&my_host), sizeof(struct sockaddr_in6))  == -1) 
    {
        throw std::logic_error("Not bind to socket");
    }   
}

