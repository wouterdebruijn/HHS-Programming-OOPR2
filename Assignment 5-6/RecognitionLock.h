#ifndef RECOGNITIONLOCK_H
#define RECOGNITIONLOCK_H

#include "QLineLock.h"
#include <map>
#include "Printer.h"

class RecognitionLock : public QLineLock
{
public:
    RecognitionLock(Printer*, QLineEdit*);
    ~RecognitionLock();
    void unlock(const std::string key);
    void lock();
    bool isLocked();
    void showFolder();
    void addToFolder(std::string, bool);
private:
    std::map<std::string, bool> folder;
    bool locked;
    Printer* printer;
};

#endif // RECOGNITIONLOCK_H
