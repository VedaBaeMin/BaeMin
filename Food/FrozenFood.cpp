//
// Created by lee on 2024. 10. 22..
//

#include "FrozenFood.h"

const long FrozenFood::getFoodPrice() const {
    return 30;
}

FrozenFood::FrozenFood(long foodId, long price, const string &foodName) : Food(foodId, price, foodName) {}
