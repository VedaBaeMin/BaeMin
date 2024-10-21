//
// Created by lee on 2024. 10. 17..
//

#include "OrderService.h"

void OrderService::createOrder(OrderRequest request) {

    const shared_ptr<Food> &food = foodService.readFood(request.getFoodId());
    const shared_ptr<Customer>& customer = dynamic_pointer_cast<Customer>(userService.getUser(request.getCustomerId()));

    //todo : 예외처리 해야함
    if(customer == nullptr) return;

    long totalPrice = food->getFoodPrice() *request.getOrderCount();

    totalPrice *= totalPrice/ 100 *(customer->getTotalDiscountRate());

    orderDataBase.save(request.toOrder(totalPrice,orderDataBase.currentIdx()+1));
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

shared_ptr<Order> OrderService::readOrder(long orderId) {
    std::shared_ptr<Order> order = orderDataBase.find(orderId);
    return order;
}

