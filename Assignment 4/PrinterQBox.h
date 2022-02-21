#ifndef PRINTERQBOX_H
#define PRINTERQBOX_H

#include "Printer.h"
#include "QTextBrowser"

class PrinterQBox : public Printer {
    public:
        PrinterQBox(QTextBrowser*);
        void showText(std::string);
        void clearMedium();
    private:
        QTextBrowser *browser;
};

#endif // PRINTERQBOX_H
