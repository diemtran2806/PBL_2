#include "birthday.h"
using namespace std;

int birthday::getDay() const
{
    return day;
}

void birthday::setDay(int day)
{
    this->day = day;
}

int birthday::getMonth() const
{
    return month;
}

void birthday::setMonth(int month)
{
    this->month = month;
}

int birthday::getYear() const
{
    return year;
}

void birthday::setYear(int year)
{
    this->year = year;
}

ostream &operator<<(ostream &out, const birthday &d)
{
    out << d.day << "   " << d.month << "   " << d.year << endl;
    return out;
}

bool operator<(const birthday &d1, const birthday &d2)
{
    if (d1.year < d2.year)
    {
        return true;
    }

    if (d1.year == d2.year)
    {
        if (d1.month < d2.month)
        {
            return true;
        }
        if (d1.month == d2.month)
        {
            if (d1.day < d2.day)
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool operator!=(const birthday &d1, const birthday &d2)
{
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
    {
        return false;
    }
    return true;
}

const birthday &birthday::operator=(const birthday &x)
{
    if (this != &x)
    {
        day = x.day;
        month = x.month;
        year = x.year;
    }
    return *this;
}

birthday operator-(const birthday &d, int x)
{
    birthday dateResult = d;
    dateResult.year -= x;
    return dateResult;
}

bool operator==(const birthday &d1, const birthday &d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
    {
        return true;
    }
    return false;
}
