#include "member.h"
using namespace std;
list com;
member::member()
{
    mID = "";
    mlname = "";
    firstname = "";
    gID = "";
    pnumber = "";
    ns;
    gender = 0;
    position = "";
    C_salary = 0;
    year_in = 0;
    degree = "";
    L_certificate = "";
}

member::member(string mID, string mlname, string firstname, string gID, string pnumber, birthday ns, int gender, string pos, float C_salary, int year_in, string degree, string L_cer)
    : mID(mID), mlname(mlname), firstname(firstname), gID(gID), pnumber(pnumber), ns(ns), gender(gender), position(pos),
      C_salary(C_salary), year_in(year_in), degree(degree), L_certificate(L_cer) {}

//member::getter
string member::getMID() const
{
    return mID;
}

string member::getGID() const
{
    return gID;
}

int member::getGender() const
{
    return gender;
}

string member::getMlname() const
{
    return mlname;
}

string member::getFirstname() const
{
    return firstname;
}

float member::getC_salary() const
{
    return C_salary;
}

int member::getYear_in() const
{
    return year_in;
}

birthday member::getBirthday() const
{
    return ns;
}

string member::getFullName() const
{
    return mlname + " " + firstname;
}

//member::setter
void member::setmID()
{
    int temp, check = 0;
    int a[100];
    do
    {
        int alert = 21;
        gotoxy(l_uiDisplay + 5, cursor);
        cout << "Nhap ma nhan vien:                                                                                                                         ";
        gotoxy(l_uiDisplay + 25, cursor);
        string tempmID;
        cin >> tempmID;
        check = com.search(1, tempmID, a);
        if (check > 0)
        {
            gotoxy(l_uiDisplay + 5, alert);
            SET_COLOR(4);
            cout << "BAN DA NHAP TRUNG MA NHAN VIEN CO SAN,MOI BAN NHAP LAI!" << endl;
            SET_COLOR(0);
        }
        else
        {
            mID = tempmID;
        }
    } while (check > 0);
};

void member::setmlname()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ho va ten dem: ";
    getline(cin >> ws, mlname);
    mlname += " ";
};

void member::setfirstname()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ten: ";
    getline(cin >> ws, firstname);
};

void member::setgID()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ma don vi: ";
    getline(cin >> ws, gID);
};

void member::setpnumber()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap so dien thoai: ";
    cin >> pnumber;
};

void member::setns()
{
    int temp;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ngay/thang/nam sinh: " << endl;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ngay sinh: ";
    cin >> temp;
    ns.setDay(temp);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap thang sinh: ";
    cin >> temp;
    ns.setMonth(temp);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap nam sinh: ";
    cin >> temp;
    ns.setYear(temp);
};

void member::setgender()
{
    string s;
    int gt = 0;
    while (gt == 0)
    {
        gt = 1; //điều kiện dừng
        gotoxy(l_uiDisplay + 5, ++cursor);
        cout << "Nhap gioi tinh (nam/nu): ";
        cin >> s;
        if (s == "nam")
            gender = 0;
        else if (s == "nu")
            gender = 1;
        else
        {
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Ban da nhap sai!" << endl;
            gt = 0;
        }
    }
};

void member::setposition()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ma chuc vu: ";
    cin >> position;
};

void member::setC_salary()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap he so luong: ";
    cin >> C_salary;
};

void member::setyear_in()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap nam vao lam viec: ";
    cin >> year_in;
};

void member::setdegree()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap trinh do cua nhan vien: ";
    getline(cin >> ws, degree);
};

void member::setL_certificate()
{
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap trinh do ngoai ngu cua nhan vien: ";
    getline(cin >> ws, L_certificate);
};

//
void member::readfile_M(ifstream &in)
{
    string s; //bỏ qua dòng đầu
    char t;   // đọc kí tự bỏ qua
    getline(in, mID, '|');
    del_ws(mID);
    getline(in, mlname, '|');
    del_ws(mlname);
    getline(in, firstname, '|');
    del_ws(firstname);
    getline(in, gID, '|');
    del_ws(gID);
    getline(in, pnumber, '|');
    del_ws(pnumber);
    int day;
    in >> day;
    ns.setDay(day);
    in >> t; // đọc |, bỏ qua nó
    int month;
    in >> month;
    ns.setMonth(month);
    in >> t;
    int year;
    in >> year;
    ns.setYear(year);
    in >> t;
    in >> gender;
    getline(in, s, '|');
    getline(in, position, '|');
    del_ws(position);
    in >> C_salary;
    getline(in, s, '|');
    in >> year_in;
    getline(in, s, '|');
    getline(in, degree, '|');
    del_ws(degree);
    getline(in, L_certificate, '\n');
    del_ws(L_certificate);
}

void member::display()
{
    cout << setw(6) << mID << setw(17) << "|" + mlname << setw(7) << "|" + firstname << setw(6) << "|" + gID << setw(15)
         << "|" + pnumber << right << setfill('0') << "|" << setw(2) << ns.getDay() << "/" << setw(2) << ns.getMonth() << "/"
         << setfill(' ') << left << setw(5) << ns.getYear() << "|" << setw(9) << (gender == 1 ? "Nu" : "Nam") << setw(10) << "|" + position
         << "|" << setw(12) << C_salary << "|" << setw(8) << year_in << setw(10) << "|" + degree << setw(12) << "|" + L_certificate;
}

ostream &operator<<(ostream &out, member &m)
{
    //du nguyen
    out << setw(6) << m.mID << setw(17) << "|" + m.mlname << setw(7) << "|" + m.firstname << setw(6) << "|" + m.gID << setw(15)
        << "|" + m.pnumber << right << setfill('0') << "|" << setw(2) << m.ns.getDay() << "/" << setw(2) << m.ns.getMonth() << "/"
        << setfill(' ') << left << setw(5) << m.ns.getYear() << "|" << setw(9) << m.gender << setw(10) << "|" + m.position
        << "|" << setw(12) << m.C_salary << "|" << setw(8) << m.year_in << setw(10) << "|" + m.degree << setw(12) << "|" + m.L_certificate;
    return out;
}

istream &operator>>(istream &in, member &m)
{
    int temp, check = 0;
    int gt = 0;
    string s;
    int a[100];
    do
    {
        gotoxy(l_uiDisplay + 5, ++cursor);
        cout << "Nhap ma nhan vien: ";
        in >> m.mID;
        check = com.search(1, m.mID, a);
        if (check > 0)
        {   
            gotoxy(l_uiDisplay + 5, ++cursor);
            SET_COLOR(4);
            cout << "BAN DA NHAP TRUNG MA NHAN VIEN CO SAN!" << endl;
            SET_COLOR(0);
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "MOI BAN NHAP LAI: " << endl << endl;
        }
    } while (check > 0);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ho va ten dem: ";
    getline(in >> ws, m.mlname);
    m.mlname += " ";
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ten: ";
    getline(in >> ws, m.firstname);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ma don vi: ";
    getline(in >> ws, m.gID);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap so dien thoai: ";
    in >> m.pnumber;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ngay/thang/nam sinh: " << endl;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ngay sinh: ";
    in >> temp;
    m.ns.setDay(temp);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap thang sinh: ";
    in >> temp;
    m.ns.setMonth(temp);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap nam sinh: ";
    in >> temp;
    m.ns.setYear(temp);
    while (gt == 0)
    {
        gt = 1; //điều kiện dừng
        gotoxy(l_uiDisplay + 5, ++cursor);
        cout << "Nhap gioi tinh (nam/nu): ";
        in >> s;
        if (s == "nam")
            m.gender = 0;
        else if (s == "nu")
            m.gender = 1;
        else
        {
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Ban da nhap sai!" << endl;
            gt = 0;
        }
    }
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap ma chuc vu: ";
    in >> m.position;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap he so luong: ";
    in >> m.C_salary;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap nam vao lam viec: ";
    in >> m.year_in;
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap trinh do cua nhan vien: ";
    getline(in >> ws, m.degree);
    gotoxy(l_uiDisplay + 5, ++cursor);
    cout << "Nhap trinh do ngoai ngu cua nhan vien: ";
    getline(in >> ws, m.L_certificate);
    gotoxy(l_uiDisplay + 5, ++cursor + 5);
    return in;
}

int member::getSalary()
{
    return (A / 100) * (int(C_salary * 100));
}

int member::getNewsalary()
{
    if (position.compare("GD") == 0 || position.compare("PGD") == 0)
    {
        return (getSalary() / 10 * 15);
    }
    else if (position.compare("TP") == 0 || position.compare("PP") == 0)
    {
        return (getSalary() / 100 * 125);
    }
    else
        return getSalary();
}

bool member::isEqual_name(string s){
    int len = getFullName().length() - s.length();
    int lenS = s.length();
    for(int i=0; i <= len; i++){
        if(s.compare(0,lenS,getFullName(),i,lenS)==0) return 0;
    }
    return 1;
}

bool member::isEqual(int chon, string s)
{
    string temp; //chuyển kiểu int/float sang string
    string temp1, temp2, temp3, temp4, temp5, temp6;
    ostringstream convert, convert1, convert2;
    switch (chon)
    {
    case 1:
        return s.compare(this->mID);
    case 2:
        return s.compare(this->mlname);
    case 3:
        return s.compare(this->firstname);
    case 4:
        return s.compare(this->gID);
    case 5:
        return s.compare(this->pnumber);
    case 6:
        /*convert << this->ns.getDay();
        temp = convert.str();
        convert1 << this->ns.getMonth();
        temp += convert1.str();
        convert2 << this->ns.getYear();
        temp += convert2.str();*/
        temp = to_string(this->ns.getDay()) + to_string(this->ns.getMonth()) + to_string(this->ns.getYear());
        if(s == temp) return 0;
        temp1 = "0" + to_string(this->ns.getMonth()) + to_string(this->ns.getYear());
        if(s == temp1) return 0;
        temp2 = to_string(this->ns.getDay()) + "0" + to_string(this->ns.getYear());
        if(s == temp2) return 0;
        temp3 = to_string(ns.getDay()) + to_string(ns.getMonth()) + "0";
        if(s == temp3) return 0;
        temp4 = "0" + to_string(ns.getMonth()) + "0";
        if(s == temp4) return 0;
        temp5 = "00" + to_string(ns.getYear());
        if(s == temp5) return 0;
        temp6 = to_string(ns.getDay()) + "00";
        return s.compare(temp6);
    case 7:
        temp = to_string(this->gender);
        return s.compare(temp);
    case 8:
        return s.compare(this->position);
    case 9:
        convert << this->C_salary;
        temp = convert.str();
        cout << temp;
        return s.compare(temp);
    case 10:
        temp = to_string(this->year_in);
        return s.compare(temp);
    case 11:
        return s.compare(this->degree);
    case 12:
        return s.compare(this->L_certificate);
    case 13:
        return s.compare(this->getFullName());
    case 14:
        return isEqual_name(s);
    default:
        return false;
    }
}
