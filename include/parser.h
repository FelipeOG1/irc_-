#pragma once
#include <string_view>
#include <string>
namespace irc {
  enum class Command {
      NICK,
      UNKNOWN
    };
  namespace parser {
    Command parse_command(std::string_view str);
    std::string parse_nickname(const std::string& nick);
    
    
  } 
}

