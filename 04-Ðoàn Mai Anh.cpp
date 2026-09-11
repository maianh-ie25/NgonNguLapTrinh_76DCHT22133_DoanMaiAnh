#include<stdio.h>
#include <iostream>
using namespace std;

class SoPhuc
{
private:
    double thuc, ao; // Phan thuc, phan ao

public:
    // Ham tao khong doi
    SoPhuc()
    {
        thuc = 0;
        ao = 0;
    }

    // Ham tao co doi
    SoPhuc(double t, double a)
    {
        thuc = t;
        ao = a;
    }

    // Ham huy
    ~SoPhuc()
    {
    }

    // Toan tu nhap
    friend istream& operator>>(istream& in, SoPhuc& z)
    {
        in >> z.thuc >> z.ao;
        return in;
    }

    // Toan tu xuat
    friend ostream& operator<<(ostream& out, const SoPhuc& z)
    {
        out << z.thuc;

        if (z.ao >= 0)
            out << "+" << z.ao << "i";
        else
            out << z.ao << "i";

        return out;
    }

    // Cong
    // (a+bi) + (c+di) = (a+c) + (b+d)i
    SoPhuc operator+(const SoPhuc& z)
    {
        return SoPhuc(thuc + z.thuc, ao + z.ao);
    }

    // Tru
    // (a+bi) - (c+di) = (a-c) + (b-d)i
    SoPhuc operator-(const SoPhuc& z)
    {
        return SoPhuc(thuc - z.thuc, ao - z.ao);
    }

    // Nhan
    // (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    SoPhuc operator*(const SoPhuc& z)
    {
        double t = thuc * z.thuc - ao * z.ao;
        double a = thuc * z.ao + ao * z.thuc;

        return SoPhuc(t, a);
    }

    // Chia
    // (a+bi)/(c+di)
    // = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
    SoPhuc operator/(const SoPhuc& z)
    {
        double mau = z.thuc * z.thuc + z.ao * z.ao;

        if (mau == 0)
        {
            cout << "Khong the chia cho 0!" << endl;
            return SoPhuc();
        }

        double t = (thuc * z.thuc + ao * z.ao) / mau;
        double a = (ao * z.thuc - thuc * z.ao) / mau;

        return SoPhuc(t, a);
    }
};

int main()
{
    SoPhuc z1, z2;

    cout << "Nhap z1: ";
    cin >> z1;

    cout << "Nhap z2: ";
    cin >> z2;

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cout << "z1 + z2 = " << z1 + z2 << endl;
    cout << "z1 - z2 = " << z1 - z2 << endl;
    cout << "z1 * z2 = " << z1 * z2 << endl;
    cout << "z1 / z2 = " << z1 / z2 << endl;

    return 0;
}

