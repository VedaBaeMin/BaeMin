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
    long getId(){
        return userId;
    }
    void changeName(std::string name){
        this->userName = name;
    }
    std::string getname(){
    }
    User( long long userId, std::string userName, std::string userPw)
            :userId(userId), userPw(userPw), userName(userName){
    }

    virtual ~User() {
    }


};

#endif //BAEMIN_USER_H
