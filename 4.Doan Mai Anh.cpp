#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class NhanVien
{
private:
    string maNV;
    string hoTen;
    int tuoi;
    double luong;
public:
    // Constructor khong doi
    NhanVien()
    {
        maNV = "";
        hoTen = "";
        tuoi = 0;
        luong = 0;
    }
    // Constructor co doi
    NhanVien(string ma, string ten, int t, double l)
    {
        maNV = ma;
        hoTen = ten;
        tuoi = t;
        luong = l;
    }
    void xuat()
    {
        cout << left
             << setw(15) << maNV
             << setw(25) << hoTen
             << setw(10) << tuoi
             << setw(15) << luong << endl;
    }
};
int main()
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    vector<NhanVien> dsnv;
    for (int i = 0; i < n; i++)
    {
        string ma, ten;
        int tuoi;
        double luong;
        cout << "\n=== NHAP NHAN VIEN " << i + 1 << " ===" << endl;
        cout << "Nhap ma nhan vien: ";
        cin >> ma;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap luong: ";
        cin >> luong;
        // Dung constructor co doi
        NhanVien nv(ma, ten, tuoi, luong);
        // Dua nhan vien vao mang
        dsnv.push_back(nv);
    }
    cout << "\n========== DANH SACH NHAN VIEN ==========\n";
    cout << left
         << setw(15) << "Ma NV"
         << setw(25) << "Ho Ten"
         << setw(10) << "Tuoi"
         << setw(15) << "Luong" << endl;
    for (int i = 0; i < dsnv.size(); i++)
    {
        dsnv[i].xuat();
    }
    return 0;
}
