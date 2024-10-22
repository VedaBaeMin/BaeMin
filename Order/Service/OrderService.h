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
private:
    DataBase<Order> orderDataBase;
    FoodService &foodService;
    UserService &userService;
public:
     OrderService(FoodService & foodService, UserService & userService):foodService(foodService),userService(userService){

     }
    const shared_ptr<Order> readOrder(long orderId);
    void updateOrderStatus(long OrderId,OrderStatus status);
    void deleteOrder(long orderId);
    void createOrder(OrderRequest request);
};


#endif //BAEMIN_ORDERSERVICE_H
