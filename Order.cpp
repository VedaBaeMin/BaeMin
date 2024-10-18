//
// Created by lee on 2024. 10. 17..
//

#include "Order.h"

Order::Order(long orderId, long sellerId, long customerId, OrderStatus status) {
    this->orderId=orderId;
    this->sellerId=sellerId;
    this->customerId=customerId;
}

long Order::gerOrderId() {
    return this->orderId;
}
