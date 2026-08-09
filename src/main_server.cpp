#include "../include/server.h"
#include <iostream>
int main() {
  irc::Server new_server(8000);
  new_server.run();
}
   
