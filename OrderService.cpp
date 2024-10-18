//
// Created by lee on 2024. 10. 17..
//

#include "OrderService.h"

void OrderService::createOrder(OrderRequest request) {
    Order neworder(request.orderId, request.customerId, request.sellerId);
    orderlist.push_back(neworder);
}

Order OrderService::readOrder(long orderId) {
    for(auto order:orderlist)
        if(order.gerOrderId()==orderId)
            return order;
}

void OrderService::deleteOrder(long orderId) {
    for(auto orderIt=orderlist.begin();orderIt!=orderlist.end();orderIt++)
        if(orderIt->gerOrderId()==orderId)
            orderlist.erase(orderIt);
}

void OrderService::updateOrder(Order order) {
    deleteOrder(order.gerOrderId());
    orderlist.push_back(order);
}

