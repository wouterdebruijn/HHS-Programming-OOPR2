#include "PrinterQBox.h"

PrinterQBox::PrinterQBox(QTextBrowser *bowser) : browser(bowser) {}

void PrinterQBox::showText(std::string text) {
    browser->setText(QString::fromStdString(text));
}

void PrinterQBox::clearMedium() {
    browser->clear();
}
