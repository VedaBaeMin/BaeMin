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

        std::cout << "�θ� ȣ��" << std::endl;

    }


    virtual bool canRegister(){
        std::cout << "�θ� �������� ȣ��" << std::endl;
        if( userName.size() >= 10) std::cout<< "���� ���� ���� "<< std::endl;
        if( userPw.size() >= 20) std::cout << "��й�ȣ ���� ���� " << std::endl;
    }

    virtual bool canUpdate( int userId){
        std::cout << "�θ� ȣ��" << std::endl;
        return isSame(userId);
    }

    bool isSame( int userId){
       std::cout << "�θ� ȣ��" << std::endl;
        return userId == this->userId;
    }
    virtual bool canDelete(int userId){
        return isSame(userId);
    }

};

#endif //BAEMIN_USER_H
