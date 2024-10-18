//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERSERVICE_H
#define BAEMIN_ORDERSERVICE_H

#include "Order.h"
#include "OrderRequest.h"
#include <vector>
#include <algorithm>
using namespace std;

class OrderService {
     vector<Order> orderlist;

     void createOrder(OrderRequest request);
     Order readOrder(long orderId);
     void updateOrder(Order order);
     void deleteOrder(long orderId);



};


#endif //BAEMIN_ORDERSERVICE_H
