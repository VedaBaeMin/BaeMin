//
// Created by lee on 2024. 10. 18..
//

#ifndef BAEMIN_FOODREQUEST_H
#define BAEMIN_FOODREQUEST_H

#include <string>
#include <memory>
#include <QJsonDocument>
#include <QJsonObject>
#include "../Food.h"
#include "../FreshFood.h"
#include "../FrozenFood.h"
using namespace std;
enum FoodType{
    FRESH,
    FROZEN,
    UNKNOWN
};
FoodType stringToFoodType(const string& type) {
    static const std::unordered_map<std::string, FoodType> FoodTypeMap = {
        {"FRESH", FRESH},
        {"FROZEN", FROZEN}
    };

    auto it = FoodTypeMap.find(type);
    if (it != FoodTypeMap.end()) {
        return it->second;
    } else {
        return UNKNOWN; // 찾을 수 없는 경우
    }
}

class FoodRequest {
    long price;
    std::string foodName;
    FoodType type;

public:
    FoodRequest(long price, std::string foodName,FoodType type):price(price), foodName(foodName),type(type){};
    FoodRequest(QByteArray byte){
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byte);
    QJsonObject jsonObj = jsonDoc.object();
    this->price=jsonObj["price"].toInt();
    this->foodName=jsonObj["foofName"].toString().toStdString();
    this->type=stringToFoodType(jsonObj["foofName"].toString().toStdString());
    }

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
