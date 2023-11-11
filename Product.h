#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Product {
protected:
    string  productId;
    string name;
    double price;
public:
    Product() {  }
    ~Product() {}
    
    string getproductId() { return  productId;}
    string getName() { return  name;}
    double getPrice() { return price; }

    void setName(string n) { name = n; }
    void setPrice(double n) { price = n; }
    friend std::ostream& operator<<(std::ostream& os, Product* a) {
        os << a->productId << a->name << a->price << " ";
        return os;
    }
    friend std::istream& operator >> (std::istream& is, Product* a) {
        std::cout << "ID:"; is >> a->productId;
        std::cout << "name:";	is >> a->name;
        std::cout << "price:";  is >> a->price;
        return is;
    }
    virtual void read_file_product(ifstream& filein) {
        getline(filein, productId, ',');
        filein.seekg(1, 1);
        getline(filein, name, ',');
        filein.seekg(1, 1);
        filein >> price;
    }
     void write_file(Product *a) {
         ofstream fileout;
         fileout.open("Product.txt", ios::out | ios::app);
         fileout  << "\n";
         fileout << a->productId << ", " <<a->name<<", "<<a->price;
         fileout.close();
    }
};

