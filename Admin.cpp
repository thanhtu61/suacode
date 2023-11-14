#include "Admin.h"
Admin::Admin() {
	clientList = new List<Client>;
	read_list_client(clientList);
}

Admin::~Admin() {
		delete clientList;
	}
	void Admin::write_list_product(List<Product>* products) {
		ofstream fileout;
		fileout.open("Product.txt", ios::out);
		Item<Product>* x = new Item<Product>;
		x = products->getHead();
		while (x != nullptr) {
			x->data->write_file_product();
			x = x->next;
		}
		delete x;
		fileout.close();
	}
	void Admin::add_product() {
		cout << "Enter the element to be inserted:" << endl;
		cout << "1)Laptop\n2)Computer\n3)Other\nEnter:";
		int n; cin >> n;
		Product* newItem=NULL;
		if (n == 1) {	newItem = new LapProduct;}
		else if (n == 2) {	newItem = new ComProduct;}
		else if (n == 3) { newItem = new OtherProduct; }
		else {
			cout << "Enter wrong";
		}
		newItem->insert();
		ProductList->insert_back(newItem);
		write_list_product(ProductList);
	}

	void Admin::update_product() {
		cout << "\nupdate product:\n";
		cout << "1)Laptop\n2)Computer\n3)Other\nEnter:";
		int n; cin >> n;
		Product* upProduct = NULL;
		if (n == 1) { upProduct = new LapProduct; }
		else if (n == 2) { upProduct = new ComProduct; }
		else if (n == 3) { upProduct = new OtherProduct; }
		else {
			cout << "Enter wrong";
		}
		cout << "\nupdate product in number:";
		int pos; cin >> pos;
		cout << "\nenter new product:\n";
		upProduct->insert();
		ProductList->update(upProduct, pos-1);
		write_list_product(ProductList);
	}
	void Admin::delete_product() {
		cout << "delete product at number:";
		int pos; cin >> pos;
		ProductList->deleteAt(pos-1);
		write_list_product(ProductList);
	}

	void Admin::read_list_client(List<Client>* client) {
		ifstream filein;
		filein.open("Client.txt", ios::in);

		while (!filein.eof()) {
			char a = ' ';
			filein >> a;
			if (a != ' ') {
				filein.seekg(-1, ios::cur);
				Client* x = new Client;
				x->read_client(filein);
				client->insert_back(x);
			}
			else {
				return;
			}
		}

		filein.close();
	}

	void Admin::write_list_client(List<Client>* clients) {
		ofstream fileout;
		fileout.open("Client.txt", ios::out);
		Item<Client>* x = new Item<Client>;
		x = clients->getHead();
		while (x != nullptr) {
			fileout << x->data->get_userId() << ", " << x->data->get_user() << ", " << x->data->get_address() << endl;
			x = x->next;
		}
		delete x;
		fileout.close();
	}
	void Admin::display_client() {

		Item<Client>* current = new Item<Client>;
		current = clientList->getHead();
		while (current != nullptr) {
			cout << "ID:" << current->data->get_userId() << "   ";
			cout << "name:" << setw(10)<<left<<current->data->get_user() << "   ";
			cout << "address:" << current->data->get_address() << "   ";
			current = current->next;
			cout << endl;
		}
	}


	void Admin::del_client() {
		cout << "delete client at number:";
		int pos; cin >> pos;
		clientList->deleteAt(pos);
		write_list_client(clientList);
	}

	bool Admin::log_in_admin() {
		ifstream is;
		is.open("accountAdmin.txt", ios::in);

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

	void  Admin::read_list_order() {
	Item<Client>* current = clientList->getHead();
	
	while (current != nullptr) {
		ifstream filein;
		filein.open("Order.txt", ios::in);
		string temp;
		string temp1;
		string temp2;
		double temp3;
		getline(filein, temp, ',');
		while (temp != current->data->get_user()) {
			getline(filein, temp1, '\n');
			getline(filein, temp, ',');
		}
		cout << "Name Client:" << current->data->get_user() << endl;
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
			else break;
		}
		current = current->next;
		filein.close();
	} 
}
	
	