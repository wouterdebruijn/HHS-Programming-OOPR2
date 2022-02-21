#include "RecognitionLock.h"
#include <sstream>

RecognitionLock::RecognitionLock(Printer *printer, QLineEdit* line) : QLineLock(line), printer(printer), locked(true) {}

RecognitionLock::~RecognitionLock() {
    delete printer;
}

void RecognitionLock::unlock(const std::string key) {
    // Search for key
    auto position = folder.find(key);

    // If we didn't find anything
    if (position == folder.end())
        return;

    // Check if the bool returns true.
    if (position->second)
        locked = false;
}

void RecognitionLock::lock() {
    locked = true;
}

bool RecognitionLock::isLocked() {
    return locked;
}

void RecognitionLock::showFolder() {
    std::stringstream outputStream;

    for (auto const& item : folder) {
        outputStream << item.first << ": " << (item.second ? "Authorized" : "Unauthorized") << std::endl;
    }

    printer->showText(outputStream.str());
}

void RecognitionLock::addToFolder(std::string key , bool value) {
    folder[key] = value;
}
