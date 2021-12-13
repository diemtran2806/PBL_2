#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "birthday.h"
#include "function.h"
#include "list.h"
using namespace std;
#define A 1500000 //LCB

class member
{
protected:
    string mID;       //mã nhân viên
    string mlname;    //họ và đệm
    string firstname; //tên
    string gID;       //mã đơn vị
    string pnumber;
    birthday ns;
    int gender;
    string position; //mã chức vụ
    float C_salary;  //hệ số lương
    int year_in;
    string degree;        //trình độ, cấp bậc
    string L_certificate; // bằng ngoại ngữ
public:
    member();
    member(string, string, string, string, string, birthday, int, string, float, int, string, string);
    //hàm getter
    string getMID() const;
    string getGID() const;
    int getGender() const;
    birthday getBirthday() const;
    string getFullName() const;
    string getMlname() const;
    string getFirstname() const;
    float getC_salary() const;
    int getYear_in() const;

    void setmID();
    void setmlname();
    void setfirstname();
    void setgID();
    void setpnumber();
    void setns();
    void setgender();
    void setposition();
    void setC_salary();
    void setyear_in();
    void setdegree();
    void setL_certificate();

    void readfile_M(ifstream &);
    int getSalary();    //tinh luong
    int getNewsalary(); //thực lĩnh
    bool isEqual(int, string);
    bool isEqual_name(string);

    void display();
    friend istream &operator>>(istream &in, member &);
    friend ostream &operator<<(ostream &out, member &);
    friend bool operator<(const member &, const member &);
    friend bool operator>(const member &, const member &);
};

#endif