//
// Created by lee on 2024. 10. 17..
//

#include "FoodService.h"

void FoodService::createFood(long foodID, long orderID) {
    Food newfood(foodID,orderID);
    foodlist.push_back(newfood);
}

Food FoodService::readFood(long foodId) {
    for(auto food:foodlist)
        if(food.getFoodId()==foodId)
            return food;
}

void FoodService::updateFood(Food food) {
    deleteFood(food.getFoodId());
    foodlist.push_back(food);
}

void FoodService::deleteFood(long foodId) {
    for(auto foodIt=foodlist.begin();foodIt!=foodlist.end();foodIt++)
        if(foodIt->getFoodId()==foodId)
            foodlist.erase(foodIt);
}

