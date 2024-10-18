//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDER_H
#define BAEMIN_ORDER_H

enum OrderStatus{
    PENDING,
    PROCEEDING,
    FINISHED
};


class Order {

    long orderId;
    long sellerId;
    long customerId;
    // string Date;
    OrderStatus status;
public:
    Order(long orderId, long sellerId, long customerId, OrderStatus status=PENDING);
    long gerOrderId();
};


#endif //BAEMIN_ORDER_H
