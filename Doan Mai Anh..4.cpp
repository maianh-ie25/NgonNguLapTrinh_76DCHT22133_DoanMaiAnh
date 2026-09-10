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
    // Hàm tao có doi
    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = mau;
    }
    // Ham huy
    ~PhanSo() {
    }
    // Tim UCLN
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
    // Rut gon phan so
    void rutGon() {
        int ucln = UCLN(tuSo, mauSo);
        if (ucln != 0) {
            tuSo /= ucln;
            mauSo /= ucln;
        }
        // Dua dau am lên tu so
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }
    // Cau 2: Nap chong toan tu nhap >>
    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu so: ";
        is >> ps.tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            is >> ps.mauSo;
        } while (ps.mauSo == 0);
        return is;
    }
    // Nap chong toan tu xuat <<
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.mauSo == 1)
            os << ps.tuSo;
        else
            os << ps.tuSo << "/" << ps.mauSo;
        return os;
    }
    // Câu 3: Nap chong toan tu cong
    PhanSo operator+(const PhanSo& ps) {
        PhanSo kq;

        kq.tuSo = tuSo * ps.mauSo + ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;

        kq.rutGon();
        return kq;
    }

    // Nap chong toan tu tru
    PhanSo operator-(const PhanSo& ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo - ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }
    // Nap chong toan tu nhan
    PhanSo operator*(const PhanSo& ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.tuSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }
    // Nap chong toan tu chia
    PhanSo operator/(const PhanSo& ps) {
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
    cin >> ps1;
    cout << "\nNhap phan so thu hai:\n";
    cin >> ps2;
    // Rut gon hai phân so ban dau
    ps1.rutGon();
    ps2.rutGon();
    cout << "\nPhan so thu nhat: " << ps1;
    cout << "\nPhan so thu hai: " << ps2;
    cout << "\n\nKet qua:";
    cout << "\nCong: " << ps1 + ps2;
    cout << "\nTru: " << ps1 - ps2;
    cout << "\nNhan: " << ps1 * ps2;
    cout << "\nChia: " << ps1 / ps2;
    cout << endl;
    return 0;
}

