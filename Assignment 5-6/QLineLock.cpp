#include "QLineLock.h"

QLineLock::QLineLock(QLineEdit* inputField) : inputField(inputField) {}

QLineEdit* QLineLock::getUiInput() {
    return this->inputField;
}
