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
    Product() { }
    ~Product() {}
    
    //getter setter
    string getproductId();
    string getName();
    double getPrice();
    void setName(string n);
    void setPrice(double n);
    //operator
    friend std::ostream& operator<<(std::ostream& os, Product* a);
    friend std::istream& operator >> (std::istream& is, Product* a);
    //file
    virtual void read_file_product(ifstream& filein);
    void write_file(Product* a);
};

