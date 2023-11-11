#pragma once
#include "Product.h"
#include"List.h"
#include"ComProduct.h"
#include"LapProduct.h"
#include"OtherProduct.h"
#include <string>
#include<iostream>
#include<iomanip>


using namespace std;
class User
{
protected:
	int userId;
	string user;
	string address;
	int password;
	List<Product>* ProductList;
public:
	User() {
		
		ProductList = new List<Product>;
		read_list_product(ProductList);
	}
	int get_password() { return password; }
	int get_userId() { return userId; }
	string get_user() { return user; }
	string get_address() { return address; }

	void setUserId(int n) { user = n; }

	friend ostream& operator<<(ostream& os, User& a) {
		os << "name_user:" << a.user << "address:" << a.address << endl;
		return os;
	}
	friend istream& operator>>(istream& is, User& a)
	{
		cout << "user:";
		is >> a.user;
		cout << "address:";
		is>>a.address;
		cout << "password:";
		is >> a.password;
		return is;
	}

	void display_product() {
		Item<Product>* current = new Item<Product>;
		current = ProductList->getHead();
		while (current != nullptr) {
			cout << "ID:" << current->data->getproductId() << "   ";
			cout << "name:" <<left<< setw(25)<<current->data->getName() << "   ";
			cout << "price:" << current->data->getPrice() << "   ";
			current = current->next;
			cout << endl;
		}
	}

	void read_list_product(List<Product>* products) {
		ifstream filein;
		filein.open("Product.txt", ios::in);
		Product* x = NULL;
		while (filein.eof() == false) {
			char a;
			filein >> a;
			if (filein.eof() == false) {
				filein.seekg(-1, ios::cur);

				if (a == 'O') {
					x = new OtherProduct;
					x->read_file_product(filein);
					products->insert_back(x);
				}
				else if (a == 'L') {
					x = new ComProduct;
					x->read_file_product(filein);
					products->insert_back(x);

				}
				else if (a == 'C') {
					x = new LapProduct;
					x->read_file_product(filein);
					products->insert_back(x);
				}
			}
		}
		filein.close();
	}
	void write_list_product(List<Product>* products) {
		ofstream fileout;
		fileout.open("Product.txt", ios::out);
		Item<Product>* x = new Item<Product>;
		x = products->getHead();
		while (x != nullptr) {
			fileout << x->data->getproductId() << ", " << x->data->getName() << ", " << x->data->getPrice() << endl;
			x = x->next;
		}
		delete x;
		fileout.close();
	}
	
	
};



