#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class birthday{                //class ngày tháng năm sinh ddeeer sau này lấy cho dễ
    int day;
    int month;
    int year;
    public:
      int getDay(){
          return day;
      }
      void setDay(int day){
          this->day = day;
      }
      int getMonth(){
          return month;
      }
      void setMonth(int month){
          this->month = month;
      }
      int getYear(){
          return year;
      }
      void setYear(int year){
          this->year = year;
      }
};

class person {                      // class chung
    protected:
       string code;
       string fmname;    // họ và đệm
       string lastname;
       string pnumber;   //sđt
       birthday ns;
       string gender;  //giới tính
    public:
       virtual void readfile(ifstream &in){
           char t;   // đọc kí tự bỏ qua
           getline(in,code,'|');
           getline (in, fmname, '|' );
           getline (in, lastname, '|');
           getline (in, pnumber, '|');
           int day;
           in >> day;
           ns.setDay(day);
           in >>t;  // đọc |, bỏ qua nó
           int month;
           in >> month;
           ns.setMonth(month);
           in >>t;
           int year;
           in >> year;
           ns.setYear(year);
           in >>t;
           getline (in,gender,'|');
       }
       virtual void xuat(){
          cout <<"\nMa nhan vien: "<<code<<endl;
          cout <<"Ten nhan vien: "<<fmname+lastname<<endl;
          cout <<"So dien thoai :"<<pnumber<<endl;
          cout <<"Ngay thang nam sinh: "<<ns.getDay()<<"/"<<ns.getMonth()<<"/"<<ns.getYear()<<endl;
          cout <<"Gioi tinh: " <<gender<<endl;
      }



};

// dưới ni là phần riêng, chưa làm :), nghiên cứu bỏ mấy cái class bên cam dô

int main(){
    person *ds[100];
    ifstream filein;
    filein.open("D:\\code\\PBL_2\\Nv.txt", ios_base::in);
    person *x= new person();
    x->readfile(filein);
    x->xuat();

    filein.close();
    return 0;
}