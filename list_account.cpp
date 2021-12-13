#include "account.h"
using namespace std;

//phần đọc file vào list_account
list_account::list_account(int numA) : numOfAcount(numA)
{
    la = new account[numOfAcount];
}

list_account::~list_account()
{
    delete[] la;
}

int list_account::check(string s)
{ //check tk mk có tồn tại hay khum
    int temp = 0;
    for (int i = 0; i < numOfAcount; i++)
    {
        if (s.compare(la[i].getName()) == 0)
        {
            temp = 1;
            break;
        }
    }
    for (int i = 0; i < numOfAcount; i++)
    {
        if (s.compare(la[i].getPassword()) == 0)
        {
            temp = 1;
            break;
        }
    }
    if (temp == 1)
        return 1;
    else
        return 0;
}

void list_account::readfile_account(ifstream &in)
{
    in.open("Tai Khoan.txt", ios_base::in);
    int i = 0;
    while (!in.eof())
    {
        int newSize = numOfAcount + 1;
        account *newArr = new account[newSize];
        for (int j = 0; j < numOfAcount; j++)
            newArr[j] = la[j];
        delete[] la;
        numOfAcount = newSize;
        la = newArr;
        la[i].readAccount(in);
        i++;
    }
    in.close();
}
//hàm chuyển chữ nhập vào thành dấu *
string list_account::tranpass()
{
    string pw;
    for (char c; (c = getch());)
    {
        if (c == '\n' || c == '\r')
        { //phím enter
            cout << "\n";
            break;
        }
        else if (c == '\b')
        {                    //phím xóa
            cout << "\b \b"; //\b là lùi con nháy về trái 1 ký tự, dấu cách để “xóa” ký tự đó rồi \b nữa để lùi lại vị trí sau khi xóa.
            if (!pw.empty())
                pw.erase(pw.size() - 1);
        }
        else if (c == -32)
        {             //phím mũi tên
            _getch(); //bỏ qua k hiển thị gì khi nhập vào phím mũi tên
        }
        else if (isprint(c))
        { //isprint tức là chỉ nhận những ký tự in ra được
            cout << '*';
            pw += c;
        }
    }
    return pw;
}
