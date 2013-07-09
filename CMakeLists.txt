project(zkdecrypto-lite)

set(CMAKE_BUILD_TYPE "Release")

add_executable(zkdecrypto-lite main.cpp z340.cpp map.cpp message.cpp strarray.cpp files.cpp solve.cpp zodiac.cpp)

