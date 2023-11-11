#pragma once
#include<iostream>
#include<string>
#include"Product.h"
#include"list.h"
#include<fstream>
using namespace std;
class OtherProduct :public Product
{
public:
	OtherProduct():Product(){}
	~OtherProduct() {}

     void read_file_product(ifstream& filein) {
        getline(filein, productId, ',');
        filein.seekg(1, 1);
        getline(filein, name, ',');
        filein.seekg(1, 1);
        filein >> price;
    }
    
};

