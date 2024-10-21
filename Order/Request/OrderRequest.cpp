//
// Created by lee on 2024. 10. 17..
//

#include "OrderRequest.h"

std::shared_ptr<Order> OrderRequest::toOrder(long orderId) {
    return std::make_shared<Order>(orderId,sellerId,customerId,PENDING);
}

std::vector<std::shared_ptr<FoodWithOrder>> OrderRequest::toFoodWithOrder(long foodWithOrderIndex, long orderIdx) {
    std::vector<std::shared_ptr<FoodWithOrder>> foodWithOrderVector;
    for(auto i : foodList){
        foodWithOrderVector.push_back(std::make_shared<FoodWithOrder>(foodWithOrderIndex,i.foodId,orderIdx,i.foodCount));
    }
    return foodWithOrderVector;
}
