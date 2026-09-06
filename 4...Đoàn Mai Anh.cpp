#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    // Cau 2: Phuong thuc nhap
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < 5; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }
    // Phuong thuc tính diem trung bình
    float tinhDiemTrungBinh() {
        float tong = 0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5;
    }
    // Phuong thuc xuat
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Diem 5 mon: ";
        for (int i = 0; i < 5; i++) {
            cout << diem[i] << " ";
        }
        cout << endl;
        cout << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
    }
    // Câu 3: In các môn phai thi lai
    void thiLai() {
        bool coThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                if (!coThiLai) {
                    cout << "Sinh vien: " << hoTen << endl;
                    cout << "Cac mon phai thi lai:" << endl;
                    coThiLai = true;
                }
                cout << "Mon " << i + 1
                     << " - Diem: " << diem[i] << endl;
            }
        }
    }
};
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    SinhVien ds[100];
    // Nhap danh sách sinh viên
    cout << "\n===== NHAP DANH SACH SINH VIEN =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }
    // Xuat danh sách sinh viên
    cout << "\n===== THONG TIN SINH VIEN =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        ds[i].xuat();
    }
    // In sinh viên phai thi lai
    cout << "\n===== SINH VIEN PHAI THI LAI =====\n";
    bool coSinhVienThiLai = false;
    for (int i = 0; i < n; i++) {
        // Kiem tra xem sinh viên có it nhat mot môn duoi 5 khong
        // bang cách tinh lai thong qua ham thiLai()
        ds[i].thiLai();
    }
    return 0;
}

