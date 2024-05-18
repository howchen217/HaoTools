#include <iostream>
#include <ctime>
#include <string>


bool isLeapYear(int year){
    if(year % 4 != 0) return false;
    if(year % 100 == 0 && year % 400 != 0) return false; 
    return true;
};

std::string printIFCDate(int dayOfYear, int year){
    int month;
    int day;

    if(isLeapYear(year)){

        int leapYear_DayOfYear = dayOfYear;
        int leapDay = 6 * 28 + 1;

        if(dayOfYear == leapDay){
            month = 6;
            day = 29;
            return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " Leap day!";
        }
        if(dayOfYear > leapDay){
            leapYear_DayOfYear = dayOfYear - 1;
        }

        month = (leapYear_DayOfYear - 1) / 28 + 1;
        day = (leapYear_DayOfYear - 1) % 28 + 1;

        if(dayOfYear == 366){
            month = 13;
            day = 29;
            return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " Year day!";
        }

    } else {
        month = (dayOfYear - 1) / 28 + 1;
        day = (dayOfYear - 1) % 28 + 1;

        if(dayOfYear == 365){
            month = 13;
            day = 29;
            return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " Year day!";
        }
    }
    return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
};



int main(){
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);
    
    int year = localTime->tm_year + 1900;
    int dayOfYear = localTime->tm_yday + 1;

    bool leapYear = isLeapYear(year);
    if(leapYear) std::cout << "Leap year!" << std::endl;

    std::cout << "Today's Gregorian date: "
              << (year) << "-"
              << (localTime->tm_mon + 1) << "-"
              << localTime->tm_mday << std::endl;

    // printIFCDate(6 * 28 + 1, 2000);
    // printIFCDate(366, year);
     std::cout << "Today's International Fixed Calendar date: " << printIFCDate(dayOfYear, year) << std::endl;

    std::cin.get();
    return 0;
};
