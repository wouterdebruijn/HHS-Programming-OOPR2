#ifndef IDCARD_H
#define IDCARD_H

#include <string>
#include <vector>

class CardLock;

class IdCard {
public:
    IdCard(std::string, std::string, std::string);
    std::string userID();
    void authorize(CardLock*);
    void deauthorize(CardLock*);
    bool isAuthorized(CardLock*);
private:
    std::string id;
    std::vector<CardLock*> authorizedLocks;
    std::string ownerName;
    std::string ownerAddress;

};

#endif // IDCARD_H
