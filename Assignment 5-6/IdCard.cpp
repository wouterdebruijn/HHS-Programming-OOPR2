#include "IdCard.h"
#include "LockException.h"

IdCard::IdCard(std::string id, std::string name, std::string address) : id(id), ownerName(name), ownerAddress(address) {}

std::string IdCard::userID() {
    return id;
}

void IdCard::authorize(CardLock *lock) {
    authorizedLocks.push_back(lock);
}

void IdCard::deauthorize(CardLock * lock) {
    for (auto item = authorizedLocks.begin(); item != authorizedLocks.end(); item++) {

        if (*item == lock) {
            authorizedLocks.erase(item);
        }
    }

}

bool IdCard::isAuthorized(CardLock * lock) {
    for (std::vector<CardLock*>::iterator item = authorizedLocks.begin(); item != authorizedLocks.end(); item++) {
        if (*item == lock) {
            return true;
        }
    }

    throw LockException(this, lock);

    return false;
}
