//
// Created by lee on 2024. 10. 15..
//

#ifndef BAEMIN_USER_H
#define BAEMIN_USER_H

#include <string>
#include <iostream>
class User{

    long userId;
    std::string userName;
    std::string userPw;

public:
    User( long long userId, std::string userName, std::string userPw)
            :userId(userId), userPw(userPw), userName(userName){

        std::cout << "부모 호출" << std::endl;

    }


    virtual bool canRegister(){
        std::cout << "부모 레지스터 호출" << std::endl;
        if( userName.size() >= 10) std::cout<< "유저 검증 오류 "<< std::endl;
        if( userPw.size() >= 20) std::cout << "비밀번호 문제 있음 " << std::endl;
    }

    virtual bool canUpdate( int userId){
        std::cout << "부모 호출" << std::endl;
        return isSame(userId);
    }

    bool isSame( int userId){
       std::cout << "부모 호출" << std::endl;
        return userId == this->userId;
    }
    virtual bool canDelete(int userId){
        return isSame(userId);
    }

};

#endif //BAEMIN_USER_H
