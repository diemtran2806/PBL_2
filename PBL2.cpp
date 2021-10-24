#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//
class member;
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
      friend ostream &operator <<(ostream &out, member &);
};

//nhan vien
class member {
private:
    string mID;     //mã nhân viên
    string mlname;    //họ và đệm
    string firstname; //
    string gID;     //mã đơn vị
    string pnumber;
    birthday ns;//da_tri
    int gender;
    string position;
    float C_salary; //hệ số lương
    int year_in;
    string degree; //trình độ, cấp bậc
    string L_certificate; // bẳng ngoại ngữ
public:
    //member();
    void readfile_M(ifstream &);
    void display();
    int getSalary(); //tinh luong    
    friend istream &operator >>(istream &in, member &);
    friend ostream &operator <<(ostream &out, member &);
    friend bool operator <(const member &, const member &);
    friend bool operator >(const member &, const member &);

    //friend
};

void member::readfile_M(ifstream &in) {
    string s;  //bỏ qua dòng đầu
    char t;   // đọc kí tự bỏ qua
    getline(in,mID,'|');
    getline(in, mlname, '|' );
    getline(in, firstname, '|');
    getline(in, gID, '|');
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

ostream &operator <<(ostream &out, member &m){
    //du nguyen
    
 out<<setw(10)<<m.mID<<setw(20)<<m.mlname+m.firstname<<setw(20)<<m.pnumber<<m.ns.getDay()<<"/"<<m.ns.getMonth()<<"/"<<m.ns.getYear()
    <<setw(10)<<m.gender<<setw(10)<<m.position<<setw(10)<<m.C_salary<<setw(10)<<m.year_in<<setw(10)<<m.degree<<setw(10)<<m.L_certificate<<endl;
    return out;
}

//don vi
class group { 
private:
    string gID;  //ma don vi
    string gName;
    string mID; //ma nhan vien
public:
    //group();
    void readfile_G(ifstream &);
    void display();
    friend ostream &operator <<(ostream &out, const group&);
};

void group::readfile_G(ifstream &in){
    string s;
    getline(in,s,'\n');
    getline(in,gID,'|');
    getline(in,gName,'|');
    getline(in,mID,'\n');
}

void group::display(){
    cout<<setw(10)<<gID<<setw(20)<<gName<<setw(10)<<mID<<endl;
}

ostream &operator <<(ostream &out, const group &g){
    out<<setw(10)<<g.gID<<setw(20)<<g.gName<<setw(10)<<g.mID<<endl;
    return out;
}

//chuc vu
class Position 
{
private:
    string pID;
    string pName; 
    float pAllowance;
public:
    //Position ();
    void readfile_P(ifstream &);
    void display();
    friend ostream &operator <<(ostream &out, const Position&);
    //~Position ();
};

void Position::readfile_P(ifstream &in){
    string s;
    getline(in,s,'\n');
    getline(in,pID,'|');
    getline(in,pName,'|');
    in >> pAllowance;
    getline(in,s,'\n');
}

void Position::display(){
    cout<<setw(10)<<pID<<setw(20)<<pName<<setw(10)<<pAllowance<<endl;
}

ostream &operator <<(ostream &out, const Position &p){
    out<<setw(10)<<p.pID<<setw(20)<<p.pName<<setw(10)<<p.pAllowance<<endl;
    return out;
}

//danh sach
class list{
private:
    int numofMem;   //sl nv
    int numofGr;    //sl đơn vị
    int numofP;
    member *list_mem;
    group *list_gr;
    Position *list_p;
public:
    list(int = 0, int = 0);
    list(const list&);
    ~list();
    void readfile_mem(ifstream& in);                     //nhap danh sach nhan vien tu file 
    void readfile_gr(FILE *fi);                      //nhap danh sach don vi tu file
    void display_mem();                              //in danh sach nhan vien
    void display_gr();                               //in bang thong ke theo don vi
    void add(member&, int k);                        //bo sung 1 doi tuong vao vi tri k bat ki
    void sort(bool CompFunc(member&, member&));      //sap xep danh sach nhan vien theo thu tu tang/giam
    member search(member&);                          //tim kiem 1 nhan vien
    void delete_mem(member&);                        //xoa 1 nhan vien bat ki
    member &operator [](int i) const;                //toan tu lay phan tu thu i [] trong danh sach nhan vien
};

//Khoi tao
list::list(int NMem, int NGr):numofMem(NMem),numofGr(NGr)
{
    list_mem = new member [numofMem];
}

list::~list(){
    delete [] list_mem; 
}


void list::readfile_mem(ifstream& in){
    in.open("Nhan Vien.txt", ios_base::in);
    string s;
    getline(in,s,'\n');
    int i=0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofMem+1;
        member* newArr = new member[newSize];
        for (int i = 0; i < numofMem; i++)
	        newArr[i] = list_mem[i];
        delete[] list_mem;
        list_mem = newArr;
        numofMem=newSize;
        //doc file
        list_mem[i].readfile_M(in);
        cout<<list_mem[i]<<endl;
        i++;
    }
     
   
    in.close();
} 

int main(){
    /*cout <<left;
    member *x=new member();
    group gr;
    Position p;*/

//doc file
    /*
    ifstream filein_G;
    ifstream filein_P;
    filein_G.open("Don Vi.txt", ios_base::in);
    filein_P.open("Chuc Vu.txt", ios_base::in);
*/
    ifstream filein_M;
    list com;
    com.readfile_mem(filein_M);
/*
    x->readfile_M(filein_M);
    //x->display();
    cout<<*x;
    gr.readfile_G(filein_G);
    //gr.display();
    cout<<gr;
    p.readfile_P(filein_P);
    //p.display();
    cout<<p;

    filein_M.close();
    filein_G.close();
    filein_P.close();
*/
    return 0;
}
