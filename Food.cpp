//
// Created by lee on 2024. 10. 17..
//

#include "Food.h"

Food::Food(long foodID, long orderID, long foodCount=0, long price=0) {
    this->foodId=foodID;
    this->orderId=orderID;
    this->foodCount=foodCount;
    this->price=price;
};
long Food::getFoodId() {
    return this->foodId;
}
