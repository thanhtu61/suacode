#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
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

    virtual void displayp(Product*)=0;
    virtual void insert() = 0;
    //operator
    friend ostream& operator<<(std::ostream& os, Product* a);
    friend istream& operator >> (std::istream& is, Product* a);
    //file
    virtual void read_file_product(ifstream& filein)=0;
    virtual void write_file_product()=0;
};

