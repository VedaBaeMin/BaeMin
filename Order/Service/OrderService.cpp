//
// Created by lee on 2024. 10. 17..
//

#include "OrderService.h"
#include <iostream>
void OrderService::createOrder(OrderRequest request) {

    std::cout << "start" << std:: endl;
    const shared_ptr<const Food> &food = foodService.readFood(request.getFoodId());
    const std::shared_ptr<const Customer>& customer = std::dynamic_pointer_cast<const Customer>(userService.getUser(request.getCustomerId()));
    if(customer == nullptr) return;
    long totalPrice = food->getPrice() * request.getOrderCount();
    std::cout << "total price: " << totalPrice << std::endl;
    totalPrice *= (double)((100.0 -food->getFoodDiscountPercent()) / 100.0);
    std::cout << "applied food discount :" << totalPrice << std::endl;
    totalPrice *= (double)((100.0 - customer->getTotalDiscountRate()) / 100.0);
    std::cout << "applied member discount :" << totalPrice << std::endl;
    orderDataBase.save(request.toOrder(totalPrice,orderDataBase.currentIdx()+1));
    std::cout << "userName : "<< std::dynamic_pointer_cast<const User>(customer)->getname() << std::endl;
    std::cout << "foodPrice: " << food->getPrice() << std::endl;
    std::cout << "foodDiscount rate : "<< food->getFoodDiscountPercent() << std::endl;
    std::cout << "orderCount: "<< request.getOrderCount() << std::endl;
    std::cout << "customer discountRate: " << customer->getTotalDiscountRate() << std::endl;
    std::cout << "total : " << totalPrice << std::endl;

    std::cout << "success "<< std::endl;
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

