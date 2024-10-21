//
// Created by lee on 2024. 10. 17..
//

#include "FoodService.h"

void FoodService::createFood(FoodRequest request) {

    const long foodIndex = foodDataBase.currentIdx()+1;
    foodDataBase.save(request.toFood(foodIndex));

}

shared_ptr<Food> FoodService::readFood(long foodId) {
    return foodDataBase.find(foodId);
}

void FoodService::updateFood(shared_ptr<Food> food) {
    foodDataBase.update(food);
}

void FoodService::deleteFood(long foodId) {
    foodDataBase.remove(foodId);
}
