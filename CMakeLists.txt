cmake_minimum_required(VERSION 3.28)
project(BaeMin)

set(CMAKE_CXX_STANDARD 17)
set(Qt6_DIR "C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(BaeMin main.cpp
        #User/Service/UserService.h
        #User/Service/UserService.cpp
        User/Type/User.h
        User/Type/Seller/Seller.h
        #Order/Service/OrderService.h
        #Order/Service/OrderService.cpp
        Food/Food.h
        Food/Food.cpp
        Order/Order.h
        Order/Order.cpp
        #DataBase.h
        #Food/Service/FoodService.cpp
        #Order/Request/OrderRequest.cpp
)

target_link_libraries(BaeMin Qt6::Widgets)