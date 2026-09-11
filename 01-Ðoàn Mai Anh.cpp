#include<stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

// Cau 1: Tim UCLN cua 2 so a, b
void cau1()
{
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;

    // Dung thuat toan Euclid de tim UCLN
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    cout << "UCLN = " << abs(a) << endl;
}

// Cau 2: T = 100 + 1/2^3 + 1/3^4 + ... + 1/n^(n+1)
void cau2()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    double T = 100;

    // i chay tu 2 den n vi so hang dau tien la 1/2^3
    for (int i = 2; i <= n; i++)
    {
        // 1.0 de phep chia cho ra so thuc
        T += 1.0 / pow(i, i + 1);
    }

    cout << "T = " << T << endl;
}

// Cau 3: T = 99 - 1/10 + 1/20 - ... + (-1)^n/(10*n)
void cau3()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    double T = 99;

    for (int i = 1; i <= n; i++)
    {
        // i le thi tru, i chan thi cong
        if (i % 2 != 0)
            T -= 1.0 / (10 * i);
        else
            T += 1.0 / (10 * i);
    }

    cout << "T = " << T << endl;
}

int main()
{
    int chon;

    do
    {
        cout << "\n1. Tim UCLN cua 2 so";
        cout << "\n2. Tinh tong T1";
        cout << "\n3. Tinh tong T2";
        cout << "\n0. Thoat";
        cout << "\nNhap lua chon: ";
        cin >> chon;

        switch (chon)
        {
            case 1:
                cau1();
                break;

            case 2:
                cau2();
                break;

            case 3:
                cau3();
                break;

            case 0:
                cout << "Thoat chuong trinh!";
                break;

            default:
                cout << "Lua chon khong hop le!";
        }

    } while (chon != 0);

    return 0;
}

