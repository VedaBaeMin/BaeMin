//
// Created by lee on 2024. 10. 23..
//

#ifndef BAEMIN_USERREGISTERREQUEST_H
#define BAEMIN_USERREGISTERREQUEST_H

#include <string>

class UserRegisterRequest {

    std::string userName;
public:
    const std::string &getUserName() const {
        return userName;
    }

    const std::string &getUserPw() const {
        return userPw;
    }

private:
    std::string userPw;
};


#endif //BAEMIN_USERREGISTERREQUEST_H
