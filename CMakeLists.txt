cmake_minimum_required(VERSION 3.19)
project(NimbleGUI)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs/raylib/include)
link_directories(libs/raylib/lib)

file(GLOB resources "resources/*")
file(COPY ${resources} DESTINATION "${CMAKE_BINARY_DIR}/resources")

add_executable(TESTING
        src/main.cpp
        src/elements/BaseElement.cpp src/elements/BaseElement.h
        src/elements/Input.cpp src/elements/Input.h)

target_link_libraries(TESTING raylib)