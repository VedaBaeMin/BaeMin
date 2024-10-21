//
// Created by lee on 2024. 10. 17..
//

#include "Food.h"

Food::Food(long foodId, long price, string foodName): foodId(foodId), price(price), foodName(foodName){


}

long Food::getId() {
     return foodId;
}

long Food::getPrice() const {
    return price;
}

const string &Food::getFoodName() const {
    return foodName;
}

void Food::setPrice(long price) {
    Food::price = price;
}

void Food::setFoodName(const string &foodName) {
    Food::foodName = foodName;
}
