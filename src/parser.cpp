#include "../include/parser.h"
#include "string_view"
namespace irc {
  namespace parser {
    Command parse_command(std::string_view message) {
      //extract the firt word before space char and return Command.
      std::string_view command = message.substr(0, message.find(' '));
      
      if (command == "NICK") return Command::NICK;
      if (command == "QUIT") return Command::QUIT;
      
      return Command::UNKNOWN;
    }
      
  } 
}

