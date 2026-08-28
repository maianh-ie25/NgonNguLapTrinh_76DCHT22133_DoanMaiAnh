#include <stdio.h>
#include <iostream>
using namespace std;
// khai bao lop matran
class Matran {
private: // quyen truy xuat private cho thuc tinh
	// Cau1 khai bao cac thuoc tinh
	int soHang;// khai bao hang so nguyen
	int soCot;// khai bao cot so nguyen
	int a[100][100]; // mang 2 chieu chua cac phan tu ma tran
	
public:
	// cau 2 cac phuong thuc nhap, xuat
	void nhap() {
		cout << "Nhap so hang: ";
		cin >> soHang;
		
		cout << "Nhap so cot: ";
		cin >>  soCot;
		
		cout << "Nhap cac phan tu:\n";
		for (int i = 0; i < soHang; i++) {
			for (int j = 0; j < soCot; j++) {
				cout << "A[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
		}
	}
	// cau 2 phuong thuc xuat ma tran ra man hinh
	void xuat() {
		for (int i = 0; i < soHang; i++) {
			for (int j = 0; j < soCot; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl; // xuong dong khi het 1 hang
		}
	}
	// Cau 3 khai bao ham ban de cong 2 ma tran
	friend Matran tong(const Matran& m1, const Matran& m2);
};
// Cau 3 dinh nghia ham ban thuc hien cong 2 ma tran
Matran tong(const Matran& m1, const Matran& m2) {
	Matran ketQua; // tao doi tuong ma tran luu ket qua
	
	// vi 2 ma tran dong cap nen kich thuoc bang nhau
	ketQua.soHang = m1.soHang;
	ketQua.soCot = m1.soCot;
	
	// cong tung phan tu tuong ung qua 2 ma tran
	for (int i = 0; i < ketQua.soHang; i++) {
		for (int j = 0; j < ketQua.soCot; j++) {
			ketQua.a[i][j] = m1.a[i][j] + m2.a[i][j];
		}
	}
	return ketQua; // tra ve ma tran tong
}

int main() {
	Matran a, b, c;
	
	// nhap 2 ma tran dong cap
	cout << "=== NHAP MA TRAN 1 ===\n";
	a.nhap();
	
	cout << "=== NHAP MA TRAN 2 (CUNG KICH THUOC) ===\n";
	b.nhap();
	
	// thuc hien cong 2 ma tran bang ham ban
	c = tong(a, b);
	
	// in ra man hinh 2 ma tran ban dau va ma tran ket qua
	cout << "---------------------------------------\n";
	cout << "Ma tran 1 ban dau:\n";
	a.nhap();
	
	cout << "Ma tran 2 ban dau:\n";
	b.nhap();
	
	cout << "Ma tran ket qua:\n";
	c.xuat();
	
	return 0;
}

