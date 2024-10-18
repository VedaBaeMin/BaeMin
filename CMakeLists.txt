cmake_minimum_required(VERSION 3.28)
project(BaeMin)

set(CMAKE_CXX_STANDARD 17)

add_executable(BaeMin main.cpp
        UserService.h
        UserService.cpp
        User.h
        Seller.h
        OrderService.h
        OrderService.cpp
        Food.h
        Food.cpp
        Order.h
        Order.cpp
        DataBase.h
)
