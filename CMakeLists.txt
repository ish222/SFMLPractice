cmake_minimum_required(VERSION 3.17)
project(SFMLProject)

set(SFML_DIR "C:/Program Files/mingw-w64/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/lib/cmake/SFML/")

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(SFMLProject main.cpp Animation.cpp Animation.h Player.cpp Player.h)
target_link_libraries(SFMLProject sfml-system sfml-window sfml-graphics)