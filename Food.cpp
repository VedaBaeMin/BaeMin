//
// Created by lee on 2024. 10. 17..
//

#include "Food.h"

Food::Food(long foodID, long orderID, long foodCount, long price, string foodName) {
    this->foodId=foodID;
    this->orderId=orderID;
    this->foodCount=foodCount;
    this->price=price;
    this->foodName=foodName;
};
long Food::getFoodId() {
    return this->foodId;
}
