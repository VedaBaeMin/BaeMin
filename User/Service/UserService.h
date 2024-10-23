//
// Created by lee on 2024. 10. 15..
//

#ifndef BAEMIN_USERSERVICE_H
#define BAEMIN_USERSERVICE_H

#include "../Type/User.h"
#include "../Type/Seller/Seller.h"
#include "../../DataBase.h"
class UserService {

    DataBase<User> userDatabase;
    void createUser( User * user);
public:

    void join(std::shared_ptr<User> user){
        userDatabase.save(user);
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
