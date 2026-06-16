#ifndef HETHONGQUANLY_H
#define HETHONGQUANLY_H

#include <string>
#include "Entities.h"
#include "MangDong.h"

class HeThongQuanLy {
private:
    MangDong<SinhVien> dsSinhVien;
    MangDong<MonHoc> dsMonHoc;
    MangDong<LopHocPhan> dsLopHocPhan;
    MangDong<DiemSo> dsDiem;

    MonHoc* timMonHoc(std::string maMon);

public:
    void luuDanhSachSinhVien();
    void luuDanhSachMonHoc();
    void luuDanhSachDiem();
    void luuToanBoHeThong();

    void docDanhSachSinhVien();
    void docDanhSachMonHoc();
    void docDanhSachDiem();
    void taiToanBoHeThong();

    void khoiTaoDuLieuMau();
    void themSinhVien();
    void themMonHoc();
    void nhapCapNhatDiem();
    void inBangDiemSinhVien();
    void inBangDiemLopHocPhan();
    void hienThiDanhSachSinhVienXepTen();
};

// Khai báo các hàm logic nghiệp vụ tự do bên ngoài class
float quyDoiHe4(float diem10);
std::string xepLoaiHocLuc(float gpa4);
void sapXepSinhVienTheoTen(MangDong<SinhVien>& ds);

#endif