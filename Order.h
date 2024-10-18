//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDER_H
#define BAEMIN_ORDER_H

enum OrderStatus{
    PENDING,
    PROCEDDING,
    FINISHED
};


class Order {

    long orderId;
    long sellerId;
    long customerId;
    // string Date;
    OrderStatus status;

    void update();



};


#endif //BAEMIN_ORDER_H
