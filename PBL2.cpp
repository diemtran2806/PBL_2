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

class person{
protected:
    string codeM;     //mã nhân viên
    string mlname;    //họ và đệm
    string firstname; //
    string codeG;     //mã đơn vị
public:
    person();
    virtual void readfile(ifstream &);
    virtual void display();
};

class member :public person{
private:
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
    int tinhLuong(); //tinh luong    
    friend istream &operator >>(istream &in,member &);
    friend ostream &operator <<(ostream &out,const member &);
    friend bool operator <(const member &, const member &);
    friend bool operator >(const member &, const member &);
};

class group :public person{ //đơn vị
private:
    string nameG;
    int numofM;   //số lượng nam
    int numofFM;  //số lượng nữ
public:
    group();
    void readfile(ifstream &);
    void display();
};

class list{
private:
    int numofMem;   //sl nv
    int numofGr;    //sl đơn vị
    member *list_mem;
    group *list_gr;
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
