#include <iostream>
using namespace std;

class Chung{
private:
    string ho;
    string ten;
    string maDonVi;
public:
    Chung();
    friend class NhanVien;
    friend class DonVi;    
};

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

class DonVi{
private:
    string tenDonVi;
    int soLuongNam;
    int soLuongNu;
public:
    DonVi();
};

class DanhSach{
private:
    int soLuong_NV;
    int soLuong_DV;
    NhanVien *danhSach_NV;
    DonVi *danhSach_DV;
public:
    DanhSach(int, int);
    DanhSach(const DanhSach&);
    void nhapFile_NV(FILE *fi);                     //nhap danh sach nhan vien tu file 
    void nhapFile_DV(FILE *fi);                     //nhap danh sach don vi tu file
    void in_NV();                                   //in danh sach nhan vien
    void in_DV();                                   //in bang thong ke theo don vi
    void boSung(NhanVien&, int k);                  //bo sung 1 doi tuong vao vi tri k bat ki
    void sapXep(bool CompFunc(NhanVien&, NhanVien&));//sap xep danh sach nhan vien theo thu tu tang/giam
    NhanVien timkiem(NhanVien&);                    //tim kiem 1 nhan vien
    void xoa(NhanVien&);                            //xoa 1 nhan vien bat ki
    NhanVien &operator [](int i) const;             //toan tu lay phan tu thu i [] trong danh sach nhan vien
};

int main(){
    return 0;
}