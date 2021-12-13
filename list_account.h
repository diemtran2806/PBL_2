#ifndef LIST_ACCOUNT_H
#define LIST_ACCOUNT_H

#include <iostream>
#include <conio.h>
#include "account.h"
using namespace std;

class list_account
{
    int numOfAcount;
    account *la;

public:
    list_account(int = 0);
    void readfile_account(ifstream &in);
    int check(string s);
    string tranpass();
    ~list_account();
};

#endif