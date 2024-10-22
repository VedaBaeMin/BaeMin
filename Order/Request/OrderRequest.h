//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERREQUEST_H
#define BAEMIN_ORDERREQUEST_H
#include <vector>
#include "../Order.h"

class OrderRequest {


    long orderCount;
    long foodId;
    long sellerId;
    long customerId;
    // 주문 시 갱신되는 부분
    long total = 0;
    long orderId = -1;


public:
    long getCustomerId() const {
        return customerId;
    }

    long getSellerId() const {
        return sellerId;
    }

    long getFoodId() const {
        return foodId;
    }

    long getOrderCount() const {
        return orderCount;
    }

    std::shared_ptr<Order> toOrder(long total, long orderId ){
        return std::make_shared<Order>(orderId,orderCount,foodId,sellerId,total,customerId);
    }

// 생성자
OrderRequest(long sellerId, long customerId, long foodId, long orderCount):sellerId(sellerId), customerId(customerId), foodId(foodId),orderCount(orderCount){

}
};


#endif //BAEMIN_ORDERREQUEST_H
