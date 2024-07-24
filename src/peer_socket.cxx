#include "peer_socket.hpp"

extern threadsafe_queue<Message> qu;



//void Udp_Socket::recieve_message(threadsafe_queue<Message>& queue)
//{
//    
//    for (;;) {
//
//        char* raw_message = new char[max_length];
//
//       
//        if (  recvfrom(_fd, raw_message, max_length, 0, NULL, NULL) != 255) 
//        {
//            throw std::logic_error("Receive error");
//        }
//
//        Message mess(std::string(raw_message, max_length));
//        queue.push(std::move(mess));
//    }
//}


Udp_Socket::Udp_Socket() 
{

    char* raw_message = new char[max_length];
    sockaddr_in my_host;

    in_addr addr_any;
    addr_any.s_addr = INADDR_ANY;

    std::memset( (void*) (&my_host), 0, sizeof(sockaddr_in));
    my_host.sin_family = AF_INET;
    my_host.sin_addr   = addr_any;
    my_host.sin_port   = htons(open_port);

    // create IPv4 socket
    _fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (_fd == -1)
    {
        throw std::logic_error("Socket error function");
    }

    if (  bind(_fd, reinterpret_cast<sockaddr*>(&my_host), sizeof(struct sockaddr_in))  == -1) 
    {
        throw std::logic_error("Not bind to socket");
    } 

//    std::thread reciever_thread(&Udp_Socket::recieve_message, this, std::ref(qu)); 
//    std::thread reciever_thread(&Udp_Socket::recieve_message, this);

//    reciever_thread.detach();
    for (;  ;) {
       
        if (  recvfrom(_fd, raw_message, max_length, 0, NULL, NULL) != 255) 
        {
            throw std::logic_error("Receive error");
        }

        for (int i = 0; raw_message[i] != EOF; ++i)
        {
            std::cout << raw_message[i] << std::endl; 
        }
    }
    
}




