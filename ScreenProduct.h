#pragma once
#include<iostream>
#include<string>
#include"Product.h"
#include"list.h"
#include<fstream>
using namespace std;
class ScreenProduct :public Product
{
private:
    string Resolution;
public:
    ScreenProduct();
    ~ScreenProduct();
    void setResolution(string n);
    string getResolution();

    void displayp(Product* a);
    void insert();
    friend ostream& operator<<(std::ostream& os, ScreenProduct* a);
    friend istream& operator >> (std::istream& is, ScreenProduct* a);
    void read_file_product(ifstream& filein);
    void write_file_product();
};


