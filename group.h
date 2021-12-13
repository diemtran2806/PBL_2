#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <iomanip>
#include "function.h"
using namespace std;

class group
{
private:
    string gID; //ma don vi
    string gName;
    string mID; //ma nhan vien
public:
    group(string = "", string = "", string = "");
    string getGID() const;
    void readfile_G(ifstream &);
    friend ostream &operator<<(ostream &, const group &);
};

#endif