//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERSERVICE_H
#define BAEMIN_ORDERSERVICE_H

#include "../Order.h"
#include "../../DataBase.h"
#include "../Request/OrderRequest.h"
#include <vector>
#include <algorithm>

using namespace std;

class OrderService {
    DataBase<Order> orderDataBase;
     void createOrder(OrderRequest request);
     shared_ptr<Order> readOrder(long orderId);
     void updateOrder(shared_ptr<Order> order);
     void deleteOrder(long orderId);



};


#endif //BAEMIN_ORDERSERVICE_H
