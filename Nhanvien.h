#include<iostream>
#include "Chung.h"
using namespace std;

#ifndef NHANVIEN_H
#define NHANVIEN_H

class NhanVien{
private:
    string maNhanVien;
    string soDienThoai;
    string ngaySinh;
    bool gioiTinh;
    string chucVu;
    double heSoLuong;
    double luong;
    double phuCap;
    double thucLinh;
    int namVao;
    int soNamLamViec;
    string trinhDo;
    string ngoaiNgu;
public:
    NhanVien();
    int tinhLuong(); //tinh luong    
    friend istream &operator >>(istream &in,NhanVien &);
    friend ostream &operator <<(ostream &out,const NhanVien &);
    friend bool operator <(const NhanVien &, const NhanVien &);
    friend bool operator >(const NhanVien &, const NhanVien &);
};
#endif