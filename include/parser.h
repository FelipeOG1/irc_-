#pragma once
#include <string_view>
#include <string>
namespace irc {
  enum class Command {
      NICK,
      QUIT,
      UNKNOWN
    };
  namespace parser {
    Command parse_command(std::string_view str);
    
    
  } 
}

