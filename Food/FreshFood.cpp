//
// Created by lee on 2024. 10. 22..
//

#include "FreshFood.h"

const long FreshFood::getFoodPrice() const {
    return 100;
}

FreshFood::FreshFood(long foodId, long price, const string &foodName) : Food(foodId, price, foodName) {}
