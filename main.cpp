#include <iostream>
#include "HeThongQuanLy.h"

using namespace std;

int main() {
    HeThongQuanLy ql;
    ql.taiToanBoHeThong();   // Nạp dữ liệu cũ từ file
    ql.khoiTaoDuLieuMau();   // Nạp thêm data mẫu nếu file rỗng

    int luaChon;
    do {
        cout << "\n----- CHUONG TRINH QUAN LY SINH VIEN & DIEM SO -----\n";
        cout << "1. Them sinh vien moi\n";
        cout << "2. Them mon hoc moi\n";
        cout << "3. Nhap/Cap nhat diem cho sinh vien\n";
        cout << "4. Tim kiem & In bang diem cua 1 sinh vien (Tinh GPA + Xep loai)\n";
        cout << "5. In bang diem cua lop hoc phan (Theo ma mon)\n";
        cout << "6. In toan bo sinh vien (Da sap xep theo Ten)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: 
                ql.themSinhVien(); 
                ql.luuDanhSachSinhVien(); 
                break;
            case 2: 
                ql.themMonHoc(); 
                ql.luuDanhSachMonHoc();
                break;
            case 3: 
                ql.nhapCapNhatDiem(); 
                ql.luuDanhSachDiem();
                break;
            case 4: 
                ql.inBangDiemSinhVien(); 
                break;
            case 5: 
                ql.inBangDiemLopHocPhan(); 
                break;
            case 6: 
                ql.hienThiDanhSachSinhVienXepTen(); 
                break;
            case 0:
                ql.luuToanBoHeThong();
                cout << "He thong da luu trang thai an toan\n";
                break;
            default: 
                cout << "Lua chon sai! Vui long nhap lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}