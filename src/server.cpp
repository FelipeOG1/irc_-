#include "../include/server.h"
#include "../include/client.h"
#include "../include/parser.h"
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <stdexcept>
#include <iostream>
namespace irc {
  //TODO 
  Server::~Server() = default;
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

  void Server::handle_nick_command(std::string_view message) {
  
  }
  void Server::handle_quit_command(int client_fd) {
    close(client_fd);
    std::cout << "client disconnected" << std::endl;
  }
  
  
  void Server::run() {
    for (;;) {
      
      sockaddr_in client_addr{}; 
      socklen_t addrlen = sizeof(client_addr);
      int client_fd = accept(_sockfd, (sockaddr*)(&client_addr), &addrlen);
      
      if (client_fd < 0) {
        std::cerr << "Failed to accept client\n";
        continue;  
      }
      char ip_str[INET_ADDRSTRLEN];
      inet_ntop(AF_INET, &(client_addr.sin_addr), ip_str, addrlen);
      
      std::cout << "client connected with ip: " << ip_str << "and socket: " << client_fd << std::endl;
      
      std::string client_message;
      client_message.resize(1024);
      for (;;) {
        ssize_t bytes_read = recv(
            client_fd, 
            client_message.data(), 
            client_message.size(),
            0);
        
      
        std::string_view view_message(client_message);
        std::cout << "receive " << view_message << std::endl;
        
        Command command = parser::parse_command(view_message);
        switch(command) {
          case Command::NICK:
            handle_nick_command(view_message);
          case Command::QUIT:
            handle_quit_command(client_fd);
          case Command::UNKNOWN:
            std::cout << "NOOO UNKOOOWN";
          
        }
        break;
        
      }   

      close(client_fd);
  
    }
  }

}
 
