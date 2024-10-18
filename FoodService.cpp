//
// Created by lee on 2024. 10. 17..
//

#include "FoodService.h"

void FoodService::createFood(long foodId, long orderId) {
    Food newfood(foodId,orderId);
    foodlist.push_back(newfood);
}

Food FoodService::readFood(long foodId) {
    for(auto food:foodlist)
        if(food.getFoodId()==foodId)
            return food;
    cout<<"food ����"<<endl;
    //return; ������ ���� �� ��������ߵ�
}

void FoodService::updateFood(Food food) {
    deleteFood(food.getFoodId());
    foodlist.push_back(food);
}

void FoodService::deleteFood(long foodId) {
    auto foodIt=find_if(foodlist.begin(),foodlist.end(),[foodId](Food food){return food.getFoodId()==foodId;});
    foodlist.erase(foodIt);
}

void FoodService::showList() {
    cout<<"list ���� : "<<foodlist.size()<<endl;
}


