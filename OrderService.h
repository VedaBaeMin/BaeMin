//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERSERVICE_H
#define BAEMIN_ORDERSERVICE_H

#include "Order.h"
#include "OrderRequest.h"
class OrderService {

     void createOrder(OrderRequest request);
     Order readOrder();
     void updateOrder(Order order);
     void deleteOrder(long orderId);



};


#endif //BAEMIN_ORDERSERVICE_H
