#pragma once
#include<iostream>
#include<string>
#include"Product.h"
#include"list.h"
#include<fstream>
using namespace std;
class LapProduct :public Product
{
private:
    string Brand;
public:
    LapProduct();
    ~LapProduct();
        void setBrand(string n);
        string getBrand();

        void displayp(Product* a);
        void insert();
        friend ostream& operator<<(std::ostream& os, LapProduct* a);
        friend istream& operator >> (std::istream& is, LapProduct* a);
        void read_file_product(ifstream& filein);
        void write_file_product();
    };


