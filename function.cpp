#include <iostream>
#include "function.h"
using namespace std;

void del_ws(string &s) //Hàm xóa khoảng trắng
{
    while (s[0] == ' ')
    {
        for (int k = 0; k < s.length(); k++)
        {
            s[k] = s[k + 1];
        }
    }
    while (s[s.length() - 1] == ' ')
    {
        s.resize(s.size() - 1);
    }
    for (int i = 0; i < s.length(); i++)
    {
        while (s[i] == ' ' && s[i + 1] == ' ')
        {
            for (int k = i + 1; k < s.length(); k++)
            {
                s[k] = s[k + 1];
            }
        }
    }
}

//hàm sắp xếp
bool ascending(const member &m1, const member &m2, int key)
{
    birthday ns1 = m1.getBirthday();
    birthday ns2 = m2.getBirthday();
    switch (key)
    {
    case 1:
        return m1.getMID().compare(m2.getMID()) > 0 ? true : false;
    case 2:
        //so sánh nếu tên giống nhau thì so sánh họ
        if (m1.getFirstname().compare(m2.getFirstname()) != 0)
            return m1.getFirstname().compare(m2.getFirstname()) > 0 ? true : false;
        else
            return m1.getMlname().compare(m2.getMlname()) > 0 ? true : false;
    case 3:
        return m1.getGID().compare(m2.getGID()) > 0 ? true : false;
    case 4:
        //ss nếu năm bằng nhau thì ss tháng
        if (ns1.getYear() != ns2.getYear())
            return ns1.getYear() > ns2.getYear();
        //nếu tháng bằng nhau thì ss ngày
        else if (ns1.getMonth() != ns2.getMonth())
            return ns1.getMonth() > ns2.getMonth();
        return ns1.getDay() > ns2.getDay();
    case 5:
        return m1.getC_salary() > m2.getC_salary();
    case 6:
        return m1.getYear_in() > m2.getYear_in();
    default:
        return false;
    }
}

bool descending(const member &m1, const member &m2, int key)
{
    birthday ns1 = m1.getBirthday();
    birthday ns2 = m2.getBirthday();
    switch (key)
    {
    case 1:
        return m1.getMID().compare(m2.getMID()) < 0 ? true : false;
    case 2:
        if (m1.getFirstname().compare(m2.getFirstname()) != 0)
            return m1.getFirstname().compare(m2.getFirstname()) < 0 ? true : false;
        else
            return m1.getMlname().compare(m2.getMlname()) < 0 ? true : false;
    case 3:
        return m1.getGID().compare(m2.getGID()) < 0 ? true : false;
    case 4:
        if (ns1.getYear() != ns2.getYear())
            return ns1.getYear() < ns2.getYear();
        else if (ns1.getMonth() != ns2.getMonth())
            return ns1.getMonth() < ns2.getMonth();
        return ns1.getDay() < ns2.getDay();
    case 5:
        return m1.getC_salary() < m2.getC_salary();
    case 6:
        return m1.getYear_in() < m2.getYear_in();
    default:
        return false;
    }
}

bool checkFile(string path)
{
    ifstream isf(path);
    return isf.good();
}

//trả về ngày hiện tại
birthday SystemDate()
{
    birthday dateResult;
    time_t now = time(0);   //hàm trả về thời gian là s
    char *dt = ctime(&now); //chuyển s thành date
    //012345678901234567890123 để tìm vị trí ngày cho dễ
    //Fri Oct 29 21:53:17 2021

    //bắt đầu lấy ngày
    string date(dt); //chuyển char thành string
    char sday[2];    //ngày có hai chữ số và một kí tự kết thúc \0->chuoi
    int length = date.copy(sday, 2, 8);
    sday[length] = '\0';        //thhêm ký tụ kết thúc để chuyển char thành string
    int iday;                   //day kiểu int
    stringstream(sday) >> iday; //chuyển string thành int
    dateResult.setDay(iday);

    // //lấy năm
    string year(dt);
    char syear[4];
    length = year.copy(syear, 4, 20);
    syear[length] = '\0';
    int iyear;
    stringstream(syear) >> iyear;
    dateResult.setYear(iyear);

    //bat dau lay thang
    string month(dt);
    char cmonth[4];
    month.copy(cmonth, 3, 4);
    string smonth(cmonth);
    int imonth = monthStrToInt(smonth);

    dateResult.setMonth(imonth);
    return dateResult;
}

//chuyển tháng chữ sang số
int monthStrToInt(string a)
{
    if (a == "Jan")
        return 1;
    if (a == "Feb")
        return 2;
    if (a == "Mar")
        return 3;
    if (a == "Apr")
        return 4;
    if (a == "May")
        return 5;
    if (a == "Jun")
        return 6;
    if (a == "Jul")
        return 7;
    if (a == "Aug")
        return 8;
    if (a == "Sep")
        return 9;
    if (a == "Oct")
        return 10;
    if (a == "Nov")
        return 11;
    if (a == "Dec")
        return 12;
    else
        return 0;
}

//color
void SET_COLOR(int color)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
//giao dien
void uiDisplay(int n)
{
    system("cls");
    getCol();
    //size 158; 79
    int tempcursor = cursor;
    cursor = 0;
    gotoxy(l_uiDisplay, cursor);
    cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    gotoxy(l_uiDisplay, ++cursor);
    cout << "|                                                                                                                                                            |" << endl;
    gotoxy(l_uiDisplay, ++cursor);
    cout << "|                                                                                                                                                            |" << endl;
    gotoxy(l_uiDisplay, ++cursor);
    cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    gotoxy(l_uiDisplay, ++cursor);
    cout << "|  +------------------------------------------------------------------------------------------------------------------------------------------------------+  |" << endl;
    for (int i = 0; i < n; i++)
    {
        gotoxy(l_uiDisplay, ++cursor);
        cout << "|  |                                                                                                                                                      |  |" << endl;
    }
    gotoxy(l_uiDisplay, ++cursor);
    cout << "|  +------------------------------------------------------------------------------------------------------------------------------------------------------+  |" << endl;
    gotoxy(l_uiDisplay, ++cursor);
    cout << "+------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cursor = tempcursor;
}

void uiFunc(int n)
{
    system("cls");
    getCol();
    //size 104 52
    int tempcursor = cursor;
    cursor = 0;

    gotoxy(l_uiFuns, cursor);
    gotoxy(l_uiFuns, cursor);
    cout << "+------------------------------------------------------------------------------------------------------+" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                                                                                      |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                                                                                      |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "+------------------------------------------------------------------------------------------------------+" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  +------------------------------------------------------------------------------------------------+  |" << endl;
    for (int i = 0; i < n; i++)
    {
        gotoxy(l_uiFuns, ++cursor);
        cout << "|  |                                                                                                |  |" << endl;
    }
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  +------------------------------------------------------------------------------------------------+  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "+------------------------------------------------------------------------------------------------------+" << endl;
    cursor = tempcursor;
}

void uiLogin()
{
    system("cls");
    getCol();
    //size 104 52
    int tempcursor = cursor;
    cursor = 0;
    gotoxy(l_uiFuns, ++cursor);
    cout << "x======================================================================================================x" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                                NHOM 2                                                |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "x======================================================================================================x" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                   De tai 03:  Quan ly nhan vien                                      |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                   Sinh vien:  Le Van Dat                                             |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                               Tran Thi Diem                                          |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                               Nguyen Thi Cam                                         |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|                                   GVHD:       Do Thi Tuyet Hoa                                       |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "x------------------------------------------------------------------------------------------------------x" << endl;
    gotoxy(l_uiFuns, cursor);
    cout << "+------------------------------------------------------------------------------------------------------+" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  +------------------------------------------------------------------------------------------------+  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                           ~LOGIN~                                              |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                      +----------------------------------------------+                          |  |" << endl; //10
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                      |                                              |                          |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                      +----------------------------------------------+                          |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                      +----------------------------------------------+                          |  |" << endl; //15
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                      |                                              |                          |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                      +----------------------------------------------+                          |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  |                                                                                                |  |" << endl; //20
    gotoxy(l_uiFuns, ++cursor);
    cout << "|  +------------------------------------------------------------------------------------------------+  |" << endl;
    gotoxy(l_uiFuns, ++cursor);
    cout << "+------------------------------------------------------------------------------------------------------+" << endl;
    cursor = tempcursor;
}

//set con trỏ trong console
void gotoxy(short x, short y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

void getCol() //lấy hàng cột
{
    ///////////////lấy cột hàng
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    l_uiDisplay = (columns / 2) - uiDisplaySize;
    l_uiFuns = (columns / 2) - uiFunSize;
    /////////////////////////////////////////
}

//hàm login chính
void login()
{
    ifstream filein_A;
    int t;
    d = 0;
    system("cls");
    getCol();
    uiLogin();
    acc.readfile_account(filein_A);
    gotoxy(l_uiFuns + 15, 25);
    cout << "NEU BAN NHAP SAI QUA 3 LAN THI SE BI KHOA TAM THOI! (DUNG CHUONG TRINH)" << endl
         << endl;
    do
    {
        gotoxy(l_uiFuns + 27, 15);
        cout << "Nhap ten tai khoan: ";
        gotoxy(l_uiFuns + 28, 16);
        cout << "                                            "; //clear khung nhập account
        gotoxy(l_uiFuns + 28, 16);
        getline(cin, tk);
        if (acc.check(tk) != 1)
        {
            gotoxy(l_uiFuns + 27, 18);
            SET_COLOR(4);
            cout << "TEN TAI KHOAN KHONG TON TAI, VUI LONG NHAP LAI!" << endl;
            SET_COLOR(0);
        }
        else
        {
            gotoxy(l_uiFuns + 27, 18);
            cout << "                                                 " << endl;
        }
    } while (acc.check(tk) != 1);
    do
    {
        gotoxy(l_uiFuns + 27, 20);
        cout << "Nhap mat khau: ";
        gotoxy(l_uiFuns + 28, 21);
        cout << "                                             "; //clear khung nhập passwỏd
        gotoxy(l_uiFuns + 28, 21);
        string mk = acc.tranpass();
        d++;
        t = acc.check(mk);
        if (t != 1 && d != 3)
        {
            gotoxy(l_uiFuns + 31, 23);
            SET_COLOR(4);
            cout << "MAT KHAU KHONG DUNG, VUI LONG NHAP LAI!" << endl;
            SET_COLOR(0);
        }
        else
        {
            gotoxy(l_uiFuns + 31, 23);
            cout << "                                         " << endl;
        }
    } while (t != 1 && d != 3);
    if (t == 1)
    {
        gotoxy(l_uiFuns + 5, 25);
        cout << "                                                                                 ";
        gotoxy(l_uiFuns + 15, 25);
        SET_COLOR(2);
        cout << "DANH NHAP THANH CONG!, VUI LONG DOI VAI GIAY DE SU DUNG CHUC NANG..." << endl;
        SET_COLOR(0);
        gotoxy(l_uiFuns + 80, 25); //break
        d--;
        Sleep(1500);
    }
    else
    {
        SET_COLOR(4);
        cout << "BAN DA NHAP SAI QUA 3 LAN, VUI LONG THU LAI SAU!!" << endl;
        SET_COLOR(0);
    }
}
