//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_FOOD_H
#define BAEMIN_FOOD_H
#include <string>

using namespace std;

class Food {
private:
    long foodId;
    long orderId;
    long foodCount;
    long price;
    string foodName;
public:
    Food(long foodID, long orderID, long foodCount=0, long price=0, string foodName="");
    long getFoodId();
};


#endif //BAEMIN_FOOD_H
