#pragma once

#include"List.h"
#include <string>
#include<iostream>
#include<iomanip>
#include "Product.h"
#include"ComProduct.h"
#include"LapProduct.h"
#include"OtherProduct.h"
#include"ScreenProduct.h"

using namespace std;
class User
{
protected:
	int userId;
	string user;
	string address;
	int password;
	List<Product>* ProductList;
	List<Product>* ComputerList;
	List<Product>* LaptopList;
	List<Product>* OtherList;
	List<Product>* ScreenList;
public:
	User();
	~User();
	// geter seter
	int get_password();
	int get_userId();
	string get_user();
	string get_address();
	void setUserId(int n);
	//operator
	friend ostream& operator<<(ostream& os, User& a);
	friend istream& operator>>(istream& is, User& a);
	//product
	void display_product();
	void display_laptop();
	void display_computer();
	void display_other();
	void display_screen();
	void read_list_product(List<Product>* products, List<Product>* laptop, List<Product>* computer, List<Product>* other, List<Product>*screen);
	
};



