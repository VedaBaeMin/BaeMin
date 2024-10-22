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
    long price;
    string foodName;
public:
    long getPrice() const;
    const string &getFoodName() const;
    void setPrice(long price);
    void setFoodName(const string &foodName);
    long getId();
    Food(long foodId, long price, string foodName);
    long getFoodId();
    virtual const long getFoodPrice() const = 0;

};


#endif //BAEMIN_FOOD_H
