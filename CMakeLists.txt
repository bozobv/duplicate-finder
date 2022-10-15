cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 body/main.cpp body/Segment.cpp heather/Segment.h body/Street.cpp heather/Street.h body/Network.cpp heather/Network.h)
