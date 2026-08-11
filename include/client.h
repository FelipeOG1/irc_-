#include <string>
namespace irc {
  bool is_valid_nickname(std::string);
  class Client {
    
  private:   
    int _sockfd;
    std::string _nickname;
    
    
  public:
    Client(std::string nickname);   
    void connect_server(const int port, const char* server_ip);
    
    void disconnect_server();
    void send_nickname();
    
  };

 }
 

namespace ui {
    void show_welcome_message();
  }


