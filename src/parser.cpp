#include "../include/parser.h"
#include "string_view"
namespace irc {
  namespace parser {
    constexpr Command parse_command(std::string_view command) {
      if (command == "NICK") return Command::NICK;
      return Command::UNKNOWN;
    }
    
  } 
}

