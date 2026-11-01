#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <cstddef>
#include <string>

class InputValidator
{
public:
    static int getIntInRange(
        const std::string& prompt,
        int minimum,
        int maximum
    );

    static double getDoubleInRange(
        const std::string& prompt,
        double minimum,
        double maximum
    );

    static std::string getRequiredString(
        const std::string& prompt,
        std::size_t maximumLength
    );

    static std::string getDateMMDDYYYY(
        const std::string& prompt
    );

    static bool isValidDate(
        const std::string& date
    );

private:
    static std::string trim(
        const std::string& value
    );

    static bool isLeapYear(int year);
    static int daysInMonth(int month, int year);
};

#endif
