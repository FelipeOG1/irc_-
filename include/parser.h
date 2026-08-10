#pragma once
#include <string_view>
#include <string>
namespace irc {
  
  namespace parser {
    enum class Command {
      NICK,
      USER,
      UNKNOWN
    };
    constexpr Command get_command(std::string_view str);
    std::string parse_nickname(const std::string& nick);
    
    
  } 
}

