#include <string>
namespace irc {
  class Client {
    
  private:
    std::string _nickname;
    int _sockfd;
  public:
    Client(std::string nickname);

    void connect_server(const int port, const char* server_ip);
    
  };
}
 

