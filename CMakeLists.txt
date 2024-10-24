cmake_minimum_required(VERSION 3.28)
project(BaeMin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

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
        Food/Request/FoodRequest.cpp
        Food/Request/FoodRequest.h
        Qt/client.cpp
        Qt/client.h
        Qt/server.cpp
        Qt/server.h
)

# MOC 설정
set_target_properties(BaeMin PROPERTIES
        AUTOMOC ON  # MOC 활성화
)

target_link_libraries(BaeMin
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
)