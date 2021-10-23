#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
    //member();
    void readfile(ifstream &);
    void display();
    int getSalary(); //tinh luong    
    friend istream &operator >>(istream &in,member &);
    friend ostream &operator <<(ostream &out,const member &);
    friend bool operator <(const member &, const member &);
    friend bool operator >(const member &, const member &);
};

void member::readfile(ifstream &in) {
    string s;  //bỏ qua dòng đầu
    char t;   // đọc kí tự bỏ qua
    getline(in,s,'\n');
    getline(in,mID,'|');
    getline (in, mlname, '|' );
    getline (in, firstname, '|');
    getline (in, gID, '|');
    getline(in,pnumber,'|');
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
    in >> gender;
    getline(in,s,'|');
    getline(in,position,'|');
    in >> C_salary;
    getline(in,s,'|');
    in >> year_in;
    getline(in,s,'|');
    getline(in,degree,'|');
    getline(in, L_certificate,'\n');
}
void member::display(){
    cout<<setw(10)<<mID<<setw(20)<<mlname+firstname<<setw(20)<<pnumber<<ns.getDay()<<"/"<<ns.getMonth()<<"/"<<ns.getYear()
    <<setw(10)<<gender<<setw(10)<<position<<setw(10)<<C_salary<<setw(10)<<year_in<<setw(10)<<degree<<setw(10)<<L_certificate<<endl;
}
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
    cout <<left;
    member *ds;
    ifstream filein;
    filein.open("F:\\PBL2_Real\\Nhan Vien.txt", ios_base::in);
    member *x= new member();
    x->readfile(filein);
    x->display();

    filein.close();
    return 0;
}
