#ifndef CARDLOCK_H
#define CARDLOCK_H

#include "QLineLock.h"
#include "IdCard.h"
#include <map>

class CardLock : public QLineLock {
public:
    CardLock(std::string, QLineEdit*);
    void unlock(const std::string key);
    void lock();
    bool isLocked();
    void addIdCard(IdCard*);
    void removeIdCard(std::string);
    std::string getLocation();
private:
    std::string location;
    bool locked;
    static std::map<std::string, IdCard*> idCards;
};

#endif // CARDLOCK_H
