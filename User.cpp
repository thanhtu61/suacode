#include "User.h"

User::User() {

	ProductList = new List<Product>;
	read_list_product(ProductList);
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
	Item<Product>* current = new Item<Product>;
	current = ProductList->getHead();
	while (current != nullptr) {
		cout << "ID:" << current->data->getproductId() << "   ";
		cout << "name:" << left << setw(25) << current->data->getName() << "   ";
		cout << "price:" << current->data->getPrice() << "   ";
		current = current->next;
		cout << endl;
	}
}
void User::read_list_product(List<Product>* products) {
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
				products->insert_back(x);
			}
			else if (a == 'L') {
				x = new ComProduct;
				x->read_file_product(filein);
				products->insert_back(x);

			}
			else if (a == 'C') {
				x = new LapProduct;
				x->read_file_product(filein);
				products->insert_back(x);
			}
		}
	}
	filein.close();
}
