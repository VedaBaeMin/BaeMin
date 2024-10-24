//
// Created by lee on 2024. 10. 17..
//

#include "OrderService.h"

void OrderService::createOrder(OrderRequest request) {

    const shared_ptr<const Food> &food = foodService.readFood(request.getFoodId());
    const std::shared_ptr<const Customer>& customer = std::dynamic_pointer_cast<const Customer>(userService.getUser(request.getCustomerId()));
    if(customer == nullptr) return;
    long totalPrice = food->getFoodPrice() *request.getOrderCount();
    totalPrice *= (double)((100.0 - customer->getTotalDiscountRate()) / 100.0);
    orderDataBase.save(request.toOrder(totalPrice,orderDataBase.currentIdx()+1));

    std::cout << "success " << std::endl;
    return;

}


void OrderService::deleteOrder(long orderId) {
    orderDataBase.remove(orderId);
    return;
}

void OrderService::updateOrderStatus(long orderId,OrderStatus status) {
    const shared_ptr<Order> &order = orderDataBase.find(orderId);
    order->updateOrderStatus(status);
    orderDataBase.update(order);
}

const shared_ptr<const Order> OrderService::readOrder(long orderId) {
    std::shared_ptr<Order> order = orderDataBase.find(orderId);
    return order;
}

