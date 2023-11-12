#pragma once
#include "List.h"
#include "fstream"
#include"User.h"
#include <string>
using namespace std;
class User;

class Client:public User
{
public:
	//account
	bool log_in_client();
	void registerUser();
	void read_client(ifstream& filein);
	//order
	void add_product_to_order();
};

