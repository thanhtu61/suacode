#include "Client.h"


	bool Client:: log_in_client() {
		ifstream is;
		is.open("accountClient.txt", ios::in);

		cout << "user name:";
		cin.ignore();
		char* u = new char[50]; cin.getline(u, 50);
		cout << "password:";
		int p; cin >> p;

		while (!is.eof()) {
			getline(is, user, ',');
			is.ignore();
			is >> password;
			is.ignore();
			if (password == p && u == user) {
				return true;
			}
		}
		cout << "You entered incorrectly, you cannot log in";
		is.close();
		return false;
	}
	void Client::registerUser() {

		Client a;
		cin >> a;

		ifstream is("accountClient.txt");
		bool checkExist = false;
		while (!is.eof()) {
			char check[50];
			char bin[50];
			is.getline(check, 50, ',');
			is.getline(bin, 50, '\n');

			if (a.user == check) {
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
		int numberClient = 1;
		filein.open("Client.txt", ios::in);
		while (!filein.eof()) {
			string temp;
			getline(filein, temp);
			numberClient++;
		}
		setUserId(numberClient);
		filein.close();

		ofstream fileout;
		fileout.open("Client.txt", ios::app);
		fileout << "\n" << numberClient << ", " << a.user << ", " << a.address;
		fileout.close();
	}
	void Client::read_client(ifstream& filein) {
		filein >> userId;
		filein.seekg(2, 1);
		getline(filein, user, ',');
		filein.seekg(1, 1);
		getline(filein, address, '\n');
	}


	void Client::add_product_to_order() {
		ofstream fileout;
		fileout.open("Order.txt", ios::app);
		fileout << "\n" << user;
		display_product();

		int check = 1;
		cout << "\nChoose product: ";
		cin.ignore(1,'\n');
		while (check != 0) {
			
			string n;
			getline(cin, n);

			Item<Product>* current = ProductList->getHead();
			bool productFound = false;
			while (current != nullptr) {
				if (current->data->getproductId() == n) {
					Product* temp = current->data;
					productFound = true;
					fileout << ", " << temp->getproductId() << ", " << temp->getPrice();
					break;
				}
				current = current->next;
			}

			if (!productFound) {
				cout << "Product not found. Please try again." << endl;
				continue;
			}

			cout << "Enter 1 to continue shopping" << endl;
			cout << "Enter 0 to complete the purchase" << endl;
			cout << "Your choice is: ";
			cin >> check;
			if(check==1)cout << "\nChoose product: ";
			
			cin.ignore();
		}
		fileout.close();
	}

	void  Client::read_order() {
		ifstream filein;
		filein.open("Order.txt", ios::in);
		string temp;
		string temp1;
		string temp2;
		double temp3;

		getline(filein, temp, ',');
		while (temp != user) {
			getline(filein, temp1, '\n');
			getline(filein, temp, ',');
		}
		cout << user << endl;
		filein.seekg(1, 1);
		char check_n = ',';
		while (check_n == ',') {
			char check = ' ';
			filein >> check;
			if (check != ' ') {
				filein.seekg(-1, ios::cur);
				
				getline(filein, temp2, ',');
				cout << "ID:" << temp2 << "\t";
				filein.seekg(1, 1);
				filein >> temp3;
				cout << "Price:" << temp3 << endl;
				filein >> check_n;
				
			}
			else return;
		}
	}
	
