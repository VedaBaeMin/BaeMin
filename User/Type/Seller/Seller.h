//
// Created by lee on 2024. 10. 15..
//

#ifndef BAEMIN_SELLER_H
#define BAEMIN_SELLER_H
#include "../User.h"
#include "../Customer/Customer.h"
class Seller : public User{

    std::string sellingaddress;
    int sellingpostcode;
public:
    Seller(long long int userId, const std::string &userName, const std::string &userPw,
           const std::string &sellingaddress, int sellingpostcode) : User(userId, userName, userPw),
                                                                     sellingaddress(sellingaddress),
                                                                     sellingpostcode(sellingpostcode) {}


    void addUser( Customer * user){


}

    ~Seller() override {};
};


#endif //BAEMIN_SELLER_H
