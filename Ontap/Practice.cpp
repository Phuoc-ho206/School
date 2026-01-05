#include <iostream>
using namespace std;


class Phanso {
private:
    int tuso;
    int mauso;
    Phanso *next;
    
public:
    Phanso();
    Phanso(int, int);
    virtual ~Phanso();

    int Gethead();
    void Sethead(int val);
    int Gettail();
    void Settail(int val);
    Phanso* Getnext();
    void Setnext(Phanso* val);

};

class Danhsach {
private:    
    Phanso *head;
    Phanso *tail;
    int size;
public:
    Danhsach();
    virtual ~Danhsach();

    Phanso* Gethead();
    void Sethead(Phanso* val);
    Phanso* Gettail();
    void Settail(Phanso* val);
    int Getsize();
    void Setsize(int val);
    void InDS();
    int Uocln(int a, int b);
    int Rutgon(Phanso* p);
};

Phanso::Phanso()
{
    tuso = 0;
    mauso = 1;
    next = nullptr;
}

Phanso::Phanso(int tuso, int mauso)
{
    this->tuso = tuso;
    this->mauso = mauso;
    next = nullptr;
}

Phanso::~Phanso()
{
    next = nullptr;
}

Phanso::Gethead()
{
    return tuso;
}
void Phanso::Sethead(int val) {
    tuso = val;
}
int Phanso::Gettail() {
    return mauso;
}
void Phanso::Settail(int val) {
    mauso = val;
}
Phanso* Phanso::Getnext() {
    return next;
}
void Phanso::Setnext(Phanso* val) {
    next = val;
}


Danhsach::Danhsach()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Danhsach::~Danhsach()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Phanso* Danhsach::Gethead() {
    return head;
}
void Danhsach::Sethead(Phanso* val) {
    head = val;
}
Phanso* Danhsach::Gettail() {
    return tail;
}
void Danhsach::Settail(Phanso* val) {
    tail = val;
}
int Danhsach::Getsize() {
    return size;
}
void Danhsach::Setsize(int val) {
    size = val;
}

void Danhsach::InDS(){
    Phanso *p = head;
    while(p != nullptr){
        cout << p->Gethead() << "/" << p->Gettail() << " ";
        p = p->Getnext();
    }
}

int Danhsach::Uocln(int a, int b){
    if (b == 0) return a;
    return Uocln(b, a % b);
}

int Danhsach::Rutgon(Phanso* p){
    int ucln = Uocln(p->Gethead(), p->Gettail());
    p->Sethead(p->Gethead() / ucln);
    p->Settail(p->Gettail() / ucln);
    return 0;
}

int main() {
    Danhsach ds;
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int tu, mau;
        cout << "Nhap phan so thu " << i + 1 <<" (tu so va mau so): ";
        cin >> tu >> mau;
        Phanso* p = new Phanso(tu, mau);
        ds.Rutgon(p);
        if(ds.Gethead() == nullptr){
            ds.Sethead(p);
            ds.Settail(p);
        } else {
            ds.Gettail()->Setnext(p);
            ds.Settail(p);
        }
        ds.Setsize(ds.Getsize() + 1);
    }
    
    cout << "Danh sach phan so sau khi rut gon: ";
    ds.InDS();
    return 0;
}