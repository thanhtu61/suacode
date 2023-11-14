#include "User.h"

User::User() {

	ProductList = new List<Product>;
	LaptopList = new List<Product>;
	ComputerList = new List<Product>;
	OtherList = new List<Product>;
	read_list_product(ProductList, LaptopList, ComputerList, OtherList);
}

User::~User() {
	delete ProductList;
}

int User::get_password() { return password; }
int User::get_userId() { return userId; }
string User::get_user() { return user; }
string User::get_address() { return address; }
void User::setUserId(int n) { user = n; }

 ostream& operator<<(ostream& os, User& a) {
	os << "name_user:" << a.user << "address:" << a.address << endl;
	return os;
}
istream& operator>>(istream& is, User& a)
{
	cout << "user name:";
	is >> a.user;
	cout << "address:";
	is >> a.address;
	cout << "password:";
	is >> a.password;
	return is;
}
void User::display_product() {
	
	display_laptop(); cout << endl;
	display_computer(); cout << endl;
	display_other(); cout << endl;
}
void User::display_laptop() {
	Item<Product>* current = new Item<Product>;
	current = LaptopList->getHead();
	cout << "LAPTOP:" <<endl; 
	while (current != nullptr) {
		current->data->displayp(current->data);
		current = current->next;
		cout << endl;
	}
}
void User::display_computer() {
	Item<Product>* current = new Item<Product>;
	current = ComputerList->getHead();
	cout << "COMPUTER:" << endl;
	while (current != nullptr) {
		current->data->displayp(current->data);
		current = current->next;
		cout << endl;
	}
}
void User::display_other() {
	Item<Product>* current = new Item<Product>;
	current =OtherList->getHead();
	cout << "OTHER:" << endl;
	while (current != nullptr) {
		current->data->displayp(current->data);
		current = current->next;
		cout << endl;
	}
}

void User::read_list_product(List<Product>* products, List<Product>*laptop, List<Product>*computer, List<Product>*other) {
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
				other->insert_back(x);
				products->insert_back(x);
			}
			else if (a == 'L') {
				x = new LapProduct;
				x->read_file_product(filein);
				laptop->insert_back(x);
				products->insert_back(x);

			}
			else if (a == 'C') {
				x = new ComProduct;
				x->read_file_product(filein);
				computer->insert_back(x);
				products->insert_back(x);
			}
		}
	}
	filein.close();
}
