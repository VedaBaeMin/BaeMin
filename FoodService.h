//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_FOODSERVICE_H
#define BAEMIN_FOODSERVICE_H

#include <vector>

#include "Food.h"

class FoodService {
    vector<Food> foodlist;

    void createFood(long foodID, long orderID);
    Food readFood(long foodId);
    void updateFood(Food food);
    void deleteFood(long foodId);
};


#endif //BAEMIN_FOODSERVICE_H
