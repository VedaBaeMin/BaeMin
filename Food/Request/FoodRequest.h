//
// Created by lee on 2024. 10. 18..
//

#ifndef BAEMIN_FOODREQUEST_H
#define BAEMIN_FOODREQUEST_H

#include <string>
#include <memory>
#include "../Food.h"
#include "../FreshFood.h"
#include "../FrozenFood.h"
enum FoodType{
    FRESH,
    FROZEN
};

class FoodRequest {
    long price;
    std::string foodName;
    FoodType type;

public:
    FoodRequest(long price, std::string foodName,FoodType type):price(price), foodName(foodName),type(type){};

     shared_ptr<Food> toFood(long foodIdx){
         if(type == FRESH){
             return make_shared<FreshFood>(foodIdx,price,foodName);
         }
         else if(type == FROZEN){
             return make_shared<FrozenFood>(foodIdx,price,foodName);
         }

     }

};


#endif //BAEMIN_FOODREQUEST_H
