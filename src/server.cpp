#include "../include/server.h"
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <stdexcept>
#include <iostream>
namespace irc {

  Server::Server(int port) : _port(port) {
    
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (_sockfd < 0) {
      throw std::runtime_error("Couldt create socket for server");
    }
    int opt = 1;
    setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    
    int bind_res = bind(_sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (bind_res < 0) {
      throw std::runtime_error("Failed to bind socket");
      
    }
    if (listen(_sockfd, BACKLOG_SIZE) < 0) throw std::runtime_error("Failed to listen");
  };
  
  void Server::run() {
    for (;;) {
      
      sockaddr_in client_addr{}; 
      socklen_t addrlen = sizeof(client_addr);
      
      int client_fd = accept(_sockfd, (sockaddr*)(&client_addr), &addrlen);
      
      if (client_fd < 0) std::cerr << "Failed to accept client"; continue;
      
      
      
      
      
    }
  }
  
  

}
 


