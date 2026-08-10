#include "../include/client.h"
#include <arpa/inet.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>
namespace irc {
  Client::Client(std::string nick) : _nickname(nick) {
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
  }
  void Client::connect_server(const int port, const char* server_ip) {
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, server_ip, &addr.sin_addr) <= 0) {
      close(_sockfd);
      throw std::runtime_error("Invalid ip addr");
    }
    if (connect(_sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
      close(_sockfd);
      throw std::runtime_error("Faile to connect");
    }
    
    for (;;) {
      std::string user_input;
      std::getline(std::cin, user_input);
      int res = send(_sockfd, user_input.c_str(), user_input.length(), 0);
           
    }

    
    
  
  }

}
