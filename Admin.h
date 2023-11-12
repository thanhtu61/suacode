#pragma once
#include<iomanip>
#include"User.h"
#include"List.h"
#include"Client.h"
#include"Product.h"
#include"ComProduct.h"
#include"LapProduct.h"
#include"OtherProduct.h"

using namespace std;
class User;
class Admin:public User
{
private:
	List<Client> *clientList;
public:

	Admin();
	~Admin();
	//product
	void add_product();
	void update_product();
	void delete_product();
	void write_list_product(List<Product>* products);
	//client
	void read_list_client(List<Client>* client);
	void write_list_client(List<Client>* clients);
	void display_client();
	void del_client();
	//account
	bool log_in_admin();
	
};

