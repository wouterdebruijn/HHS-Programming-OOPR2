#include "LockException.h"

LockException::LockException(IdCard *card, CardLock *lock) {
    cardId = card != nullptr ? card->userID() : "noCard";
    lockLocation = lock != nullptr ? lock->getLocation() : "noLock";
}

std::string LockException::getIdCardID() {
    return cardId;
}

std::string LockException::getLockLocation() {
    return lockLocation;
}
