#include<iostream>
#include<cstdlib>
using namespace std;

// Cau 1: Khai bao lop PS1
class PS1{
    protected:
        int ts;
        int ms;
    public:
        void nhap(){
            cout<<"Nhap ts: "; cin>>ts;
            do{
                cout<<"Nhap ms (khac 0): "; cin>>ms;
            }while (ms==0);
        }
        
        // toi gian
        void toigian(){
            //tim ucln cua ts va ms
            int a=abs(ts), b=abs(ms);
            //thuat toan oclid
            while (b!=0) //(a,b)=(b,r)
            {
                int r=a%b; // tim phan su a chia b
                a=b;
                b=r;
            }
            int uc=a; //ucln=a+b; vi b=0 nen ucln=a
            if (uc != 0) {
                ts=ts/uc;
                ms=ms/uc;
            }
        }

        void in(){ // 1/2, 1/-2 => -1/2
            toigian();
            if (ms<0) {
                ts=-ts;
                ms=-ms;
            }
            if (ms==1)
                cout<<ts;
            else
                cout<<ts<<"/"<<ms;
        }
};

// Cau 2: Lop PS2 ke thua tu PS1
class PS2 : public PS1
{
    public:
        //nap chong toan tu =
        // cach 1; La phuong thuc Lop
        PS2& operator= (const PS2 &a){
            //this =a;
            ts=a.ts;
            ms=a.ms;
            return *this;
        }

        // nap chong toan tu >, ktra this>a: ts/ms >a.ts/a.ms
        // 1/2 va 1/3
        bool operator >(const PS2 &a){
            return ts*a.ms > ms*a.ts ; // 1*3>1*2 => true,
            // 1/3 va 1/2 => 1*2 > 1*3 => sai
        }
        //return float(ts)/ms>float (a.ts)/a.ms; => cach 2
};

// Cau 3: Chuong trinh chinh
int main()
{
    PS2 a[10]; // Danh sach toi da 10 phan so
    int n;

    do {
        cout<<"Nhap so luong phan so (1-10): ";
        cin>>n;
    } while (n < 1 || n > 10);

    cout<<"--- NHAP DANH SACH PHAN SO ---\n";
    for (int i = 0; i < n; i++) {
        cout<<"\nPhan so thu "<<i + 1<<":\n";
        a[i].nhap();
        a[i].toigian();
    }

    cout<<"Danh sach vua nhap:\n";
    for (int i = 0; i < n; i++) {
        a[i].in();
        cout<<"   ";
    }

    // Sap xep giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                PS2 tam = a[i]; //tam= tamthoi
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    cout<<"Danh sach sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; i++) {
        a[i].in();
        cout<<"   ";
    }
    cout<<endl;

    return 0;
}
