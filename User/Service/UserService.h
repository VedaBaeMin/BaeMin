//
// Created by lee on 2024. 10. 15..
//

#ifndef BAEMIN_USERSERVICE_H
#define BAEMIN_USERSERVICE_H

#include "../User.h"
#include "../Seller.h"
class UserService {

public:
    void createUser( User * user){

        if(user-> canRegister()){
            std::cout << " 회원가입 가능 " << std::endl;
        }
        else{
            std::cout << "회원가입 불가" << std::endl;
        }
    }

    User getUser( long userId){};

    void updateUser( User user){};

    void deleteUser( long userId){};
};


#endif //BAEMIN_USERSERVICE_H
