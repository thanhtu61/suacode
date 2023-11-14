#pragma once
#include<iostream>
#include<string>
#include"Product.h"
#include"list.h"
#include<fstream>
using namespace std;
class ComProduct :public Product
{
private:
    string Processor;
public:
    ComProduct();
    ~ComProduct();

    void setProcessor(string n);
    string getProcessor();
    void displayp(Product* a);
    void insert();
    friend ostream& operator<<(std::ostream& os, ComProduct* a);
    friend istream& operator >> (std::istream& is, ComProduct* a);
    void read_file_product(ifstream& filein);
    void write_file_product();
};


