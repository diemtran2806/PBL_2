#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <iomanip>
#include "function.h"
using namespace std;

class Position
{
private:
    string pID;
    string pName;
    float pAllowance;

public:
    Position(string = "", string = "", float = 0);
    void readfile_P(ifstream &);
    friend ostream &operator<<(ostream &out, const Position &);
};

#endif