#pragma once
#include<iostream>
#include<string>
#include"Product.h"
#include"list.h"
#include<fstream>
using namespace std;
class OtherProduct :public Product
{
private:
    string Description;

public:
    OtherProduct();
    ~OtherProduct();

    void setDescription(string n);
    string getDescription();

    void displayp(Product* a);
    void insert();
    friend ostream& operator<<(std::ostream& os, OtherProduct* a);
    friend istream& operator >> (std::istream& is, OtherProduct* a);
    void read_file_product(ifstream& filein);
     void write_file_product();
};

