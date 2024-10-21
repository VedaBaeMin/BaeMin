//
// Created by lee on 2024. 10. 17..
//

#include "OrderService.h"

void OrderService::createOrder(OrderRequest request) {

    const long orderDatbaseIndex = orderDataBase.currentIdx() + 1;
    const shared_ptr<Order> &order = request.toOrder(orderDatbaseIndex);
    orderDataBase.save(order);

    return;

}


void OrderService::deleteOrder(long orderId) {
    orderDataBase.remove(orderId);
    return;
}

void OrderService::updateOrder(shared_ptr<Order> order) {
    orderDataBase.update(order);
}

shared_ptr<Order> OrderService::readOrder(long orderId) {
    std::shared_ptr<Order> order = orderDataBase.find(orderId);
    return order;
}

