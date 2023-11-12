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
	void read_list_product(List<Product>* products);
	
};



