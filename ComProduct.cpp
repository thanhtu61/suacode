#include "ComProduct.h"
ComProduct::ComProduct() :Product() {}
ComProduct::~ComProduct() {}

void ComProduct::setProcessor(string n) { Processor = n; }
string ComProduct::getProcessor() { return Processor; }
void ComProduct::displayp(Product* a) {
    cout << "ID:" << a->getproductId() << "   ";
    cout << "name:" << left << setw(25) << a->getName() << "   ";
    cout << "price:" << a->getPrice() << "   ";
    cout << "Processor:" << Processor << "   ";
}
void ComProduct::insert()
{
    cout << "ID:"; cin >> productId;
    cout << "Name:"; cin >> name;
    cout << "Price:";  cin >> price;
    cout << "Processor:";  cin >> Processor;
}
 ostream& operator<<(std::ostream& os, ComProduct* a) {
    os << "ID:" << a->getproductId() << "   ";
    os << "Name:" << left << setw(25) << a->getName() << "   ";
    os << "Price:" << a->getPrice() << "   ";
    os << "Processor:" << a->getProcessor() << "   ";
    return os;
}
 istream& operator >> (std::istream& is, ComProduct* a) {
    cout << "ID:"; is >> a->productId;
    cout << "Name:";	is >> a->name;
    cout << "Price:";  is >> a->price;
    cout << "Description:";  is >> a->Processor;
    return is;
}
void ComProduct::read_file_product(ifstream& filein) {
    getline(filein, productId, ',');
    filein.seekg(1, 1);
    getline(filein, name, ',');
    filein.seekg(1, 1);
    filein >> price;
    filein.seekg(2, 1);
    getline(filein, Processor, '\n');
}
void ComProduct::write_file_product() {
    ofstream fileout;
    fileout.open("Product.txt", ios::out | ios::app);
    fileout << productId << ", " << name << ", " << price << ", " << Processor;
    fileout << "\n";
    fileout.close();
}
