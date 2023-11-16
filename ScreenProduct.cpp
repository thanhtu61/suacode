#include "ScreenProduct.h"

ScreenProduct::ScreenProduct() :Product() {}
ScreenProduct::~ScreenProduct (){}
void ScreenProduct::setResolution(string n) { Resolution = n; }
string ScreenProduct::getResolution() { return Resolution; }

void ScreenProduct::displayp(Product* a) {
    cout << "ID:" << a->getproductId() << "   ";
    cout << "name:" << left << setw(25) << a->getName() << "   ";
    cout << "price:" << a->getPrice() << "   ";
    cout << "Resolution:" << Resolution << "   ";
}
void ScreenProduct::insert()
{
    cout << "ID:"; cin >> productId;
    cout << "Name:"; cin >> name;
    cout << "Price:";  cin >> price;
    cout << "Resolution:";  cin >> Resolution;
}
ostream& operator<<(std::ostream& os, ScreenProduct* a) {
    os << "ID:" << a->getproductId() << "   ";
    os << "Name:" << left << setw(25) << a->getName() << "   ";
    os << "Price:" << a->getPrice() << "   ";
    os << "Resolution:" << a->getResolution() << "   ";
    return os;
}
istream& operator >> (std::istream& is, ScreenProduct* a) {
    cout << "ID:"; is >> a->productId;
    cout << "Name:";	is >> a->name;
    cout << "Price:";  is >> a->price;
    cout << "Resolution:";  is >> a->Resolution;
    return is;
}
void ScreenProduct::read_file_product(ifstream& filein) {
    getline(filein, productId, ',');
    filein.seekg(1, 1);
    getline(filein, name, ',');
    filein.seekg(1, 1);
    filein >> price;
    filein.seekg(2, 1);
    getline(filein, Resolution, '\n');
}
void ScreenProduct::write_file_product() {
    ofstream fileout;
    fileout.open("Product.txt", ios::out | ios::app);
    fileout << productId << ", " << name << ", " << price << ", " << Resolution;
    fileout << "\n";
    fileout.close();
}
