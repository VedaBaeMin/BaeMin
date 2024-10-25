//
// Created by lee on 2024. 10. 15..
//

#ifndef BAEMIN_USERSERVICE_H
#define BAEMIN_USERSERVICE_H

#include "../Type/User.h"
#include "../Type/Seller/Seller.h"
#include "../../DataBase.h"
#include "../Request/UserRegisterRequest.h"
#include "../Request/UserLoginRequest.h"
#include "../Type/Customer/NewbieUser.h"
#include <iostream>
class UserService {

    DataBase<User> userDatabase;
    void createUser( User * user);
public:

    void join(const UserRegisterRequest  request){
        std::shared_ptr<User> userptr = std::make_shared<NewbieUser>(userDatabase.currentIdx()+1,request.getUserName(),request.getUserPw(),"temp",10120,20);
        userDatabase.save(userptr);
        std::cout << "join success" << std::endl;
    }

    void login(){};

    const std::shared_ptr<const User> getUser( long userId){
        return userDatabase.find(userId);
    };

    const std::shared_ptr<const Customer> getCustomer(long customerId){};

    void updateUser( std::shared_ptr<User> user){

    };

    void deleteUser( long userId){

    };
};


#endif //BAEMIN_USERSERVICE_H
