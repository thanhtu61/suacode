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
			fileout << x->data->getproductId() << ", " << x->data->getName() << ", " << x->data->getPrice() << endl;
			x = x->next;
		}
		delete x;
		fileout.close();
	}
	void Admin::add_product() {
		cout << "Enter the element to be inserted:" << endl;
		Product* newItem = new Product;
		cin >> newItem;
		ProductList->insert_back(newItem);
		write_list_product(ProductList);
	}

	void Admin::update_product() {
		cout << "\nupdate product at number:";
		int pos; cin >> pos;
		cout << "enter new product:\n";
		Product* upProduct = new Product;
		cin >> upProduct;
		ProductList->update(upProduct, pos);
		write_list_product(ProductList);
	}
	void Admin::delete_product() {
		cout << "delete product at number:";
		int pos; cin >> pos;
		ProductList->deleteAt(pos);
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


