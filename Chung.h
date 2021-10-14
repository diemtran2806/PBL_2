#include<iostream>
using namespace std;

#ifndef CHUNG_H
#define CHUNG_H

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
#endif