#include<stdio.h>
#include<iostream>
using namespace std;

class nguoi{
    protected:
        string hoten;
        int nsinh;
    public:
        // ham tao k doi
        nguoi()
        { hoten=""; nsinh=0; }
        
        // ham tao co doi
        nguoi(string ht, int ns){
            hoten=ht;
            nsinh=ns;
        }

        void nhap(){
            cout<<"Nhap ho ten "; getline(cin,hoten);
            cout<<"Nhap nam sinh "; cin>>nsinh;
        }

        void xuat(){
            cout<<"Ho ten: "<<hoten<<" | Nam sinh: "<<nsinh;
        }
};

class SinhVien: public nguoi{
    private:
        string msv;
        float dtb;
    public:
        // ham tao k doi
        SinhVien():nguoi(){
        }

        // ham tao co doi (Sua kieu du lieu int ns)
        SinhVien(string ht, int ns, string ms, float dtb): nguoi(ht, ns){
            this->msv=ms;
            this->dtb=dtb;
        }

        void nhap(){
            nguoi::nhap();
            cin.ignore();
            cout<<"Nhap msv: "; getline(cin,msv);
            cout<<"Nhap dtb: "; cin>>dtb;
        }

        void xuat(){
            nguoi::xuat();
            cout<<" | Ma SV: "<<msv<<" | DTB: "<<dtb<<endl;
        }

        float getDTB(){
            return dtb;
        }
};

int main(){
    // khoi tao sv voi ham tao co doi
    SinhVien mai("Mai", 2007, "mn01", 8);
    cout<<"--- THONG TIN SINH VIEN KHOI TAO BAN DAU ---\n";
    mai.xuat();

    int n;
    cout<<"\nNhap so sinh vien: "; cin>>n;
    SinhVien a[100];

    // nhap danh sach sv
    for(int i=0; i<n; i++){
        cout<<"Nhap sinh vien thu "<<i+1<<":\n"; // Da sua loi cu phap \n
        a[i].nhap();
    }

    // sap xep giam dan theo dtb
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].getDTB() < a[j].getDTB()){
                SinhVien tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }

    cout<<"\n--- DANH SACH SAU KHI SAP XEP GIAM DAN ---\n";
    for(int i=0; i<n; i++){
        a[i].xuat();
    }

    return 0;
}
