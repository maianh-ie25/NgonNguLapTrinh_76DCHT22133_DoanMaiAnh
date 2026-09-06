#include <iostream>
#include <string>
using namespace std
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];
public:
    // Phuong thuc nhap
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem 4 mon:\n";
        for (int i = 0; i < 4; i++) {
            cout << "Mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }
    // Tinh diem trung binh
    float diemTrungBinh() {
        float tong = 0;
        for (int i = 0; i < 4; i++) {
            tong += diem[i];
        }
        return tong / 4;
    }
    // Kiem tra co mon nao duoi 5
    bool khong co mon duoi 5() {
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5)
                return false;
        }
        return true;
    }
    // Kiem tra sinh vien thi tot nghiep
    bool thiTotNghiep() {
        return diemTrungBinh() > 7 && khong co mon duoi 5();
    }
    // Xuat thong tin
    void xuat() {
        cout << "\nHo ten: " << hoTen;
        cout << "\nNam sinh: " << namSinh;
        cout << "\nDiem 4 mon: ";
        for (int i = 0; i < 4; i++) {
            cout << diem[i] << " ";
        }
        cout << "\nDiem trung binh: " << diemTrungBinh();
    }
};
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien ds[n];
    // Nhap danh sach
    for (int i = 0; i < n; i++) {
        cout << "\n===== SINH VIEN " << i + 1 << " =====\n";
        ds[i].nhap();
    }
    // In sinh vien thi tot nghiep
    cout << "\n\n===== SINH VIEN THI TOT NGHIEP =====\n";
    bool co = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].thiTotNghiep()) {
            co = true;
            cout << "\n-------------------------";
            ds[i].xuat();
            cout << endl;
        }
    }
    if (!co) {
        cout << "Khong co sinh vien nao thi tot nghiep.\n";
    }
    return 0;
}

