#include <iostream>
#include <string>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <cstring>
#include <cstdlib>
#include <arpa/inet.h>

int main() {

    // create IPv4 socket
    int _fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (_fd == -1) 
    {
        throw std::logic_error("error function socket") ;
    }

    sockaddr_in send_host;
    std::memset((void*) &send_host, 0, sizeof(sockaddr_in));

    const char* buffer = new char[255];
    buffer = "Sultan:127.0.0.1\nHello World\0";

    send_host.sin_family = AF_INET;
    send_host.sin_port   = htons(62564);

    std::string loopback = "127.0.0.1";

    if (inet_pton(AF_INET, loopback.c_str(), (void*) &send_host.sin_addr ) == -1)
    {
        throw std::logic_error("Error");
    }

    if (sendto(_fd, buffer, 255, 0, (sockaddr*) &send_host, sizeof(send_host) ) != 255 ) 
    {
        throw std::logic_error{"Error sendto"};
    }
    else 
    {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}