#pragma once

namespace irc {
  
  class Server {
  private:
    const int _port;
    int _sockfd{-1};
  public:
    explicit Server(const int port);
    void star();
  }; 
}

