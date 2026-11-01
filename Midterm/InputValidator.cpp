#include <cctype>
#include <iostream>
#include <sstream>
#include "InputValidator.h"

std::string InputValidator::trim(const std::string& value)
{
    std::size_t first = value.find_first_not_of(" \t\r\n");

    if (first == std::string::npos)
    {
        return "";
    }

    std::size_t last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

int InputValidator::getIntInRange(
    const std::string& prompt,
    int minimum,
    int maximum
)
{
    while (true)
    {
        std::cout << prompt;

        std::string line;
        std::getline(std::cin, line);
        line = trim(line);

        std::stringstream parser(line);
        int value;
        char extra;

        if (!(parser >> value) || (parser >> extra))
        {
            std::cout
                << "Invalid input. Please enter a whole number.\n";
            continue;
        }

        if (value < minimum || value > maximum)
        {
            std::cout
                << "Invalid range. Enter a value from "
                << minimum << " to " << maximum << ".\n";
            continue;
        }

        return value;
    }
}

double InputValidator::getDoubleInRange(
    const std::string& prompt,
    double minimum,
    double maximum
)
{
    while (true)
    {
        std::cout << prompt;

        std::string line;
        std::getline(std::cin, line);
        line = trim(line);

        std::stringstream parser(line);
        double value;
        char extra;

        if (!(parser >> value) || (parser >> extra))
        {
            std::cout
                << "Invalid input. Please enter a numeric value.\n";
            continue;
        }

        if (value < minimum || value > maximum)
        {
            std::cout
                << "Invalid range. Enter a value from "
                << minimum << " to " << maximum << ".\n";
            continue;
        }

        return value;
    }
}

std::string InputValidator::getRequiredString(
    const std::string& prompt,
    std::size_t maximumLength
)
{
    while (true)
    {
        std::cout << prompt;

        std::string value;
        std::getline(std::cin, value);
        value = trim(value);

        if (value.empty())
        {
            std::cout
                << "Invalid input. This field is required and cannot be empty.\n";
            continue;
        }

        if (value.length() > maximumLength)
        {
            std::cout
                << "Invalid input. Enter no more than "
                << maximumLength << " characters.\n";
            continue;
        }

        return value;
    }
}

bool InputValidator::isLeapYear(int year)
{
    return
        (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);
}

int InputValidator::daysInMonth(int month, int year)
{
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            return isLeapYear(year) ? 29 : 28;

        default:
            return 0;
    }
}

bool InputValidator::isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[2] != '/' || date[5] != '/')
    {
        return false;
    }

    const int digitPositions[] = {0, 1, 3, 4, 6, 7, 8, 9};

    for (int position : digitPositions)
    {
        if (!std::isdigit(
                static_cast<unsigned char>(date[position])
            ))
        {
            return false;
        }
    }

    int month = std::stoi(date.substr(0, 2));
    int day = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if (year < 2000 || year > 2100)
    {
        return false;
    }

    if (month < 1 || month > 12)
    {
        return false;
    }

    int maxDay = daysInMonth(month, year);
    return day >= 1 && day <= maxDay;
}

std::string InputValidator::getDateMMDDYYYY(const std::string& prompt)
{
    while (true)
    {
        std::cout << prompt;

        std::string date;
        std::getline(std::cin, date);
        date = trim(date);

        if (!isValidDate(date))
        {
            std::cout
                << "Invalid date. Use MM/DD/YYYY and enter a real date "
                << "between 2000 and 2100.\n";
            continue;
        }

        return date;
    }
}
