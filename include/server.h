#pragma once
#include <string>
#include <unordered_map>
#include <memory>


namespace irc {
   
  class Client;
  constexpr int BACKLOG_SIZE = 5;
  
  struct Channel {
    std::string name;
    Channel(std::string name) : name(name) {}
  };
  class Server {
  private:
    const int _port;
    int _sockfd{-1};
    std::unordered_map<std::string, std::unique_ptr<Client>> clients;  
  public:
    explicit Server(const int port);
    ~Server();
    void handle_nick_command(std::string_view message);
    void handle_quit_command(int client_fd);
    void run();
  }; 
}

