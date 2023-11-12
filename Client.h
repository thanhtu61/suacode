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
	void add_product_to_order(){}
	bool log_in_client() {
		ifstream is;
		is.open("accountClient.txt", ios::in);

		cout << "user name:";
		cin.ignore();
		char* u = new char[50]; cin.getline(u, 50);
		cout << "password:";
		int p; cin >> p;

		while (!is.eof()) {
			getline(is,user, ',');
			is.ignore();
			is >> password;
			is.ignore();
			if (password == p && u==user) {
				return true;
			}
		}
		cout << "You entered incorrectly, you cannot log in";
		is.close();
		return false;
	}
	void registerUser() {
		
		Client a;
		cin >> a;
		
		ifstream is("accountClient.txt");
		bool checkExist = false;
		while (!is.eof()) {
			char check[50];
			char bin[50];
			is.getline(check, 50, ',');
			is.getline(bin, 50, '\n');
			
			if (a.user ==check) {
				checkExist = true;
				break;
			}
		}
		is.close();
		if (checkExist) {
			cout << "Username already exists. Registration failed." << endl;
			return;
		}

		ofstream os;
		os.open("accountClient.txt", ios::app);
		os << a.user << ", " << a.password << endl;
		cout << "Registration successful." << endl;
		os.close();

		ifstream filein;
		int numberClient=1;
		filein.open("Client.txt", ios::in);
		while (!filein.eof()) {
			string temp;
			getline(filein, temp);
			numberClient++; }

		filein.close();

		ofstream fileout;
		fileout.open("Client.txt", ios::app);
		fileout <<"\n"<< numberClient << ", " << a.user << ", " << a.address;
		fileout.close();
	}
	void read_client(ifstream& filein) {
		filein >> userId;
		filein.seekg(2, 1);
		getline(filein, user, ',');
		filein.seekg(1, 1);
		getline(filein, address, '\n');
	}
};

