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
	//void Client::add_product_to_order() {
	//	ofstream fileout;
	//	fileout.open("Order.txt", ios::app);
	//	fileout << "\n" << user;
	//	display_product();

	//	//List<Product>* lpOrder= new List<Product>;
	//	int check = 1;
	//	while (check != 0) {
	//		cout << "\nchon san pham:";
	//		cin.ignore();
	//		string n;
	//		getline(cin, n);

	//		Item<Product>* current = ProductList->getHead();
	//		while (current != nullptr) {
	//			if (current->data->getproductId() == n) {
	//				Product* temp = current->data;
	//				//lpOrder->insert_back(temp);
	//				fileout << ", " << temp->getproductId() << ", " << temp->getPrice();
	//				break;
	//			}
	//			current = current->next;
	//		}
	//		cout << "nhap 1 de tiep tuc mua hang" << endl;
	//		cout << "nhap 0 de ket thuc mua hang" << endl;
	//		cout << "your choise is:"; cin >> check;
	//		cin.ignore();

	//	}
	//	fileout.close();
	//}


