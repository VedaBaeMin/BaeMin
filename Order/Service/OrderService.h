//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERSERVICE_H
#define BAEMIN_ORDERSERVICE_H

#include "../Order.h"
#include "../../DataBase.h"
#include "../Request/OrderRequest.h"
#include "../../Food/Service/FoodService.h"
#include "../../User/Service/UserService.h"
#include <vector>
#include <algorithm>

using namespace std;

class OrderService {
    DataBase<Order> orderDataBase;
    FoodService &foodService;
    UserService &userService;
     void createOrder(OrderRequest request);
     shared_ptr<Order> readOrder(long orderId);
     void updateOrderStatus(long OrderId,OrderStatus status);
     void deleteOrder(long orderId);


     OrderService(FoodService & foodService, UserService & userService):foodService(foodService),userService(userService){

     }

};


#endif //BAEMIN_ORDERSERVICE_H
