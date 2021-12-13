#include "group.h"
using namespace std;

group::group(string gID, string gName, string mID)
    : gID(gID), gName(gName), mID(mID) {}

string group::getGID() const
{
    return gID;
}

void group::readfile_G(ifstream &in)
{
    getline(in, gID, '|');
    del_ws(gID);
    getline(in, gName, '|');
    del_ws(gName);
    getline(in, mID, '\n');
    del_ws(mID);
}

ostream &operator<<(ostream &out, const group &g)
{
    out << setw(10) << g.gID << "|" << setw(19) << g.gName << "|" << setw(9) << g.mID;
    return out;
}
