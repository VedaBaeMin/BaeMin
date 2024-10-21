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
    long orderCount;
    long foodId;
    long total;
    long sellerId;
    long customerId;
    // string Date;
    OrderStatus status = PENDING;
public:


    Order(long orderId, long orderCount, long foodId, long sellerId, long total, long customerId);

    long getId(){ return orderId; }
    void setOrderId(long orderId){};
    long calculateOrder();
    long gerOrderId();
    void updateOrderStatus(OrderStatus status){
        this->status = status;
    }
};


#endif //BAEMIN_ORDER_H
