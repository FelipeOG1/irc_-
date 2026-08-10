#pragma once
#include <string_view>
namespace irc {
  
  namespace parser {
    enum class Command {
      NICK,
      USER,
      UNKNOWN
    };
    constexpr Command parse_command(std::string_view str);
  } 
}

