#include "../include/client.h"

int main() {
  irc::Client client_1("Felipe");
  client_1.connect_server(8000, "127.0.0.1");
  return 0;
}
