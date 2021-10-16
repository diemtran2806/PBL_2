#include <iostream>
using namespace std;

class birthday{                //class ngày tháng năm sinh để sau này lấy cho dễ
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

class member {
private:
    string mID;     //mã nhân viên
    string mlname;    //họ và đệm
    string firstname; //
    string gID;     //mã đơn vị
    string pnumber;
    birthday ns;
    int gender;
    string position;
    float C_salary; //hệ số lương
    int year_in;
    string degree; //trình độ, cấp bậc
    string L_certificate; // bẳng ngoại ngữ
public:
    member();
    void readfile(ifstream &);
    void display();
    int getSalary(); //tinh luong    
    friend istream &operator >>(istream &in,member &);
    friend ostream &operator <<(ostream &out,const member &);
    friend bool operator <(const member &, const member &);
    friend bool operator >(const member &, const member &);
};

class group { //đơn vị
private:
    string gID;
    string gName;
    string mID;
public:
    group();
    void readfile(ifstream &);
    void display();
};

class Position 
{
private:
    int pID;
    string pName; 
    int pAllowance;
public:
    Position ();
    void readfile(ifstream &);
    void display();
    ~Position ();
};

class list{
private:
    int numofMem;   //sl nv
    int numofGr;    //sl đơn vị
    int numofP;
    member *list_mem;
    group *list_gr;
    Position *list_p;
public:
    list(int, int);
    list(const list&);
    void readfile_mem(FILE *fi);                     //nhap danh sach nhan vien tu file 
    void readfile_gr(FILE *fi);                      //nhap danh sach don vi tu file
    void display_mem();                              //in danh sach nhan vien
    void display_gr();                               //in bang thong ke theo don vi
    void add(member&, int k);                        //bo sung 1 doi tuong vao vi tri k bat ki
    void sort(bool CompFunc(member&, member&));      //sap xep danh sach nhan vien theo thu tu tang/giam
    member search(member&);                          //tim kiem 1 nhan vien
    void delete_mem(member&);                        //xoa 1 nhan vien bat ki
    member &operator [](int i) const;                //toan tu lay phan tu thu i [] trong danh sach nhan vien
};


int main(){
    
    return 0;
}
