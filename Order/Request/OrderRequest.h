//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_ORDERREQUEST_H
#define BAEMIN_ORDERREQUEST_H
#include <vector>
#include "../Order.h"
#include "../../FoodWithOrder/FoodWithOrder.h"
struct foodWithCount{
    long foodId;
    long foodCount;
    foodWithCount(long id, long count) : foodId(id), foodCount(count) {}
};
class OrderRequest {

    long sellerId;
    long customerId;
    std::vector<foodWithCount> foodList;

    // 생성자
    OrderRequest(long sellerId, long customerId):sellerId(sellerId), customerId(customerId){

    }
    // 음식 추가 메서드
    void addFood(long foodId, long foodcount) {
        foodList.emplace_back(foodId, foodcount);
    }

public:
    std::shared_ptr<Order> toOrder(long orderId);
    std::vector<std::shared_ptr<FoodWithOrder>> toFoodWithOrder(long foodWithOrderIndex, long orderIdx);
};


#endif //BAEMIN_ORDERREQUEST_H
