#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>

struct SinhVien {
    std::string mssv;
    std::string hoTen;
    std::string lop;
    std::string ngaySinh;
};

struct MonHoc {
    std::string maMon;
    std::string tenMon;
    int soTinChi;
};

struct LopHocPhan {
    std::string maLHP;
    std::string maMon;
    std::string tenLHP;
};

struct DiemSo {
    std::string mssv;
    std::string maMon;
    float diemHe10;
};

#endif