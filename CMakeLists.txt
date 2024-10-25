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
        UiTools
        REQUIRED)

add_executable(BaeMin main.cpp
        DataBase.h
        Food/Food.cpp
        Food/Food.h
        Food/FreshFood.cpp
        Food/FrozenFood.cpp
        Food/Request/FoodRequest.cpp
        Food/Request/FoodRequest.h
        Food/Service/FoodService.cpp
        Order/Order.h
        Order/Order.cpp
        Order/Request/OrderRequest.cpp
        Order/Service/OrderService.cpp
        Order/Service/OrderService.h
        Qt/client.cpp
        Qt/client.h
        Qt/server.cpp
        Qt/server.h
        User/Service/UserService.cpp
        User/Service/UserService.h
        User/Type/Customer/NewbieUser.cpp
        User/Type/Customer/NewbieUser.h
        User/Type/Customer/NormalUser.cpp
        User/Type/Customer/NormalUser.h
        User/Type/Seller/Seller.h
        User/Type/User.h
        Qt/loginwindow.cpp
        Qt/loginwindow.h
        Qt/loginwindow.ui
        Qt/mainwindow.cpp
        Qt/mainwindow.h
        Qt/mainwindow.ui
        Qt/sellerwindow.cpp
        Qt/sellerwindow.h
        Qt/sellerwindow.ui
)

# MOC 설정
set_target_properties(BaeMin PROPERTIES
        AUTOMOC ON  # MOC 활성화
        AUTOUIC ON  # MOC 활성화
)

target_link_libraries(BaeMin
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        Qt::UiTools
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
