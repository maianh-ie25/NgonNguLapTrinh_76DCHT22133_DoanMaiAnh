#include <iostream>
#include <cmath>
using namespace std;
class PhanSo {
private:
    int tuSo;
    int mauSo;
public:
    // Câu 1: Ham tao không doi
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }
    // Ham tao có doi
    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = mau;
    }
    // Ham huy
    ~PhanSo() {
    }
    // Câu 2: Nhap phân so
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
        } while (mauSo == 0);
    }
    // Xuat phân so
    void xuat() {
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
        if (mauSo == 1)
            cout << tuSo;
        else
            cout << tuSo << "/" << mauSo;
    }
    // Tìm UCLN
    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    // Rut gon phân so
    void rutGon() {
        int ucln = UCLN(tuSo, mauSo);
        if (ucln != 0) {
            tuSo /= ucln;
            mauSo /= ucln;
        }
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }
    // Cong hai phân so
    PhanSo cong(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo + ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }
    // Tru hai phân so
    PhanSo tru(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo - ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }
    // Nhan hai phân so
    PhanSo nhan(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.tuSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }
    // Chia hai phân so
    PhanSo chia(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo;
        kq.mauSo = mauSo * ps.tuSo;
        kq.rutGon();
        return kq;
    }
};
int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();
    cout << "\nNhap phan so thu hai:\n";
    ps2.nhap();
    ps1.rutGon();
    ps2.rutGon();
    cout << "\nPhan so thu nhat: ";
    ps1.xuat();
    cout << "\nPhan so thu hai: ";
    ps2.xuat();
    PhanSo kq;
    cout << "\n\nCong: ";
    kq = ps1.cong(ps2);
    kq.xuat();
    cout << "\nTru: ";
    kq = ps1.tru(ps2);
    kq.xuat();
    cout << "\nNhan: ";
    kq = ps1.nhan(ps2);
    kq.xuat();
    cout << "\nChia: ";
    kq = ps1.chia(ps2);
    kq.xuat();
    cout << endl;
    return 0;
}


