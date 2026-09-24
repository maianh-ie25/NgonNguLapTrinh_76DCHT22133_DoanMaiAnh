#include<iostream> // Thu vien nhap xuat du lieu chuan (cout, cin)
#include<cmath>    // Thu vien toan hoc de dung ham tinh can bac hai sqrt() va abs()
using namespace std; // Su dung khong gian ten chuan de khong can gdt cout, cin voi std::

// Cau 1: Khai bao lop SP1 cho doi tuong so phuc
class SP1{
    protected:
        float thuc; // Thuoc tinh phan thuc, dung protected de lop con SP2 co the truy cap
        float ao;   // Thuoc tinh phan ao, dung float de luu duoc so thuc

    public:
        // Ham tao khong tham so: khoi tao gia tri mac dinh 0 cho phan thuc va ao khi tao doi tuong
        SP1(){
            thuc = 0;
            ao = 0;
        }

        // Ham tao co tham so: cho phep khoi tao gia tri tuy chon ban dau cho so phuc
        SP1(float t, float a){
            thuc = t;
            ao = a;
        }

        // Phuong thuc nhap du lieu tu ban phim cho phan thuc va phan ao
        void nhap(){
            cout<<"Nhap phan thuc: "; cin>>thuc;
            cout<<"Nhap phan ao: "; cin>>ao;
        }

        // Phuong thuc tinh module cua so phuc theo cong thuc: sqrt(thuc^2 + ao^2)
        float module(){
            return sqrt(thuc*thuc + ao*ao); // sqrt() la ham tinh can bac hai trong cmath
        }

        // Phuong thuc in so phuc ra man hinh duoi dang: a + bi (module: x)
        void in(){
            if (ao >= 0)
                cout<<thuc<<" + "<<ao<<"i"; // In dau + neu phan ao la so duong
            else
                cout<<thuc<<" - "<<abs(ao)<<"i"; // In dau - va lay gia tri tuyet doi neu ao am
            cout<<" (module: "<<module()<<")"; // Goi ham module() de in gia tri module kem theo
        }
};

// Cau 2: Lop SP2 ke thua cong khai (public) tu lop SP1
class SP2 : public SP1
{
    public:
        // Nap chong toan tu gan (=): gán phan thuc va phan ao cua doi tuong a cho doi tuong hien tai
        SP2& operator= (const SP2 &a){
            thuc = a.thuc; // Gan phan thuc
            ao = a.ao;     // Gan phan ao
            return *this;  // Tra ve con tro this de ho tro phep gan lien tiep (vd: x = y = z)
        }

        // Nap chong toan tu so sanh lon hon (>): so sanh hai so phuc dua tren gia tri module
        bool operator >(SP2 a){
            return this->module() > a.module(); // Tra ve true neu module so hien tai > module so a
        }
};

// Cau 3: Chuong trinh chinh xu ly danh sach so phuc
int main()
{
    SP2 a[10]; // Khai bao mang a chua toi da 10 doi tuong so phuc thuoc lop SP2
    int n;     // Bien luu so luong so phuc thuc te do nguoi dung nhap

    // Vong lap do-while: bat nguoi dung nhap n va kiem tra dieu kien 1 <= n <= 10
    do {
        cout<<"Nhap so luong so phuc (1-10): ";
        cin>>n;
    } while (n < 1 || n > 10); // Neu nhap n ngoai khoang 1-10 thi bat nhap lai

    cout<<"\n--- NHAP DANH SACH SO PHUC ---\n";
    // Vong lap nhap tung so phuc trong danh sach
    for (int i = 0; i < n; i++) {
        cout<<"\nSo phuc thu "<<i + 1<<":\n";
        a[i].nhap(); // Goi phuong thuc nhap() cua phan tu a[i]
    }

    cout<<"\nDanh sach vua nhap:\n";
    // Vong lap in danh sach so phuc ban dau
    for (int i = 0; i < n; i++) {
        a[i].in(); // Goi phuong thuc in() de hien thi so phuc va module
        cout<<"\n";
    }

    // Thuat toan sap xep doi cho truc tiep (Exchange Sort) de sap xep giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) { // Su dung toan tu > da nap chong de so sanh 2 module
                SP2 tam = a[i]; // Bien tam thuoc kieu SP2 lam trung gian de hoan vi a[i] va a[j]
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    cout<<"\nDanh sach sau khi sap xep giam dan theo module:\n";
    // Vong lap in k?t qua danh sach sau khi da sap xep
    for (int i = 0; i < n; i++) {
        a[i].in();
        cout<<"\n";
    }
    cout<<endl;

    return 0; // Tra ve 0 de bao chuong trinh chay thanh cong va ket thuc
}
