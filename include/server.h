#pragma once

namespace irc {
  constexpr int BACKLOG_SIZE = 5;
  
  class Server {
  private:
    const int _port;
    int _sockfd{-1};
    
  public:
    explicit Server(const int port);
    void handle_nick_command();
      
    
    void run();
  }; 
}

