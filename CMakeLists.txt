cmake_minimum_required(VERSION 3.23)

project(irc_impl)

set (CMAKE_CXX_STANDARD 20)

add_compile_options(-g -O0)

add_executable(server)

target_sources(server
  PRIVATE
  src/main_server.cpp
  src/server.cpp
  src/parser.cpp
)
target_include_directories(server
  PRIVATE
    include
)

add_executable(client)

target_sources(client
  PRIVATE
  src/main_client.cpp
  src/client.cpp
  src/parser.cpp
)

target_include_directories(client
  PRIVATE
    include
)


