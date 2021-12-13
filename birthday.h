#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <iostream>
using namespace std;

class birthday
{ 
    int day;
    int month;
    int year;

public:
    birthday(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}
    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    const birthday &operator=(const birthday &x);
    friend bool operator==(const birthday &, const birthday &);
    friend bool operator<(const birthday &d1, const birthday &d2);
    friend bool operator!=(const birthday &d1, const birthday &d2);
    friend birthday operator-(const birthday &, int);
    friend ostream &operator<<(ostream &out, const birthday &);
};

#endif