#include "LapProduct.h"
LapProduct::LapProduct() :Product() {}
LapProduct::~LapProduct() {}
void LapProduct::setBrand(string n) { Brand = n; }
string LapProduct::getBrand() { return Brand; }

void LapProduct::displayp(Product* a) {
    cout << "ID:" << a->getproductId() << "   ";
    cout << "name:" << left << setw(25) << a->getName() << "   ";
    cout << "price:" << a->getPrice() << "   ";
    cout << "Brand:" << Brand << "   ";
}
void LapProduct::insert()
{
    cout << "ID:"; cin >> productId;
    cout << "Name:"; cin >> name;
    cout << "Price:";  cin >> price;
    cout << "Brand:";  cin >> Brand;
}
 ostream& operator<<(std::ostream& os, LapProduct* a) {
    os << "ID:" << a->getproductId() << "   ";
    os << "Name:" << left << setw(25) << a->getName() << "   ";
    os << "Price:" << a->getPrice() << "   ";
    os << "Brand:" << a->getBrand() << "   ";
    return os;
}
istream& operator >> (std::istream& is, LapProduct* a) {
    cout << "ID:"; is >> a->productId;
    cout << "Name:";	is >> a->name;
    cout << "Price:";  is >> a->price;
    cout << "Brand:";  is >> a->Brand;
    return is;
}
void LapProduct::read_file_product(ifstream& filein) {
    getline(filein, productId, ',');
    filein.seekg(1, 1);
    getline(filein, name, ',');
    filein.seekg(1, 1);
    filein >> price;
    filein.seekg(2, 1);
    getline(filein, Brand, '\n');
}
void LapProduct::write_file_product() {
    ofstream fileout;
    fileout.open("Product.txt", ios::out | ios::app);
    fileout << productId << ", " << name << ", " << price << ", " << Brand;
    fileout << "\n";
    fileout.close();
}
