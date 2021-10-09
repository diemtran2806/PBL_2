#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<iostream>
using namespace std;

class NhanVien{
private:
    string maNhanVien;
    string ho;
    string ten;
    string soDienThoai;
    string ngaySinh;
    string gioiTinh;
    string maDonVi;
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
};
#endif