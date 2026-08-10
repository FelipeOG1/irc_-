#include "../include/client.h"
#include "iostream"
int main() {
    std::string nickname;
    ui::show_welcome_message();
    std::getline(std::cin, nickname);
    
    while (!irc::is_valid_nickname(nickname)) {
      nickname.clear();
      std::getline(std::cin, nickname);
      std::cout << "Invalid name type again: ";
    }
      
    irc::Client c1(nickname);
    c1.connect_server(8000, "127.0.0.1");
    for (;;) {
      
    }
    
  
  return 0;
}

