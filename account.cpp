#include "account.h"
using namespace std;

string account::getName() const
{
    return name;
}

string account::getPassword() const
{
    return password;
}

void account::readAccount(ifstream &in)
{
    getline(in, name, '|');
    del_ws(name);
    getline(in, password, '\n');
    del_ws(password);
}