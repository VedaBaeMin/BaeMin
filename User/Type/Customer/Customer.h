//
// Created by lee on 2024. 10. 15..
//

#ifndef BAEMIN_CUSTOMER_H
#define BAEMIN_CUSTOMER_H

#include "../User.h"
#include <string>
class Customer : public User{

    std::string address;
    int postCode;

    void updateAddress(std::string address){
         this->address = address;
    }

    void updatePostCode(int postCode){
        this-> postCode = postCode;
    };

    virtual float getTotalDiscountRate() = 0;





public:
    Customer(long long userId, const std::string& userName, const std::string& userPw, const std::string& address, int postCode)
            : User(userId, userName, userPw),  // User의 생성자 호출
              address(address), postCode(postCode)
              {}
    bool canRegister() override{
        User::canRegister();
        return true;
    };
};

#endif //BAEMIN_CUSTOMER_H
