#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iomanip>
#include "function.h"
#include "member.h"
#include "group.h"
#include "Position.h"
using namespace std;
#define nhanvientxt "Nhan Vien.txt"
#define nhanvienouttxt "Nhan Vien_out.txt"
#define nhanviensearch "NhanVien_search.txt"

class list
{
private:
    int numofMem; //số lượng nhân viên
    int numofGr;  //số lượng đơn vị
    int numofP;   //số lượng chức vụ
    int ml, fl, mh, fh, mm, fm, mt, ft, ma, fa, mp, fp;
    member *list_mem;
    group *list_gr;
    Position *list_p;

public:
    list(int = 0, int = 0, int = 0);
    list(const list &);
    ~list();

    void readfile_mem(ifstream &in); //nhap danh sach nhan vien tu file
    void readfile_gr(ifstream &in);  //nhap danh sach don vi tu file
    void readfile_p(ifstream &in);   //Nhap danh sach chuc vu
    void writefile_mem(ofstream &ofs, string txt);

    void display_mem(); //in danh sach nhan vien
    void count_gender(int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);
    void display_gr(); //in bang thong ke theo don vi
    void display_p();  //in bang thong ke cac chuc vu
    void menu_dis();

    int check(member &);
    void add(member &, int k, string txt); //bo sung 1 doi tuong vao vi tri k bat ki
    void add_menu();

    void sort();                                                   //sap xep danh sach nhan vien theo thu tu tang/giam -> hàm chính
    void sort(bool CompFunc(const member &, const member &, int)); //hàm phụ
    void QuickSort(int l, int r, int key, bool CompFunc(const member &, const member &, int));
    void menu_Sort(int &);

    int search(int, string, int a[100]); //ham tim kiem 1 nhan vien
    void search();                       //tim kiem nhan vien tu ten, gioi tinh...
    int menu_Search(string &);

    //xoa
    void delete_mem(member &);    //xoa 1 nhan vien bat ki
    void delete_mem();            //main
    void delete_mem_age(int);     //xoa theo tuoi///////////
    void delete_mem_name_id(int); //xóa theo tên or id

    //tính tổng lương, tổng thực lĩnh
    void getSumOfSalary(int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);

    member &operator[](int i) const; //toan tu lay phan tu thu i [] trong danh sach nhan vien
    const list &operator=(const list &);
    friend ostream &operator<<(ostream &out, const list &);
    //sửa thông tin nhân viên
    void Edit_mem_inf();
    //menu main
    void menu();
};

#endif