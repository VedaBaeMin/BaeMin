//
// Created by lee on 2024. 10. 17..
//

#include "Order.h"

long Order::gerOrderId() {
    return this->orderId;
}

Order::Order(long orderId, long orderCount, long foodId, long sellerId, long total, long customerId)
: orderId(orderId),orderCount(orderCount),foodId(foodId),sellerId(sellerId),total(total),customerId(customerId) {}

long Order::getOrderId() const {
    return orderId;
}

long Order::getOrderCount() const {
    return orderCount;
}

long Order::getTotal() const {
    return total;
}
