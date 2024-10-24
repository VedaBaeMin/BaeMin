cmake_minimum_required(VERSION 3.28)
project(BaeMin)

set(CMAKE_CXX_STANDARD 17)

add_executable(BaeMin main.cpp
        User/Service/UserService.h
        User/Service/UserService.cpp
        User/Type/User.h
        User/Type/Seller/Seller.h
        Order/Service/OrderService.h
        Order/Service/OrderService.cpp
        Food/Food.h
        Food/Food.cpp
        Order/Order.h
        Order/Order.cpp
        DataBase.h
        Food/Service/FoodService.cpp
        Order/Request/OrderRequest.cpp
        User/Type/Customer/NewbieUser.h
        User/Type/Customer/NewbieUser.cpp
        User/Type/Customer/NormalUser.h
        User/Type/Customer/NormalUser.cpp
        Food/FreshFood.cpp
        Food/FrozenFood.cpp
)
