#ifndef LOCKEXCEPTION_H
#define LOCKEXCEPTION_H

#include <exception>
#include <string>

#include "IdCard.h"
#include "CardLock.h"

class LockException : public std::exception {
public:
    LockException(IdCard *card, CardLock *lock);
    std::string getIdCardID();
    std::string getLockLocation();
private:
    std::string cardId;
    std::string lockLocation;
};

#endif // LOCKEXCEPTION_H
