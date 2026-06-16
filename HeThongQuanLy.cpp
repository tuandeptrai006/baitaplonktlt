#include "HeThongQuanLy.h"
#include <iostream>
#include <fstream>

using namespace std;

// =========================================================================
// LOGIC NGHIỆP VỤ LẺ
// =========================================================================

float quyDoiHe4(float diem10) {
    if (diem10 >= 8.5) return 4.0;
    if (diem10 >= 7.0) return 3.0;
    if (diem10 >= 5.5) return 2.0;
    if (diem10 >= 4.0) return 1.0;
    return 0.0;
}

string xepLoaiHocLuc(float gpa4) {
    if (gpa4 >= 3.6) return "Xuat sac";
    if (gpa4 >= 3.2) return "Gioi";
    if (gpa4 >= 2.5) return "Kha";
    if (gpa4 >= 2.0) return "Trung binh";
    return "Yeu";
}

void sapXepSinhVienTheoTen(MangDong<SinhVien>& ds) {
    int n = ds.getSize();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].hoTen > ds[j + 1].hoTen) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// =========================================================================
// TRIỂN KHAI CÁC PHƯƠNG THỨC CỦA CLASS HETHONGQUANLY
// =========================================================================

MonHoc* HeThongQuanLy::timMonHoc(string maMon) {
    for (int i = 0; i < dsMonHoc.getSize(); i++) {
        if (dsMonHoc[i].maMon == maMon) return &dsMonHoc[i];
    }
    return nullptr;
}

void HeThongQuanLy::luuDanhSachSinhVien() {
    ofstream outFile("sinhvien.txt");
    if (!outFile) return;
    for (int i = 0; i < dsSinhVien.getSize(); i++) {
        outFile << dsSinhVien[i].mssv << "|" << dsSinhVien[i].hoTen << "|"
                << dsSinhVien[i].lop << "|" << dsSinhVien[i].ngaySinh << "\n";
    }
    outFile.close();
}

void HeThongQuanLy::luuDanhSachMonHoc() {
    ofstream outFile("monhoc.txt");
    if (!outFile) return;
    for (int i = 0; i < dsMonHoc.getSize(); i++) {
        outFile << dsMonHoc[i].maMon << "|" << dsMonHoc[i].tenMon << "|"
                << dsMonHoc[i].soTinChi << "\n";
    }
    outFile.close();
}

void HeThongQuanLy::luuDanhSachDiem() {
    ofstream outFile("diemso.txt");
    if (!outFile) return;
    for (int i = 0; i < dsDiem.getSize(); i++) {
        outFile << dsDiem[i].mssv << "|" << dsDiem[i].maMon << "|"
                << dsDiem[i].diemHe10 << "\n";
    }
    outFile.close();
}

void HeThongQuanLy::luuToanBoHeThong() {
    luuDanhSachSinhVien();
    luuDanhSachMonHoc();
    luuDanhSachDiem();
}

void HeThongQuanLy::docDanhSachSinhVien() {
    ifstream inFile("sinhvien.txt");
    if (!inFile) return;
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        SinhVien sv;
        string bff[4]; int idx = 0; string token = "";
        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == '|') { bff[idx++] = token; token = ""; }
            else token += line[i];
        }
        bff[idx] = token;
        sv.mssv = bff[0]; sv.hoTen = bff[1]; sv.lop = bff[2]; sv.ngaySinh = bff[3];
        dsSinhVien.push_back(sv);
    }
    inFile.close();
}

void HeThongQuanLy::docDanhSachMonHoc() {
    ifstream inFile("monhoc.txt");
    if (!inFile) return;
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        MonHoc mh;
        string bff[3]; int idx = 0; string token = "";
        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == '|') { bff[idx++] = token; token = ""; }
            else token += line[i];
        }
        bff[idx] = token;
        mh.maMon = bff[0]; mh.tenMon = bff[1]; mh.soTinChi = stoi(bff[2]);
        dsMonHoc.push_back(mh);
    }
    inFile.close();
}

void HeThongQuanLy::docDanhSachDiem() {
    ifstream inFile("diemso.txt");
    if (!inFile) return;
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        DiemSo ds;
        string bff[3]; int idx = 0; string token = "";
        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == '|') { bff[idx++] = token; token = ""; }
            else token += line[i];
        }
        bff[idx] = token;
        ds.mssv = bff[0]; ds.maMon = bff[1]; ds.diemHe10 = stof(bff[2]);
        dsDiem.push_back(ds);
    }
    inFile.close();
}

void HeThongQuanLy::taiToanBoHeThong() {
    docDanhSachSinhVien();
    docDanhSachMonHoc();
    docDanhSachDiem();
}

void HeThongQuanLy::khoiTaoDuLieuMau() {
    if (dsSinhVien.getSize() == 0) { // Chỉ nạp nếu mảng rỗng dữ liệu file
        dsSinhVien.push_back({"SV01", "Nguyen Van A", "IT1", "2005-01-01"});
        dsSinhVien.push_back({"SV02", "Tran Thi B", "IT2", "2005-05-12"});
        dsSinhVien.push_back({"SV03", "tuandeptrai", "IT3", "2006-05-02"});
        dsDiem.push_back({"SV01", "IT3011", 9});
        dsDiem.push_back({"SV02", "IT3011", 9});
        dsMonHoc.push_back({"IT3011", "Cau truc du lieu", 3});
        dsMonHoc.push_back({"IT3020", "He dieu hanh", 3});
        dsLopHocPhan.push_back({"LHP01", "IT3011", "LHP Cau truc du lieu 01"});
        dsLopHocPhan.push_back({"LHP02", "IT3020", "LHP He dieu hanh"});
    }
}

void HeThongQuanLy::themSinhVien() {
    SinhVien sv;
    cout << "Nhap MSSV: "; cin >> sv.mssv;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, sv.hoTen);
    cout << "Nhap lop: "; cin >> sv.lop;
    cout << "Nhap ngay sinh (yyyy-mm-dd): "; cin >> sv.ngaySinh;
    dsSinhVien.push_back(sv);
    cout << "-> Them sinh vien thanh cong!\n";
}

void HeThongQuanLy::themMonHoc() {
    MonHoc mh;
    cout << "Nhap ma mon hoc: "; cin >> mh.maMon;
    cin.ignore();
    cout << "Nhap ten mon hoc: "; getline(cin, mh.tenMon);
    cout << "Nhap so tin chi: "; cin >> mh.soTinChi;
    dsMonHoc.push_back(mh);
    cout << "-> Them mon hoc thanh cong!\n";
}

void HeThongQuanLy::nhapCapNhatDiem() {
    string mssv, maMon;
    float diem10;
    cout << "Nhap MSSV: "; cin >> mssv;
    cout << "Nhap ma mon hoc: "; cin >> maMon;
    cout << "Nhap diem he 10: "; cin >> diem10;

    if (diem10 < 0 || diem10 > 10) {
        cout << "-> Diem khong hop le!\n";
        return;
    }

    for (int i = 0; i < dsDiem.getSize(); i++) {
        if (dsDiem[i].mssv == mssv && dsDiem[i].maMon == maMon) {
            dsDiem[i].diemHe10 = diem10;
            cout << "-> Cap nhat diem thanh cong!\n";
            return;
        }
    }

    dsDiem.push_back({mssv, maMon, diem10});
    cout << "-> Nhap diem moi thanh cong!\n";
}

void HeThongQuanLy::inBangDiemSinhVien() {
    string mssv;
    cout << "Nhap MSSV can xem bang diem: "; cin >> mssv;

    int svIdx = -1;
    for (int i = 0; i < dsSinhVien.getSize(); i++) {
        if (dsSinhVien[i].mssv == mssv) {
            svIdx = i;
            break;
        }
    }

    if (svIdx == -1) {
        cout << "-> Khong tim thay sinh vien co MSSV nay!\n";
        return;
    }

    cout << "\n================ BANG DIEM SINH VIEN ================\n";
    cout << "MSSV: " << dsSinhVien[svIdx].mssv << " | Ho ten: " << dsSinhVien[svIdx].hoTen << "\n";
    cout << "Lop: " << dsSinhVien[svIdx].lop << "\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Ma Mon\t\tTen Mon\t\t\tTin Chi\tDiem 10\tDiem 4\n";

    float tongDiem10 = 0, tongDiem4 = 0;
    int tongTinChi = 0;

    for (int i = 0; i < dsDiem.getSize(); i++) {
        if (dsDiem[i].mssv == mssv) {
            MonHoc* mh = timMonHoc(dsDiem[i].maMon);
            if (mh != nullptr) {
                float d4 = quyDoiHe4(dsDiem[i].diemHe10);
                cout << dsDiem[i].maMon << "\t\t" << mh->tenMon << "\t\t"
                     << mh->soTinChi << "\t" << dsDiem[i].diemHe10 << "\t" << d4 << "\n";

                tongDiem10 += dsDiem[i].diemHe10 * mh->soTinChi;
                tongDiem4 += d4 * mh->soTinChi;
                tongTinChi += mh->soTinChi;
            }
        }
    }

    cout << "-----------------------------------------------------------\n";
    if (tongTinChi > 0) {
        float gpa10 = tongDiem10 / tongTinChi;
        float gpa4 = tongDiem4 / tongTinChi;
        cout << "GPA (He 10): " << gpa10 << "\n";
        cout << "GPA (He 4) : " << gpa4 << "\n";
        cout << "Xep loai   : " << xepLoaiHocLuc(gpa4) << "\n";
    } else {
        cout << "Sinh vien nay chua co dau diem nao!\n";
    }
    cout << "=====================================================\n";
}

void HeThongQuanLy::inBangDiemLopHocPhan() {
    string maMon;
    cout << "Nhap ma mon hoc de xem diem ca lop: "; cin >> maMon;

    MonHoc* mh = timMonHoc(maMon);
    if (mh == nullptr) {
        cout << "-> Mon hoc khong ton tai!\n";
        return;
    }

    cout << "\n=========== BANG DIEM MON HOC: " << mh->tenMon << " ===========\n";
    cout << "MSSV\t\tHo Ten\t\t\tDiem He 10\tDiem He 4\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < dsDiem.getSize(); i++) {
        if (dsDiem[i].maMon == maMon) {
            string tenSV = "An danh";
            for (int j = 0; j < dsSinhVien.getSize(); j++) {
                if (dsSinhVien[j].mssv == dsDiem[i].mssv) {
                    tenSV = dsSinhVien[j].hoTen;
                    break;
                }
            }
            cout << dsDiem[i].mssv << "\t\t" << tenSV << "\t\t"
                 << dsDiem[i].diemHe10 << "\t\t" << quyDoiHe4(dsDiem[i].diemHe10) << "\n";
        }
    }
    cout << "=============================================================\n";
}

void HeThongQuanLy::hienThiDanhSachSinhVienXepTen() {
    sapXepSinhVienTheoTen(dsSinhVien);
    cout << "\n======= DANH SACH SINH VIEN(SAP XEP THEO TEN) =======\n";
    for (int i = 0; i < dsSinhVien.getSize(); i++) {
        cout << dsSinhVien[i].mssv << " - " << dsSinhVien[i].hoTen << " - " << dsSinhVien[i].lop << "\n";
    }
}