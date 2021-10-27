#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#define A 1500000; //LCB

//
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

//nhan vien
//class Position;
class member {
protected:
    string mID;       //mã nhân viên
    string mlname;    //họ và đệm
    string firstname; //tên
    string gID;       //mã đơn vị
    string pnumber;
    birthday ns;      //da_tri
    int gender;
    string position;  //mã chức vụ
    float C_salary;   //hệ số lương
    int year_in;
    string degree;    //trình độ, cấp bậc
    string L_certificate; // bằng ngoại ngữ
public:
    string getGID(){
		return gID;
	}
	int getGender(){
		return gender;
	}
    member();
    member(string , string , string , string , string , birthday , int , string , float , int , string , string );
    void readfile_M(ifstream &);
    int getSalary(); //tinh luong    
    int getNewsalary();//thực lĩnh
    friend istream &operator >>(istream &in, member &);
    friend ostream &operator <<(ostream &out, member &);
    friend bool operator <(const member &, const member &);
    friend bool operator >(const member &, const member &);
   // friend class Position;
};

//don vi
class group { 
private:
    string gID;  //ma don vi
    string gName;
    string mID; //ma nhan vien
public:
    string getGID(){
		return gID;
	}
    group(string ="", string ="", string ="");
    void readfile_G(ifstream &);
    friend ostream &operator <<(ostream &out, const group&);
};

//chuc vu
class Position 
{
private:
    string pID;
    string pName; 
    float pAllowance;
public:
    Position(string ="", string ="", float =0);
    void readfile_P(ifstream &);
    friend ostream &operator <<(ostream &out, const Position&);
};

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
    list(int = 0, int = 0, int = 0);
    list(const list&);
    ~list();
    void readfile_mem(ifstream& in);                 //nhap danh sach nhan vien tu file 
    void readfile_gr(ifstream& in);                  //nhap danh sach don vi tu file
    void readfile_p(ifstream& in);                   //Nhap danh sach chuc vu
    void display_mem();                              //in danh sach nhan vien
    void display_gr();                               //in bang thong ke theo don vi
    void display_p();                                //in bang thong ke cac chuc vu
    void add(member&, int k);                        //bo sung 1 doi tuong vao vi tri k bat ki
    void sort(bool CompFunc(member&, member&));      //sap xep danh sach nhan vien theo thu tu tang/giam
    member search(member&);                          //tim kiem 1 nhan vien
    void delete_mem(member&);                        //xoa 1 nhan vien bat ki
    member &operator [](int i) const;                //toan tu lay phan tu thu i [] trong danh sach nhan vien
    const list &operator =(const list &);
    friend ostream &operator <<(ostream &out,const list&);
};


                                                                //main
int main(){
    cout <<left;
    list com;
    ifstream filein_M;
    com.readfile_mem(filein_M);
    ifstream filein_G;
    com.readfile_gr(filein_G);
    ifstream filein_p;
    com.readfile_p(filein_p);
    
    com.display_mem();
    com.display_gr();
    com.display_p();
    cout<<"test github";
    //member m;
    //cin>>m;
    //cout<<m;
    //cout<<"Thuc linh: "<<(size_t)m.getNewsalary()<<endl; // không có size t là ra số e
    return 0;
}


                                                                //member
member::member(){
    mID = "";
    mlname = "";
    firstname = "";
    gID = "";
    pnumber = "";
    ns.setDay(0);
    ns.setMonth(0);
    ns.setYear(0);
    gender = 0;
    position = "";
    C_salary = 0;
    year_in = 0;
    degree = "";
    L_certificate = "";
}

member::member(string mID, string mlname, string firstname, string gID, string pnumber, birthday ns, int gender, string pos, float C_salary, int year_in, string degree, string L_cer)
    :mID(mID),mlname(mlname),firstname(firstname),gID(gID),pnumber(pnumber),ns(ns),gender(gender),position(pos),
    C_salary(C_salary),year_in(year_in),degree(degree),L_certificate(L_cer){}

void member::readfile_M(ifstream &in) {
    string s;  //bỏ qua dòng đầu
    char t;    // đọc kí tự bỏ qua
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

ostream &operator <<(ostream &out, member &m){
    //du nguyen    
    out<<setw(10)<<m.mID<<setw(25)<<m.mlname+m.firstname<<setw(10)<<m.gID<<setw(15)<<m.pnumber<<right<<setfill('0')<<setw(2)<<m.ns.getDay()
        <<"/"<<setw(2)<<m.ns.getMonth()<<"/"<<setfill(' ')<<left<<setw(7)<<m.ns.getYear()<<setw(11)<<m.gender<<setw(9)<<m.position
        <<setw(13)<<m.C_salary<<setw(9)<<m.year_in<<setw(10)<<m.degree<<setw(12)<<m.L_certificate;
    return out;
}

istream &operator >>(istream &in, member &m){
    int temp;
    int gt=0;
    string s;
    cout<<"Nhap ma nhan vien: ";
    in >> m.mID;
    cout<<"Nhap ho va ten dem: ";
    getline(in>>ws,m.mlname);
    m.mlname+=" ";
    cout<<"Nhap ten: ";
    getline(in>>ws,m.firstname);
    cout<<"Nhap ma don vi: ";
    in >> m.gID;
    cout<<"Nhap so dien thoai: ";
    in >> m.pnumber;
    cout<<"Nhap ngay/thang/nam sinh: "<<endl;
    cout<<"Nhap ngay sinh: ";
    in >> temp;
    m.ns.setDay(temp);
    cout<<"Nhap thang sinh: ";
    in >> temp;
    m.ns.setMonth(temp);
    cout<<"Nhap nam sinh: ";
    in >> temp;
    m.ns.setYear(temp);
    while(gt==0){
        gt=1; //điều kiện dừng
        cout<<"Nhap gioi tinh (nam/nu): ";
        in >> s;
        if(s=="nam") m.gender = 0;
        else if (s=="nu") m.gender = 1;
        else {
            cout<<"Ban da nhap sai!"<<endl;
            gt=0;
        }
    }
    cout<<"Nhap ma chuc vu: ";
    in >> m.position;
    cout<<"Nhap he so luong: ";
    in >> m.C_salary;
    cout<<"Nhap nam vao lam viec: ";
    in >> m.year_in;
    cout<<"Nhap trinh do cua nhan vien: ";
    getline(in>>ws,m.degree);
    cout<<"Nhap trinh do ngoai ngu cua nhan vien: ";
    getline(in>>ws,m.L_certificate);
    return in;
}

int member::getSalary(){
    return (1500000/100)*(int(C_salary*100));
}

int member::getNewsalary(){
    if (position.compare("GD       ")==0||position.compare("PGD      ")==0){
        return (getSalary()/10*15);
    } else if (position.compare("TP       ")==0||position.compare("PP       ")==0) {
        return (getSalary()/100*125);
    } else return getSalary();
}

                                                                //group
group::group(string gID, string gName, string mID)
    :gID(gID),gName(gName),mID(mID){}

void group::readfile_G(ifstream &in){
    getline(in,gID,'|');
    getline(in,gName,'|');
    getline(in,mID,'\n');
}

ostream &operator <<(ostream &out, const group &g){
    out<<setw(10)<<g.gID<<setw(20)<<g.gName<<setw(10)<<g.mID;
    return out;
}

                                                                //position
Position::Position(string pID, string pName, float pAllowance)
    :pID(pID),pName(pName),pAllowance(pAllowance){}

void Position::readfile_P(ifstream &in){
    string s;
    getline(in,pID,'|');
    getline(in,pName,'|');
    in >> pAllowance;
    getline(in,s,'\n');
}

ostream &operator <<(ostream &out, const Position &p){
    out<<setw(10)<<p.pID<<setw(20)<<p.pName<<setw(10)<<p.pAllowance;
    return out;
}

                                                                //list
//Khoi tao
list::list(int NMem, int NGr, int NP)
:numofMem(NMem),numofGr(NGr),numofP(NP)
{
    list_mem = new member [numofMem];
    list_gr = new group [numofGr];
    list_p = new Position [numofP];

}

list::list(const list &l){
    this->numofMem = l.numofMem;
    this->numofGr = l.numofGr;
    this->numofP = l.numofP;

    this->list_mem = new member [numofMem];
    this->list_gr = new group [numofGr];
    this->list_p = new Position [numofP];

    for(int i=0; i<numofMem; i++){
        this->list_mem[i] = l.list_mem[i];
    }
    for(int i=0; i<numofGr; i++){
        this->list_gr[i] = l.list_gr[i];
    }
    for(int i=0; i<numofP; i++){
        this->list_p[i] = l.list_p[i];
    }
}

list::~list(){
    delete [] list_mem; 
    delete [] list_gr;
    delete [] list_p;
}

//doc file nhan vien 
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
        for (int j = 0; j < numofMem; j++)
	        newArr[j] = list_mem[j];
        delete[] list_mem;
        numofMem=newSize;
        list_mem = newArr;
        //doc file
        list_mem[i].readfile_M(in);
        i++;
    } 
    in.close();
} 
//doc file don vi : ô kê nuôn 
void list::readfile_gr(ifstream& in){
    in.open("Don Vi.txt", ios_base::in);
    string s;
    getline(in,s,'\n');//bỏ dòng đầu
    int i=0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofGr+1;
        group* newArr = new group[newSize];
        for (int j = 0; j < numofGr; j++)
	        newArr[j] = list_gr[j];
        delete[] list_gr;
        list_gr = newArr;
        numofGr=newSize;
        //doc file
        list_gr[i].readfile_G(in);
        i++;
    }
    in.close();
} 

void list::readfile_p(ifstream& in){
    in.open("Chuc Vu.txt", ios_base::in);
    string s;
    getline(in,s,'\n');//bỏ dòng đầu    
    int i=0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofP+1;
        Position* newArr = new Position[newSize];
        for (int j = 0; j < numofP; j++)
	        newArr[j] = list_p[j];
        delete[] list_p;
        list_p = newArr;
        numofP=newSize;
        //doc file
        list_p[i].readfile_P(in);
        i++;
    }
    in.close();
} 

void list::display_mem(){
    cout<<setw(10)<<"Ma NV"<<setw(25)<<"Ho Ten"<<setw(10)<<"Ma DV"<<setw(15)<<"So dien thoai"<<setw(13)<<"Ngay sinh"
        <<setw(11)<<"Gioi tinh"<<setw(9)<<"Chuc vu"<<setw(13)<<"He so luong"<<setw(10)<<"Nam vao"<<setw(10)<<"Trinh do"
        <<setw(11)<<"Ngoai ngu"<<setw(10)<<"Luong"<<setw(10)<<"Thuc linh"<<endl<<endl;
    for(int i=0; i<numofMem; i++){
        cout<<list_mem[i]<<setw(10)<<list_mem[i].getSalary()<<setw(10)<<list_mem[i].getNewsalary()<<endl<<endl;
    }
}

void list::display_gr(){
	int ml=0,fl=0,mh=0,fh=0,mm=0,fm=0,mt=0,ft=0,ma=0,fa=0,mp=0,fp=0;
    cout<<setw(10)<<"Ma DV"<<setw(20)<<"Ten don vi"<<setw(10)<<"Ma NV"<<setw(20)<<"So luong nam"<<setw(20)<<"So luong nu"<<setw(20)<<endl<<endl;
    for(int i=0; i<numofMem; i++){
		if(list_mem[i].getGID().compare("LDR  ")==0) {
			if(list_mem[i].getGender()==0) ml++;
			else fl++;
		} else if(list_mem[i].getGID().compare("HRS  ")==0){
			if(list_mem[i].getGender()==0) mh++;
			else fh++;
		} else if(list_mem[i].getGID().compare("MKT  ")==0){
			if(list_mem[i].getGender()==0) mm++;
			else fm++;
		} else if(list_mem[i].getGID().compare("TNC  ")==0){
			if(list_mem[i].getGender()==0) mt++;
			else ft++;
		} else if(list_mem[i].getGID().compare("ACT  ")==0){
			if(list_mem[i].getGender()==0) ma++;
			else fa++;
		} else if(list_mem[i].getGID().compare("PJT  ")==0){
			if(list_mem[i].getGender()==0) mp++;
			else fp++;
		}
    }
	for(int i=0;i<numofGr;i++) {
		if(list_gr[i].getGID().compare("LDR   ")==0) cout<<list_gr[i]<<setw(20)<<ml<<setw(20)<<fl<<endl<<endl;
		else if(list_gr[i].getGID().compare("HRS   ")==0) cout<<list_gr[i]<<setw(20)<<mh<<setw(20)<<fh<<endl<<endl;
		else if(list_gr[i].getGID().compare("MKT   ")==0) cout<<list_gr[i]<<setw(20)<<mm<<setw(20)<<fm<<endl<<endl;
		else if(list_gr[i].getGID().compare("TNC   ")==0) cout<<list_gr[i]<<setw(20)<<mt<<setw(20)<<ft<<endl<<endl;
		else if(list_gr[i].getGID().compare("ACT   ")==0) cout<<list_gr[i]<<setw(20)<<ma<<setw(20)<<fa<<endl<<endl;
		else cout<<list_gr[i]<<setw(20)<<mp<<setw(20)<<fp<<endl<<endl;
	}
}

void list::display_p(){
    cout<<setw(11)<<"Ma CV"<<setw(20)<<"Ten chuc vu"<<setw(10)<<"He so PC"<<endl<<endl;
    for(int i=0; i<numofP; i++){
        cout<<list_p[i]<<endl<<endl;
    }
}