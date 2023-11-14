#include "Product.h"
   

    string Product:: getproductId() { return  productId; }
    string Product::getName() { return  name; }
    double Product::getPrice() { return price; }

    void Product::setName(string n) { name = n; }
    void Product::setPrice(double n) { price = n; }
   /* void displayp(Product* a) {
        cout << "ID:" << a->getproductId() << "   ";
        cout << "name:" << left << setw(25) <<a->getName() << "   ";
        cout << "price:" << a->getPrice() << "   ";
    }*/
    ostream& operator<<(std::ostream& os, Product* a) {
        os  << "ID:" << a->getproductId() << "   ";
        os << "name:" << left << setw(25) << a->getName() << "   ";
        os << "price:" << a->getPrice() << "   ";
        return os;
    }
    istream& operator >> (std::istream& is, Product* a) {
        std::cout << "ID:"; is >> a->productId;
        std::cout << "name:";	is >> a->name;
        std::cout << "price:";  is >> a->price;
        return is;
    }
   //void Product::read_file_product(ifstream& filein) {
   //     getline(filein, productId, ',');
   //     filein.seekg(1, 1);
   //     getline(filein, name, ',');
   //     filein.seekg(1, 1);
   //     filein >> price;
   // }
   // void Product::write_file_product() {
   //     ofstream fileout;
   //     fileout.open("Product.txt", ios::out | ios::app);
   //     fileout << "\n";
   //     fileout << productId << ", " << name << ", " << price;
   //     fileout.close();
   // }


