#include <iostream>
#include <vector>
#include <string>

#include <sys/socket.h>

#include <netinet/in.h>
/* 
    IPv4 socket address is stored in sockaddr_in structrue, 
    defined in <netiner/in.h>
*/

struct sockaddr_in; 
// IPv4



class udp_socket {
    private:

        /* socket descriptor */
        int fd; 

    public:
        udp_socket();

        
        void send(sockaddr_in&, std::string&);

        void add_reciever(std::string&, sockaddr_in&)


        /* rules of create */
        udp_socket(udp_socket& obj) = delete;
        udp_socket& operator=(udp_socket& obj) = delete;

};