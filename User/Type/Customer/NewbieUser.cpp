//
// Created by lee on 2024. 10. 21..
//

#include "NewbieUser.h"

void NewbieUser::updateUserInfo() {

}

float NewbieUser::getTotalDiscountRate() const {
    return 10;
}

NewbieUser::NewbieUser(long long int userId, const std::string &userName, const std::string &userPw,
                       const std::string &address, int postCode, int discountCount) : Customer(userId, userName, userPw,
                                                                                               address, postCode),
                                                                                      discountCount(discountCount) {}
