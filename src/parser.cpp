#include "../include/parser.h"
#include "string_view"
#include "string"
namespace irc {
  namespace parser {
    constexpr Command parse_command(std::string_view command) {
      if (command == "NICK") return Command::NICK;
      return Command::UNKNOWN;
    }
    std::string parse_nickname(const std::string& nick) {
      //returns a parse_nickname
      return "NICK " + nick;
    }
  } 
}

