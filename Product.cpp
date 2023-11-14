#include "Product.h"
    string Product:: getproductId() { return  productId; }
    string Product::getName() { return  name; }
    double Product::getPrice() { return price; }

    void Product::setName(string n) { name = n; }
    void Product::setPrice(double n) { price = n; }
 
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



