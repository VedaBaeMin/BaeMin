//
// Created by change10 on 24. 10. 24.
//
#include "FoodRequest.h"
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

FoodRequest::FoodRequest(QByteArray byte){
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byte);
    QJsonObject jsonObj = jsonDoc.object();
    this->price=jsonObj["price"].toInt();
    this->foodName=jsonObj["foodName"].toString().toStdString();
    this->type=stringToFoodType(jsonObj["type"].toString().toStdString());
}