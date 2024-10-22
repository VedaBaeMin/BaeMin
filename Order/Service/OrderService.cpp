//
// Created by lee on 2024. 10. 17..
//

#include "OrderService.h"

void OrderService::createOrder(OrderRequest request) {

    const shared_ptr<const Food> &food = foodService.readFood(request.getFoodId());
    // getUser에서 반환된 shared_ptr을 Customer로 변환
    const std::shared_ptr<const Customer>& customer = std::dynamic_pointer_cast<const Customer>(userService.getUser(request.getCustomerId()));
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

const shared_ptr<Order> OrderService::readOrder(long orderId) {
    std::shared_ptr<Order> order = orderDataBase.find(orderId);
    return order;
}

