#pragma once
#include<iostream>
#include<string>
#include"Product.h"
#include"list.h"
#include<fstream>
using namespace std;
class ComProduct:public Product
{
private:
    string Processor;
public:
        ComProduct() :Product() {}
        ~ComProduct() {}

        void setProcessor(string n) { Processor = n; }
        string getProcessor() { return Processor; }
        void displayp(Product* a) {
            cout << "ID:" << a->getproductId() << "   ";
            cout << "name:" << left << setw(25) << a->getName() << "   ";
            cout << "price:" << a->getPrice() << "   ";
            cout << "Processor:" << Processor << "   ";
        }
        void insert()
        {
            cout << "ID:"; cin >> productId;
            cout << "Name:"; cin >> name;
            cout << "Price:";  cin >> price;
            cout << "Processor:";  cin >> Processor;
        }
        friend ostream& operator<<(std::ostream& os, ComProduct* a) {
            os << "ID:" << a->getproductId() << "   ";
            os << "Name:" << left << setw(25) << a->getName() << "   ";
            os << "Price:" << a->getPrice() << "   ";
            os << "Processor:" << a->getProcessor() << "   ";
            return os;
        }
        friend istream& operator >> (std::istream& is, ComProduct* a) {
            cout << "ID:"; is >> a->productId;
            cout << "Name:";	is >> a->name;
            cout << "Price:";  is >> a->price;
            cout << "Description:";  is >> a->Processor;
            return is;
        }
        void read_file_product(ifstream& filein) {
            getline(filein, productId, ',');
            filein.seekg(1, 1);
            getline(filein, name, ',');
            filein.seekg(1, 1);
            filein >> price;
            filein.seekg(2, 1);
            getline(filein, Processor, '\n');
        }
        void write_file_product() {
            ofstream fileout;
            fileout.open("Product.txt", ios::out | ios::app);
            fileout << productId << ", " << name << ", " << price << ", " << Processor;
            fileout << "\n";
            fileout.close();
        }
    };


