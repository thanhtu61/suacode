#include "OtherProduct.h"
OtherProduct::OtherProduct() :Product() {}
OtherProduct::~OtherProduct() {}

void OtherProduct::setDescription(string n) { Description = n; }
string OtherProduct::getDescription() { return Description; }

void OtherProduct::displayp(Product* a) {
    cout << "ID:" << a->getproductId() << "   ";
    cout << "name:" << left << setw(25) << a->getName() << "   ";
    cout << "price:" << a->getPrice() << "   ";
    cout << "Description:" << Description << "   ";
}

void OtherProduct::insert()
{
    cout << "ID:"; cin >> productId;
    cout << "Name:"; cin >> name;
    cout << "Price:";  cin >> price;
    cout << "Description:";  cin >> Description;
}
 ostream& operator<<(std::ostream& os, OtherProduct* a) {
    os << "ID:" << a->getproductId() << "   ";
    os << "Name:" << left << setw(25) << a->getName() << "   ";
    os << "Price:" << a->getPrice() << "   ";
    os << "Description:" << a->getDescription() << "   ";
    return os;
}
 istream& operator >> (std::istream& is, OtherProduct* a) {
    cout << "ID:"; is >> a->productId;
    cout << "Name:";	is >> a->name;
    cout << "Price:";  is >> a->price;
    cout << "Description:";  is >> a->Description;
    return is;
}
void OtherProduct::read_file_product(ifstream& filein) {
    getline(filein, productId, ',');
    filein.seekg(1, 1);
    getline(filein, name, ',');
    filein.seekg(1, 1);
    filein >> price;
    filein.seekg(2, 1);
    getline(filein, Description, '\n');
}
void OtherProduct::write_file_product() {
    ofstream fileout;
    fileout.open("Product.txt", ios::out | ios::app);
    fileout << productId << ", " << name << ", " << price << ", " << Description;
    fileout << "\n";
    fileout.close();
}