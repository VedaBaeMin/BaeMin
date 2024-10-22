//
// Created by lee on 2024. 10. 18..
//

#ifndef BAEMIN_FOODREQUEST_H
#define BAEMIN_FOODREQUEST_H

#include <string>
#include <memory>
#include "../Food.h"
class FoodRequest {
    long price;
    std::string foodName;

public:
    FoodRequest(long price, std::string foodName):price(price), foodName(foodName){};

     shared_ptr<Food> toFood(long foodIdx){
         return make_shared<Food>(foodIdx,price,foodName);
     }

};


#endif //BAEMIN_FOODREQUEST_H
