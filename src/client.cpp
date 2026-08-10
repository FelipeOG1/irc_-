#include "../include/client.h"
#include "../include/parser.h"
#include <arpa/inet.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>
namespace irc {
  
  bool is_valid_nickname(std::string nick) { return nick.length() <= 9;}

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
  }
  void Client::disconnect_server() { close(_sockfd); }
    
  
  void Client::send_nickname() {
    std::string message = parser::parse_nickname(_nickname);
    send(_sockfd, message.data(), message.length(), 0); 
  }
}

namespace ui {
    void show_welcome_message() {
      std::cout << "WELCOME TO IRC SERVER" << std::endl;
      std::cout << "TYPE YOUR NICKNAME" << std::endl;
    }
    
  }

