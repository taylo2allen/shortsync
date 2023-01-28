cmake_minimum_required(VERSION 3.1)
project(ShortSync)

add_subdirectory(third-party/yaml-cpp)

add_executable(
  shortsync
  shortsync.cpp
  )

target_link_libraries(
  shortsync
  PRIVATE
  yaml-cpp
  )
