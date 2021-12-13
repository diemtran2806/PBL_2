#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "function.h"
using namespace std;

class account
{
    string name;
    string password;

public:
    string getName() const;
    string getPassword() const;
    void readAccount(ifstream &);
};

#endif