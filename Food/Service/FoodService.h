//
// Created by lee on 2024. 10. 17..
//

#ifndef BAEMIN_FOODSERVICE_H
#define BAEMIN_FOODSERVICE_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "../Food.h"
#include "../../DataBase.h"
#include "../Request/FoodRequest.h"

class FoodService {
    DataBase<Food> foodDataBase;

public:
    void showList();
    void createFood(FoodRequest request);
    shared_ptr<Food> readFood(long foodId);
    void updateFood(shared_ptr<Food> food);
    void deleteFood(long foodId);
};


#endif //BAEMIN_FOODSERVICE_H
