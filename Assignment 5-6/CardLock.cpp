#include "CardLock.h"
#include "LockException.h"

std::map<std::string, IdCard*> CardLock::idCards = {};

CardLock::CardLock(std::string location, QLineEdit* line) : QLineLock(line), location(location), locked(true) {}

void CardLock::unlock(std::string key) {
    auto it = idCards.find(key);

    if (it->second == nullptr){
        throw LockException(nullptr, this);
    }

    if (it->second->isAuthorized(this)) {
        this->locked = false;
    }
}

void CardLock::lock() {
    locked = true;
}


bool CardLock::isLocked() {
    return locked;
}

void CardLock::addIdCard(IdCard* card) {
    idCards[card->userID()] = card;
}

void CardLock::removeIdCard(std::string key) {
    // No idea if this works either

    auto card = idCards.find(key);
    idCards.erase(card);

    // We have 1000000 memory leaks, but this makes one less.
    delete card->second;
}

std::string CardLock::getLocation() {
    return location;
}
