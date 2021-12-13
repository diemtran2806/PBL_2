#include <iostream>

#include "list.h"
#include "list_account.h"
#include "account.h"
#include "birthday.h"
#include "member.h"
#include "group.h"
#include "Position.h"
#include "function.h"

#include "list.cpp"
#include "list_account.cpp"
#include "account.cpp"
#include "birthday.cpp"
#include "member.cpp"
#include "group.cpp"
#include "Position.cpp"
#include "function.cpp"
using namespace std;

// BOOL WINAPI FillConsoleOutputAttribute(
//   __in   HANDLE hConsoleOutput,
//   __in   WORD wAttribute,
//   __in   DWORD nLength,
//   __in   COORD dwWriteCoord,
//   __out  LPDWORD lpNumberOfAttrsWritten
// );
int main()
{
    system("color F0");
    SetConsoleTitle(TEXT("Chuong trinh quan ly nhan vien")); //console title
    cout << left;
    getCol(); //lấy chiều rộng
    login();
    ShowWindowAsync(GetConsoleWindow(), SW_MAXIMIZE); //set console full size
    if (d != 3)
    {
        ifstream filein_M;
        com.readfile_mem(filein_M);
        ifstream filein_G;
        com.readfile_gr(filein_G);
        ifstream filein_p;
        com.readfile_p(filein_p);
        dateNow = SystemDate(); //lấy time hiện tại
        getCol();               //lấy chiều rộng
        com.menu();
    }
    return 0;
}