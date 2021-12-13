#include "Position.h"
using namespace std;

Position::Position(string pID, string pName, float pAllowance)
    : pID(pID), pName(pName), pAllowance(pAllowance) {}

void Position::readfile_P(ifstream &in)
{
    string s;
    getline(in, pID, '|');
    del_ws(pID);
    getline(in, pName, '|');
    del_ws(pName);
    in >> pAllowance;
    getline(in, s, '\n');
}

ostream &operator<<(ostream &out, const Position &p)
{
    out << setw(10) << p.pID << "|" << setw(19) << p.pName << "|" << setw(9) << p.pAllowance;
    return out;
}
