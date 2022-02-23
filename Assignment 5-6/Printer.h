#ifndef PRINTER_H
#define PRINTER_H

#include <string>

class Printer {
    public:
        virtual void showText(std::string) = 0;
        virtual void clearMedium() = 0;
};

#endif // PRINTER_H
