#include "list.h"
using namespace std;

//Khoi tao
list::list(int NMem, int NGr, int NP)
    : numofMem(NMem), numofGr(NGr), numofP(NP)
{
    list_mem = new member[numofMem];
    list_gr = new group[numofGr];
    list_p = new Position[numofP];
}

list::list(const list &l)
{
    this->numofMem = l.numofMem;
    this->numofGr = l.numofGr;
    this->numofP = l.numofP;

    this->list_mem = new member[numofMem];
    this->list_gr = new group[numofGr];
    this->list_p = new Position[numofP];

    for (int i = 0; i < numofMem; i++)
    {
        this->list_mem[i] = l.list_mem[i];
    }
    for (int i = 0; i < numofGr; i++)
    {
        this->list_gr[i] = l.list_gr[i];
    }
    for (int i = 0; i < numofP; i++)
    {
        this->list_p[i] = l.list_p[i];
    }
}

list::~list()
{
    delete[] list_mem;
    delete[] list_gr;
    delete[] list_p;
}
//list::readfile
void list::readfile_mem(ifstream &in)
{
    in.open(nhanvientxt, ios_base::in);
    string s;
    getline(in, s, '\n');
    int i = 0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofMem + 1;
        member *newArr = new member[newSize];
        for (int j = 0; j < numofMem; j++)
            newArr[j] = list_mem[j];
        delete[] list_mem;
        numofMem = newSize;
        list_mem = newArr;
        //doc file
        list_mem[i].readfile_M(in);
        i++;
    }
    in.close();
}

void list::readfile_gr(ifstream &in)
{
    in.open("Don Vi.txt", ios_base::in);
    string s;
    getline(in, s, '\n'); //bỏ dòng đầu
    int i = 0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofGr + 1;
        group *newArr = new group[newSize];
        for (int j = 0; j < numofGr; j++)
            newArr[j] = list_gr[j];
        delete[] list_gr;
        list_gr = newArr;
        numofGr = newSize;
        //doc file
        list_gr[i].readfile_G(in);
        i++;
    }
    in.close();
}

void list::readfile_p(ifstream &in)
{
    in.open("Chuc Vu.txt", ios_base::in);
    string s;
    getline(in, s, '\n'); //bỏ dòng đầu
    int i = 0;
    while (!in.eof())
    {
        //tăng mảng lên
        int newSize = numofP + 1;
        Position *newArr = new Position[newSize];
        for (int j = 0; j < numofP; j++)
            newArr[j] = list_p[j];
        delete[] list_p;
        list_p = newArr;
        numofP = newSize;
        //doc file
        list_p[i].readfile_P(in);
        i++;
    }
    in.close();
}
//list::writefile
void list::writefile_mem(ofstream &ofs, string txt)
{
    ofs.open(txt.c_str(), ios_base::trunc);
    ofs << left << setw(6) << "Ma NV" << setw(17) << "|Ho" << setw(7) << "|Ten" << setw(6) << "|Ma DV" << setw(15) << "|So dien thoai" << setw(12) << "|Ngay sinh"
        << setw(10) << "|Gioi tinh" << setw(10) << "|Chuc vu" << setw(13) << "|He so luong" << setw(9) << "|Nam vao" << setw(10) << "|Trinh do" << setw(12) << "|Ngoai ngu" << endl;
    for (int i = 0; i < numofMem - 1; i++)
    {
        ofs << left << list_mem[i] << endl;
    }
    ofs << left << list_mem[numofMem - 1];
    ofs.close();
}
//list::display
void list::display_mem()
{
    system("cls");
    getCol();
    uiDisplay(numofMem + 5);
    gotoxy(l_uiDisplay + 60, 0);
    cout << "Danh sach nhan vien trong cong ty";
    gotoxy(l_uiDisplay + 5, 6);
    cout << setw(6) << "Ma NV" << setw(17) << "|Ho" << setw(7) << "|Ten" << setw(6) << "|Ma DV" << setw(15) << "|So dien thoai" << setw(12)
         << "|Ngay sinh" << setw(10) << "|Gioi tinh" << setw(10) << "|Chuc vu" << setw(13) << "|He so luong" << setw(9) << "|Nam vao"
         << setw(10) << "|Trinh do" << setw(12) << "|Ngoai ngu" << setw(10) << "|Luong" << setw(10) << "|Thuc linh" << endl
         << endl;
    cursor = 0;
    for (int i = 0; i < numofMem; i++)
    {
        gotoxy(l_uiDisplay + 5, i + 8);
        list_mem[i].display();
        cout << "|" << setw(9) << list_mem[i].getSalary() << "|" << setw(9) << list_mem[i].getNewsalary() << endl
             << endl;
        cursor = i + 8; //lưu vị trí con trỏ trên màn hình
    }
    gotoxy(l_uiDisplay + 5, cursor + 2); //đưa cái press any key xuống cuối
}

void list::count_gender(int &ml, int &fl, int &mh, int &fh, int &mm, int &fm, int &mt, int &ft, int &ma, int &fa, int &mp, int &fp)
{
    for (int i = 0; i < numofMem; i++)
    {
        if (list_mem[i].getGID().compare("LDR") == 0)
        {
            if (list_mem[i].getGender() == 0)
                ml++;
            else
                fl++;
        }
        else if (list_mem[i].getGID().compare("HRS") == 0)
        {
            if (list_mem[i].getGender() == 0)
                mh++;
            else
                fh++;
        }
        else if (list_mem[i].getGID().compare("MKT") == 0)
        {
            if (list_mem[i].getGender() == 0)
                mm++;
            else
                fm++;
        }
        else if (list_mem[i].getGID().compare("TNC") == 0)
        {
            if (list_mem[i].getGender() == 0)
                mt++;
            else
                ft++;
        }
        else if (list_mem[i].getGID().compare("ACT") == 0)
        {
            if (list_mem[i].getGender() == 0)
                ma++;
            else
                fa++;
        }
        else if (list_mem[i].getGID().compare("PJT") == 0)
        {
            if (list_mem[i].getGender() == 0)
                mp++;
            else
                fp++;
        }
    }
}

void list::getSumOfSalary(int &sumL, int &sumNL, int &sumH, int &sumNH, int &sumM, int &sumNM, int &sumT, int &sumNT, int &sumA, int &sumNA, int &sumP, int &sumNP)
{
    for (int i = 0; i < numofMem; i++)
    {
        if (list_mem[i].getGID().compare("LDR") == 0)
        {
            sumL += list_mem[i].getSalary();
            sumNL += list_mem[i].getNewsalary();
        }
        else if (list_mem[i].getGID().compare("HRS") == 0)
        {
            sumH += list_mem[i].getSalary();
            sumNH += list_mem[i].getNewsalary();
        }
        else if (list_mem[i].getGID().compare("MKT") == 0)
        {
            sumM += list_mem[i].getSalary();
            sumNM += list_mem[i].getNewsalary();
        }
        else if (list_mem[i].getGID().compare("TNC") == 0)
        {
            sumT += list_mem[i].getSalary();
            sumNT += list_mem[i].getNewsalary();
        }
        else if (list_mem[i].getGID().compare("ACT") == 0)
        {
            sumA += list_mem[i].getSalary();
            sumNA += list_mem[i].getNewsalary();
        }
        else
        {
            sumP += list_mem[i].getSalary();
            sumNP += list_mem[i].getNewsalary();
        }
    }
}

void list::display_gr()
{
    system("cls");
    getCol();
    uiDisplay(numofGr + 5);
    gotoxy(l_uiDisplay + 60, 0);
    cout << "Danh sach don vi trong cong ty";
    gotoxy(l_uiDisplay + 20, 6);
    int ml = 0, fl = 0, mh = 0, fh = 0, mm = 0, fm = 0, mt = 0, ft = 0, ma = 0, fa = 0, mp = 0, fp = 0;
    int sumL = 0, sumNL = 0, sumH = 0, sumNH = 0, sumM = 0, sumNM = 0, sumT = 0, sumNT = 0, sumA = 0, sumNA = 0, sumP = 0, sumNP = 0;
    count_gender(ml, fl, mh, fh, mm, fm, mt, ft, ma, fa, mp, fp);
    getSumOfSalary(sumL, sumNL, sumH, sumNH, sumM, sumNM, sumT, sumNT, sumA, sumNA, sumP, sumNP);
    cout << setw(10) << "Ma DV" << setw(20) << "|Ten don vi" << setw(10) << "|Ma NV" << setw(21) << "|So luong nam"
         << setw(21) << "|So luong nu" << setw(21) << "|Tong luong" << setw(20) << "|Tong thuc linh" << endl
         << endl;
    cursor = 0;
    for (int i = 0; i < numofGr; i++)
    {
        gotoxy(l_uiDisplay + 20, i + 8);
        if (list_gr[i].getGID().compare("LDR") == 0)
            cout << list_gr[i] << "|" << setw(20) << ml << "|" << setw(20) << fl << "|" << setw(20) << sumL << "|" << setw(20) << sumNL
                 << endl
                 << endl;
        else if (list_gr[i].getGID().compare("HRS") == 0)
            cout << list_gr[i] << "|" << setw(20) << mh << "|" << setw(20) << fh << "|" << setw(20) << sumH << "|" << setw(20) << sumNH
                 << endl
                 << endl;
        else if (list_gr[i].getGID().compare("MKT") == 0)
            cout << list_gr[i] << "|" << setw(20) << mm << "|" << setw(20) << fm << "|" << setw(20) << sumM << "|" << setw(20) << sumNM
                 << endl
                 << endl;
        else if (list_gr[i].getGID().compare("TNC") == 0)
            cout << list_gr[i] << "|" << setw(20) << mt << "|" << setw(20) << ft << "|" << setw(20) << sumT << "|" << setw(20) << sumNT
                 << endl
                 << endl;
        else if (list_gr[i].getGID().compare("ACT") == 0)
            cout << list_gr[i] << "|" << setw(20) << ma << "|" << setw(20) << fa << "|" << setw(20) << sumA << "|" << setw(20) << sumNA
                 << endl
                 << endl;
        else
            cout << list_gr[i] << "|" << setw(20) << mp << "|" << setw(20) << fp << "|" << setw(20) << sumP << "|" << setw(20) << sumNP
                 << endl
                 << endl;
        cursor = i + 8; //lưu vị trí con trỏ trên màn hình
    }
    gotoxy(l_uiDisplay + 5, cursor + 2); //đưa cái press any key xuống cuối
}

void list::display_p()
{
    system("cls");
    getCol();
    uiDisplay(numofP + 5);
    gotoxy(l_uiDisplay + 60, 0);
    cout << "Danh sach chuc vu trong cong ty";
    gotoxy(l_uiDisplay + 56, 6);
    cout << setw(10) << "Ma CV" << setw(20) << "|Ten chuc vu" << setw(10) << "|He so PC" << endl
         << endl;
    cursor = 0;
    for (int i = 0; i < numofP; i++)
    {
        gotoxy(l_uiDisplay + 56, i + 8);
        cout << list_p[i] << endl
             << endl;
        cursor = i + 8; //lưu vị trí con trỏ trên màn hình
    }
    gotoxy(l_uiDisplay + 50, cursor + 2); //đưa cái press any key xuống cuối
}

void list::menu_dis()
{
    int key;
    do
    {
        system("cls");
        getCol();
        uiFunc(11);
        cursor = 5;

        gotoxy(l_uiFuns + 40, 0);
        cout << "THONG KE THEO DANH SACH" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "1: Nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "2: Don vi" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "3: Chuc vu" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "0: Thoat!" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon: ";
        cin >> key;
        //215
        switch (key)
        {
        case 0:
            break;
        case 1:
            display_mem();
            system("pause");
            break;
        case 2:
            display_gr();
            system("pause");
            break;
        case 3:
            display_p();
            system("pause");
            break;
        default:
            cursor = 5;
            system("cls");
            getCol();
            uiFunc(11);
            gotoxy(l_uiFuns + 40, 0);
            cout << "Thong ke theo danh sach" << endl;
            gotoxy(l_uiFuns + 5, ++cursor);
            SET_COLOR(4);
            cout << "Khong co chuc nang nay. Moi nhap lai!" << endl;
            gotoxy(l_uiFuns + 5, 7);
            system("pause");
            SET_COLOR(0);
        }
    } while (key);
}
//list::search
int list::search(int chon, string s, int a[])
{
    int n = 0;
    for (int i = 0; i < numofMem; i++)
    {
        if (list_mem[i].isEqual(chon, s) == 0)
        {
            a[n++] = i;
        }
    }
    return n;
}

void list::search()
{
    int a[100];
    string tt; //thông tin
    char chon2;
    int chon;
    do
    {
        chon = menu_Search(tt);
        if(chon == 0) break;
        int k = search(chon, tt, a);
        list fileSearchResult; //lưu lại danh sách kết quả tìm được
        if (k > 0)
        {
            uiDisplay(k + 10);
            cursor = 5;
            gotoxy(l_uiDisplay + 65, 0);
            cout << "TIM KIEM NHAN VIEN";
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Co " << k << " ket qua phu hop: " << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << setw(6) << "Ma NV" << setw(17) << "|Ho" << setw(7) << "|Ten" << setw(6) << "|Ma DV" << setw(15) << "|So dien thoai" << setw(12)
                 << "|Ngay sinh" << setw(10) << "|Gioi tinh" << setw(10) << "|Chuc vu" << setw(13) << "|He so luong" << setw(9) << "|Nam vao"
                 << setw(10) << "|Trinh do" << setw(12) << "|Ngoai ngu" << endl
                 << endl;
            for (int i = 0; i < k; i++)
            {
                gotoxy(l_uiDisplay + 5, ++cursor);
                list_mem[a[i]].display();
                cout << endl;
                fileSearchResult.add(list_mem[a[i]], 0, nhanviensearch);
            }
            //chon nhap file
            char key;
            cursor += 2;                //vị trí con trỏ hỏi Ban co muon in ket qua ra file khong?[C/K]:
            int errcursor = cursor + 1; //vị trí con trỏ thông báo lỗi
            do
            {
                gotoxy(l_uiDisplay + 5, cursor);
                cout << "Ban co muon in ket qua ra file khong?[C/K]:    ";
                gotoxy(l_uiDisplay + 49, cursor);
                cin >> key;
                key = toupper(key);
                if (key != 'K' && key != 'C')
                {
                    gotoxy(l_uiDisplay + 5, errcursor);
                    SET_COLOR(4);
                    cout << "Khong co lua chon nay! Moi ban nhap lai:" << endl;
                    SET_COLOR(0);
                    gotoxy(l_uiDisplay + 5, cursor);
                    cout << "                                               " << endl; //xóa c/k câu trả lời của "Ban co muon in ket qua ra file khong?[C/K]:"
                }
                else
                {
                    gotoxy(l_uiDisplay + 5, errcursor);
                    cout << "                                               " << endl; //xóa thông bao không có lựa chọn này
                }
            } while (key != 'K' && key != 'C');
            if (key == 'C')
            { //xuất file
                ofstream ofs;
                string fileNameResult; //trả về tên file xuất
                string tempFileName;   // lưu tên file tạm
                int tcursor = ++cursor;
                int errcursor = tcursor + 1;
                do //chạy cho đến khi không nhập gì hoặc nhâp đúng tên file chưa tồn tại
                {
                    gotoxy(l_uiDisplay + 5, tcursor);
                    cout << "Nhap ten file hoac bo trong de luu vs ten mac dinh!: ";
                    cin.ignore();
                    getline(cin, tempFileName);
                    tempFileName = tempFileName + ".txt";

                    if (tempFileName == ".txt") //lưu mặc định/////////////////////////////////
                    {
                        fileNameResult = nhanviensearch;                      //gán tên file gốc vào tên file xuất
                        int i = 0;                                            //file xuất có tên là fileNameResult + (i).txt
                        fileNameResult.erase(fileNameResult.length() - 4, 4); //xoa .txt
                        do                                                    //thực hiện cho đến khi tạo được file chưa tồn tại
                        {
                            tempFileName = fileNameResult + "(" + to_string(i) + ").txt"; // tạo một file tạm để kiểm tra. đỡ tạo cái xóa txt nhiều lần

                            if (checkFile(tempFileName) == true)
                            { //nếu tồn tại thì tăng i lên tạo tên khác
                                i++;
                            }
                            else
                            { //nếu không tồn tại thì trả tên file cho fileNameResult
                                fileNameResult = tempFileName;
                                break;
                            }
                        } while (1);
                    }

                    else //luu theo tên người nhập////////////////////////////
                        if (checkFile(tempFileName) == true)
                    {
                        gotoxy(l_uiDisplay + 5, errcursor);
                        SET_COLOR(4);
                        cout << "Tep nay da ton tai!. Moi nhap lai!" << endl;
                        SET_COLOR(0);
                        gotoxy(l_uiDisplay + 5, tcursor);
                        cout << "                                                                   ";
                    }
                    else
                    {
                        gotoxy(l_uiDisplay + 5, errcursor);
                        cout << "                                       " << endl; //xoas dong tệp này đã tồn tại
                        fileNameResult = tempFileName;
                    }

                } while (checkFile(tempFileName) == true);
                gotoxy(l_uiDisplay + 5, ++cursor);
                SET_COLOR(2);
                cout << "Da luu file voi ten:" << fileNameResult << endl;
                SET_COLOR(0);
                fileSearchResult.writefile_mem(ofs, fileNameResult); //xuất file
            }
        }
        else
        {
            cursor = 6;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "                                               "; //xoa thang
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "                                               "; //xoa nam
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "                                               "; //xoa nam
            cursor = 6;
            gotoxy(l_uiDisplay + 5, cursor);
            SET_COLOR(4);
            cout << "Khong tim thay ket qua phu hop!                                                                   " << endl;
            SET_COLOR(0);
        }
        gotoxy(l_uiDisplay + 5, ++cursor);
        cout << "Muon tiep tuc [C/K]: ";
        cin >> chon2;
        chon2 = toupper(chon2);
    } while (chon2 != 'K');
    gotoxy(l_uiDisplay + 5, ++cursor);
    if(chon != 0) system("pause");
}

int list::menu_Search(string &tt)
{
    int chon;
    do
    {
        system("cls");
        getCol();
        uiFunc(18);
        cursor = 5;
        gotoxy(l_uiFuns + 45, 0);
        cout << "TIM KIEM NHAN VIEN";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Ban muon tim kiem thong tin theo cach nao:" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "1: Ma nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "2: Ho va ten" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "3: Ma don vi" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "4: So dien thoai" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "5: Ngay sinh" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "6: Gioi tinh" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "7: Ma chuc vu" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "8: He so luong" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "9: Nam vao" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "10: Trinh do, cap bac" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "11: Bang ngoai ngu" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "0: Thoat!" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon: ";
        cin >> chon;
        if(chon == 0) return chon;
        cursor = 5;
        uiDisplay(18);
        gotoxy(l_uiDisplay + 65, 0);
        cout << "TIM KIEM NHAN VIEN";
        if (chon > 1) chon++;
        if (chon == 6)
        {
            string s;
            tt = s;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap ngay: ";
            cin >> s;
            tt += s;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap thang: ";
            cin >> s;
            tt += s;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap nam: ";
            cin >> s;
            tt += s;
            gotoxy(l_uiDisplay + 5, ++cursor);
        }
        else if (chon == 7)
        {
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap gioi tinh [0:nam/1:nu]: ";
            getline(cin >> ws, tt);
        }
        else
        {
            if (chon == 3)
                chon += 11;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap thong tin can tim kiem: ";
            getline(cin >> ws, tt);
        }
        return chon;
    } while (chon);
}
//list::add
int list::check(member &m)
{
    int temp = 0;
    for (int i = 0; i < numofMem; i++)
    {
        if (m.getMID().compare(list_mem[i].getMID()) == 0)
        {
            temp = -1;
            break;
        }
    }
    if (temp == -1)
    {
        cursor = 5;
        gotoxy(l_uiDisplay + 5, ++cursor);
        SET_COLOR(4);
        cout << "BAN DA NHAP TRUNG MA NHAN VIEN CO SAN!" << endl;
        SET_COLOR(0);
        gotoxy(l_uiDisplay + 5, ++cursor);
        cout << "MOI BAN NHAP LAI: " << endl
             << endl;
        return -1;
    }
    else
        return 0;
}

void list::add(member &m, int k, string txt)
{
    numofMem++;
    member *b = new member[numofMem];
    for (int i = 0; i < numofMem - 1; i++)
        b[i] = list_mem[i];
    for (int i = numofMem - 1; i > k; i--)
        b[i] = b[i - 1];
    b[k] = m;
    /*Tiến hành cấp phát động lại list_mem*/
    delete[] list_mem;
    list_mem = new member[numofMem];
    for (int i = 0; i < numofMem; i++)
        list_mem[i] = b[i];
    ofstream ofs;
    writefile_mem(ofs, txt);
}

void list::add_menu()
{
    int cv;
    member m;
    int k, x;
    do
    {
        system("cls");
        getCol();
        cursor = 5;
        uiFunc(11);
        gotoxy(l_uiFuns + 45, 0);
        cout << "THEM NHAN VIEN";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon chuc nang:" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "1: Them nhan vien vao dau danh sach" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "2: Them nhan vien vao cuoi danh sach" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "3: Them vao vi tri bat ki" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "0: Thoat!" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon: ";
        cin >> cv;
        system("cls");
        getCol();
        cursor = 5;
        switch (cv)
        {
        case 1:
            uiDisplay(36);
            cursor = 5;
            gotoxy(l_uiDisplay + 70, 0);
            cout << "THEM NHAN VIEN";
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap nhan vien muon them vao dau danh sach: " << endl;
            cin >> m;
            add(m, 0, nhanvientxt);
            gotoxy(l_uiDisplay + 5, ++cursor);
            SET_COLOR(2);
            cout << "-------------Da them thanh cong!-------------" << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            system("pause");
            SET_COLOR(0);
            break;
        case 2:
            uiDisplay(36);
            cursor = 5;
            gotoxy(l_uiDisplay + 70, 0);
            cout << "THEM NHAN VIEN";
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap nhan vien muon them vao cuoi danh sach: " << endl;
            cin >> m;
            k = --numofMem;
            add(m, k, nhanvientxt);
            gotoxy(l_uiDisplay + 5, ++cursor);
            SET_COLOR(2);
            cout << "-------------Da them thanh cong!-------------" << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            system("pause");
            SET_COLOR(0);
            break;
        case 3:
            uiDisplay(36);
            cursor = 5;
            gotoxy(l_uiDisplay + 70, 0);
            cout << "THEM NHAN VIEN";
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Nhap nhan vien muon them vao vi tri bat ki trong danh sach: " << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cin >> m;
            do
            {
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout<<"Luu y: Vi tri dau tien bat dau tu so 0!";
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "Nhap vi tri muon them: ";
                cin >> k;
                if (k < 0 && k > numofMem)
                {
                    gotoxy(l_uiDisplay + 5, ++cursor);
                    SET_COLOR(4);
                    cout << "Ban da nhap vi tri vuot ngoai danh sach, moi ban nhap lai!";
                    SET_COLOR(0);
                    k = -1;
                }

            } while (k == -1);
            add(m, k, nhanvientxt);
            gotoxy(l_uiDisplay + 5, ++cursor);
            SET_COLOR(2);
            cout << "--------------Da them thanh cong!-------------" << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            system("pause");
            SET_COLOR(0);
            break;
        case 0:
            break;
        default:
            system("cls");
            getCol();
            cursor = 5;
            uiFunc(11);
            gotoxy(45, 0);
            cout << "THEM NHAN VIEN";
            gotoxy(5, ++cursor);
            SET_COLOR(4);
            cout << "Khong co chuc nang nay!" << endl;
            gotoxy(5, ++cursor);
            system("pause");
            SET_COLOR(0);
        }
    } while (cv != 0);
}
//list::delete
void list::delete_mem_age(int key)
{
    system("cls");
    getCol();
    uiFunc(11);
    gotoxy(l_uiFuns + 40, 0);
    cout << "XOA THEO NAM SINH";
    birthday dayAge;
    bool checkdel = false;
    char keyy;
    int run = 0;
    int age = 60;
    if (key == 4)
    {
        int nam;
        gotoxy(l_uiFuns + 5, 6);
        cout << "Nhap nam sinh: ";
        cin >> nam;
        dayAge = dateNow;
        dayAge.setYear(nam);
    }
    else if (key == 5)
    {
        gotoxy(l_uiFuns + 5, 6);
        cout << "Nhap tuoi muon xoa: ";
        cin >> age;
        dayAge = dateNow - age;
    }
    else if (key == 6)
    {

        dayAge = dateNow - age;
    }

    do
    {
        //tim diem xoa
        if (key == 5 || key == 6)
        {
            while (dayAge < list_mem[run].getBirthday() && run < numofMem) //nếu chưa đủ 60(age) tuổi thì bỏ qua
            {
                run++;
            }
        }
        //tim diem xoa
        if (key == 4)
        {
            while (dayAge.getYear() != list_mem[run].getBirthday().getYear() && run < numofMem) //nếu chưa đủ 60(age) tuổi thì bỏ qua
            {
                run++;
            }
        }

        //gán lại mảng để xóa
        if (run < numofMem)
        {
            checkdel = true;
            //>= 60 tuổi
            int newSize = numofMem - 1;
            member *newArr = new member[newSize];
            int i = 0;
            int j = 0;
            //gán phần tử cho mảng mới bỏ qua phần tử muốn xóa
            while (i < numofMem && j < newSize)
            {
                if (i == run) //Nếu gặp người cần xóa thì tăng i để bỏ qua
                {
                    i++;
                }
                newArr[j] = list_mem[i];
                i++;
                j++;
            }
            delete[] list_mem;
            //trả lại mảng đã xóa
            numofMem = newSize; //tru 1 vi danh sach bat dau tu 0
            list_mem = newArr;
        }

    } while (run < numofMem);
    if (checkdel == true)
    {
        ofstream ofs;
        gotoxy(l_uiFuns + 5, 6);
        cout << "Danh sach sau khi xoa se duoc luu tu dong vao file Nhan Vien_out.txt" << endl;
        gotoxy(l_uiFuns + 5, 7);
        cout << "Ban co muon luu vao file Nhan Vien.txt hay khong [C/K]: ";
        cin >> keyy;
        keyy = toupper(keyy);
        if (keyy == 'C')
            writefile_mem(ofs, nhanvientxt);
        writefile_mem(ofs, nhanvienouttxt);
    }
    if (checkdel == true)
    {
        system("cls");
        getCol();
        uiFunc(11);
        gotoxy(l_uiFuns + 40, 0);
        cout << "XOA THEO NAM SINH";
        gotoxy(l_uiFuns + 5, 6);
        SET_COLOR(2);
        cout << "Da xoa xong!" << endl;
        gotoxy(l_uiFuns + 5, 7);
        system("pause");
        SET_COLOR(0);
    }
    else
    {
        system("cls");
        getCol();
        uiFunc(11);
        gotoxy(l_uiFuns + 40, 0);
        cout << "XOA THEO NAM SINH";
        gotoxy(l_uiFuns + 5, 6);
        SET_COLOR(4);
        cout << "Khong co nguoi nao co thong tin trung khop!" << endl;
        gotoxy(l_uiFuns + 5, 7);
        system("pause");
        SET_COLOR(0);
    }
}

void list::delete_mem_name_id(int option) //xóa theo tên hoặc id
{
    int a[100];
    char key;
    string content;
    system("cls");
    getCol();
    uiFunc(11);
    if (option == 1)
    {
        gotoxy(l_uiFuns + 45, 0);
        cout << "XOA THEO ID.";
        gotoxy(l_uiFuns + 5, 6);
        cout << "Nhap ma nhan vien: ";
    }
    else if (option == 3)
    {
        gotoxy(l_uiFuns + 45, 0);
        cout << "XOA THEO TEN";
        gotoxy(l_uiFuns + 5, 6);
        cout << "Nhap ten nhan vien: ";
    }
    else if (option == 13)
    {
        gotoxy(l_uiFuns + 45, 0);
        cout << "XOA THEO HO VA TEN";
        gotoxy(l_uiFuns + 5, 6);
        cout << "Nhap ho ten nhan vien: ";
    }
    cin.ignore();
    getline(cin, content);
    int n = search(option, content, a);
    if (n == 0)
    {
        //báo chưa xóa
        system("cls");
        getCol();
        uiFunc(11);
        gotoxy(l_uiFuns + 40, 0);
        cout << "1. Xoa theo ID.";
        gotoxy(l_uiFuns + 5, 6);
        SET_COLOR(4);
        cout << "Khong co nguoi nao co thong tin trung khop!" << endl;
        gotoxy(l_uiFuns + 5, 7);
        system("pause");
        SET_COLOR(0);
    }
    else
    {
        int newSize = numofMem - n;
        member *newListMember = new member[newSize];
        int i = 0;
        int j = 0;
        int t = 0;
        while (i < numofMem && j < newSize)
        {
            if (i == a[t])
            {

                t++;
                i++;
            }
            else
            {
                newListMember[j] = list_mem[i];
                i++;
                j++;
            }
        }
        delete[] list_mem;
        numofMem = newSize;
        list_mem = newListMember;
        for (int i = 0; i < numofMem; i++)
        {
            list_mem[i];
        }
        if (numofMem > 0)
        {
            ofstream ofs;
            gotoxy(l_uiFuns + 5, 6);
            cout << "Danh sach sau khi xoa se duoc luu tu dong vao file Nhan Vien_out.txt" << endl;
            gotoxy(l_uiFuns + 5, 7);
            cout << "Ban co muon luu vao file Nhan Vien.txt hay khong [C/K]: ";
            cin >> key;
            key = toupper(key);
            if (key == 'C')
                writefile_mem(ofs, nhanvientxt);
            writefile_mem(ofs, nhanvienouttxt);
        }

        //báo xóa xong
        system("cls");
        getCol();
        uiFunc(11);
        gotoxy(l_uiFuns + 40, 0);
        cout << "1. Xoa theo ID.";
        gotoxy(l_uiFuns + 5, 6);
        SET_COLOR(2);
        cout << "Da xoa xong!" << endl;
        gotoxy(l_uiFuns + 5, 7);
        system("pause");
        SET_COLOR(0);
    }
}
//main_del_mem
void list::delete_mem()
{
    int ktr = 0;
    do
    {
        cursor = 5;
        system("cls");
        getCol();
        uiFunc(11);
        gotoxy(l_uiFuns + 45, 0);
        cout << "XOA NHAN VIEN";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 1. Xoa theo ID.\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 2. Xoa theo ten.\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 3. Xoa theo ho ten.\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 4. Xoa theo nam sinh. \n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 5. Xoa lon hon tuoi.\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 6. Xoa nguoi tren 60 tuoi.\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 7. Hien thi ds.\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << " 0. Ket Thuc\n";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon chuc nang: ";
        int key;
        cin >> key;
        gotoxy(l_uiFuns + 5, ++cursor + 3);
        string fun;
        switch (key)
        {
        case 1:
            this->delete_mem_name_id(1);
            break;
        case 2:
            this->delete_mem_name_id(3);
            break;
        case 3:
            this->delete_mem_name_id(13);
            break;
        case 4:
            this->delete_mem_age(key);
            break;
        case 5:
            this->delete_mem_age(key);
            break;
        case 6:
            this->delete_mem_age(key);
            break;
        case 7:
            this->display_mem();
            system("pause");
            break;
        case 0:
            ktr = -1;
            break;
        default:
            system("cls");
            getCol();
            uiFunc(11);
            gotoxy(l_uiFuns + 40, 0);
            cout << "Xoa mot nhan vien";
            gotoxy(l_uiFuns + 5, 6);
            SET_COLOR(4);
            cout << "Khong co chuc nang nay. Moi nhap lai!" << endl;
            gotoxy(l_uiFuns + 5, 7);
            system("pause");
            SET_COLOR(0);
        }

    } while (ktr != -1);
}

//list::sort
void list::sort()
{
    int key;
    do
    {
        system("cls");
        getCol();
        uiFunc(10);
        cursor = 5;
        gotoxy(l_uiFuns + 50, 0);
        cout << "SAP XEP";
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "1: Tang dan" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "2: Giam dan" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "0: Thoat!" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon: ";
        cin >> key;
        if (key == 1)
            sort(ascending);
        else if (key == 2)
            sort(descending);
    } while (key);
}

void list::sort(bool CompFunc(const member &, const member &, int))
{
    int key;
    do
    {
        menu_Sort(key);
        if (key == 7)
            display_mem();
        else if (key != 0)
            QuickSort(0, numofMem - 1, key, CompFunc); //nếu kp đk dừng(key=0) thì tiếp tục
        ofstream ofs;
        writefile_mem(ofs, nhanvienouttxt);
        if (key != 0)
        {
            gotoxy(l_uiFuns + 5, ++cursor);
            SET_COLOR(2);
            cout << "------------Da sap xep xong!------------" << endl;
            gotoxy(l_uiFuns + 5, ++cursor);
            system("pause");
            SET_COLOR(0);
        }
    } while (key);
}

void list::QuickSort(int l, int r, int key, bool CompFunc(const member &, const member &, int))
{
    //key -> trong menu_Sort
    int i = l, j = r;
    member q = list_mem[(l + r) / 2]; //lấy phần tử ở giữa ds
    while (i < j)
    {
        while ((CompFunc)(q, list_mem[i], key))
            i++;
        while ((CompFunc)(list_mem[j], q, key))
            j--;
        if (i <= j)
        {
            member temp = list_mem[i];
            list_mem[i] = list_mem[j];
            list_mem[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
        QuickSort(i, r, key, CompFunc);
    if (j > l)
        QuickSort(l, j, key, CompFunc);
}

void list::menu_Sort(int &key)
{
    do
    {
        system("cls");
        getCol();
        uiFunc(15);
        gotoxy(l_uiFuns + 50, 0);
        cout << "SAP XEP";
        cursor = 5;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Ban muon sap xep theo cach nao: " << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "1: Ma nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "2: Ho va ten" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "3: Ma don vi" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "4: Nam sinh" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "5: He so luong" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "6: Nam vao" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "7: Hien thi danh sach nhan vien " << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "0: Thoat!" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon: ";
        cin >> key;
    } while (key < 0 || key > 7);
}
//list::menu
void list::menu()
{

    int chon;
    member m;
    int k, x;
    do
    {

        system("cls");
        getCol();
        uiFunc(11);

        gotoxy(l_uiFuns + 50, 0);
        cout << "MENU" << endl;
        cursor = 5;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "1: Thong ke" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "2: Sua thong tin nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "3: Them mot nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "4: Tim kiem nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "5: Xoa nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "6: Sap xep danh sach nhan vien" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "0: Thoat!" << endl;
        gotoxy(l_uiFuns + 5, ++cursor);
        cout << "Chon: ";
        cin >> chon;
        gotoxy(l_uiFuns + 5, ++cursor + 3); //tránh trường hợp lỗi ghi đè lên khung
        gotoxy(l_uiFuns + 5, 19);
        switch (chon)
        {
        case 1:
            menu_dis();
            break;
        case 2:
            Edit_mem_inf();
            break;
        case 3:
            add_menu();
            break;
        case 4:
            search();
            break;
        case 5:
            delete_mem();
            break;
        case 6:
            sort();
            break;
        case 0:
            break;
        default:
            system("cls");
            getCol();
            cursor = 5;
            uiFunc(11);
            gotoxy(l_uiFuns + 50, 0);
            cout << "MENU" << endl;
            gotoxy(l_uiFuns + 5, ++cursor);
            SET_COLOR(4);
            cout << "Khong co chuc nang nay!" << endl;
            gotoxy(l_uiFuns + 5, ++cursor);
            system("pause");
            SET_COLOR(0);
        }
    } while (chon);
}
//list::edit
void list::Edit_mem_inf()
{
    //132
    int key, nCase = 12;
    bool ktKey;
    string mID;
    system("cls");
    getCol();
    uiFunc(11);
    gotoxy(l_uiFuns + 40, 0);
    cout << "SUA THONG TIN NHAN VIEN";
    gotoxy(l_uiFuns + 5, 6);
    cout << "Nhap ma nhan vien muon chinh sua: ";
    cin >> mID;
    uiFunc(18);
    int a[100];
    int k;
    k = search(1, mID, a);
    cursor = 0;
    if (k > 0) //123
    {
        do
        {
            do
            {
                system("cls");
                getCol();
                uiDisplay(20);
                gotoxy(l_uiDisplay + 60, 0);
                cout << "SUA THONG TIN NHAN VIEN";
                cursor = 5;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "Thong tin nhan vien dang sua:" << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << setw(6) << "Ma NV" << setw(17) << "|Ho" << setw(7) << "|Ten" << setw(6) << "|Ma DV" << setw(15) << "|So dien thoai" << setw(12)
                     << "|Ngay sinh" << setw(10) << "|Gioi tinh" << setw(10) << "|Chuc vu" << setw(13) << "|He so luong" << setw(9) << "|Nam vao"
                     << setw(10) << "|Trinh do" << setw(12) << "|Ngoai ngu" << endl
                     << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << list_mem[a[0]] << endl;
                ++cursor;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "Chon thong tin muon chinh sua!" << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "1. Ma nhan vien." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "2. Ho." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "3. Ten" << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "4. Ma don vi." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "5. So dien thoai." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "6. Ngay sinh." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "7. Gioi tinh." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "8. Ma chuc vu." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "9. He so luong." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "10. Nam vao cong ty." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "11. Trinh do." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "12. Ngoai ngu." << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "0. Exit!" << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                cout << "Chon: ";
                cin >> key;
                gotoxy(l_uiDisplay + 5, ++cursor + 5);

            } while (key < 0 && key > nCase);

            system("cls");
            getCol();
            uiDisplay(18);
            gotoxy(l_uiDisplay + 60, 0);
            cout << "SUA THONG TIN NHAN VIEN";
            cursor = 5;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << "Thong tin nhan vien dang sua:" << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << setw(6) << "Ma NV" << setw(17) << "|Ho" << setw(7) << "|Ten" << setw(6) << "|Ma DV" << setw(15) << "|So dien thoai" << setw(12)
                 << "|Ngay sinh" << setw(10) << "|Gioi tinh" << setw(10) << "|Chuc vu" << setw(13) << "|He so luong" << setw(9) << "|Nam vao"
                 << setw(10) << "|Trinh do" << setw(12) << "|Ngoai ngu" << endl
                 << endl;
            gotoxy(l_uiDisplay + 5, ++cursor);
            cout << list_mem[a[0]] << endl;
            ++cursor;
            switch (key)
            {
            case 1:
                list_mem[a[0]].setmID();
                break;
            case 2:
                list_mem[a[0]].setmlname();
                break;
            case 3:
                list_mem[a[0]].setfirstname();
                break;
            case 4:
                list_mem[a[0]].setgID();
                break;
            case 5:
                list_mem[a[0]].setpnumber();
                break;
            case 6:
                list_mem[a[0]].setns();
                break;
            case 7:
                list_mem[a[0]].setgender();
                break;
            case 8:
                list_mem[a[0]].setposition();
                break;
            case 9:
                list_mem[a[0]].setC_salary();
                break;
            case 10:
                list_mem[a[0]].setyear_in();
                break;
            case 11:
                list_mem[a[0]].setdegree();
                break;
            case 12:
                list_mem[a[0]].setL_certificate();
                break;
            case 0:
                break;
            default:
                system("cls");
                getCol();
                uiDisplay(11);
                gotoxy(l_uiDisplay + 60, 0);
                cout << "SUA THONG TIN NHAN VIEN";
                cursor = 5;
                gotoxy(l_uiDisplay + 5, ++cursor);
                SET_COLOR(4);
                cout << "Khong co tuy chon nay. Moi nhap lai!" << endl;
                gotoxy(l_uiDisplay + 5, ++cursor);
                system("pause");
                SET_COLOR(0);
                break;
            }
            if (key == 0)
            {
                break;
            }
            else
            {
                if (key > nCase)
                {
                    system("cls");
                    getCol();
                    uiDisplay(11);
                    gotoxy(l_uiDisplay + 60, 0);
                    cout << "SUA THONG TIN NHAN VIEN";
                    cursor = 5;
                    gotoxy(l_uiDisplay + 5, ++cursor);
                    SET_COLOR(4);
                    cout << "Khong co tuy chon nay. Moi nhap lai!" << endl;
                    gotoxy(l_uiDisplay + 5, ++cursor);
                    system("pause");
                    SET_COLOR(0);
                }
                else if (key < nCase)
                {
                    ofstream ofs;
                    writefile_mem(ofs, nhanvienouttxt);
                    system("cls");
                    getCol();
                    cursor = 5;
                    uiDisplay(18);
                    gotoxy(l_uiDisplay + 60, 0);
                    cout << "SUA THONG TIN NHAN VIEN";
                    gotoxy(l_uiDisplay + 5, ++cursor);
                    SET_COLOR(2);
                    cout << "Da sua xong!" << endl;
                    gotoxy(l_uiDisplay + 5, ++cursor);
                    system("pause");
                    SET_COLOR(0);
                }
            }

        } while (1);
    }
    else
    {
        cursor = 5;
        system("cls");
        getCol();
        uiFunc(11);
        gotoxy(l_uiFuns + 40, 0);
        cout << "SUA THONG TIN NHAN VIEN";
        gotoxy(l_uiFuns + 5, ++cursor);
        SET_COLOR(4);
        cout << "Khong co nhan vien nay!";
        gotoxy(l_uiFuns + 5, ++cursor);
        system("pause");
        SET_COLOR(0);
        gotoxy(l_uiFuns + 5, ++cursor + 20);
    }
}
