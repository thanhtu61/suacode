#pragma once
#include <iostream>
#include"Product.h"
#include"OtherProduct.h"
#include"List.h"
#include"ComProduct.h"
#include"LapProduct.h"
#include<fstream>
#include<string>
#include"User.h"
#include"Client.h"
#include"interface.h"
#include"List.h"
#include<fstream>
using namespace std;
class Order
{
private:
	Client Cl;
	List<Product> *Pr;
public:
	Order() {
		Pr = new List<Product>;
	}
	Client getClient() { return Cl; }
	List<Product>* getListProduct() { return Pr; }


	void read_order(ifstream& filein) {
		int temp;
		string temp1;
		double temp2;
		
		filein >> temp;
		Cl.setUserId(temp);
		filein.seekg(2, 1);
		char check_n=' ';
		while (check_n !='\n') {
			char check= ' ';
			filein >> check;
			if (check != ' ') {
				filein.seekg(-1, ios::cur);
				Product* product = new Product;
				getline(filein, temp1, ',');
				product->setName(temp1);
				//filein.seekg(1, 1);
				filein >> temp2;
				product->setPrice(temp2);
				Pr->insert_front(product);
				filein >> check_n;
			}
			else return;
		}
	}

};
class OrderManagement {
private:
	List<Order>* orderList;
public:
	OrderManagement() {
		orderList = new List<Order>;
		read_list_order(orderList);
	}
	void read_list_order(List<Order>* listOrder) {
		ifstream filein;
		filein.open("Order.txt", ios::in);

		while (!filein.eof()) {
			char a = ' ';
			filein >> a;
			if (a != ' ') {
				filein.seekg(-1, ios::cur);
				Order* x = new Order;
				x->read_order(filein);
				cout << x->getClient().get_userId();
				listOrder->insert_back(x);
			}
			else {
				return;
			}
		}

		filein.close();
	}
	void display_order() {
		Item<Order>* current = new Item<Order>;
		Item<Product>* current1 = new Item<Product>;
		current = orderList->getHead();
		current1 = current->data->getListProduct()->getHead();
		while (current != nullptr) {
			cout << "userID:" << current->data->getClient().get_userId() << "   ";
			while (current1 != nullptr) {
				cout << "name:" << left << setw(25) << current->data->getListProduct()->getHead()->data->getName() << "   ";
				cout << "price:" << current->data->getListProduct()->getHead()->data->getPrice() << " ";
				current1 = current1->next;
			}
			current = current->next;
			cout << endl;
		}
	}
	
	/*void write_list_order (List<Order>* order) {
		ofstream fileout;
		fileout.open("Order.txt", ios::out);
		Item<Order>* x = new Item<Order>;
		x = order->getHead();
		while (x != nullptr) {
			fileout << x->data->getClient().get_userId() << ", " << x->data->getListProduct()->getHead()->data->getName()
				<< ", " << x->data->getListProduct()->getHead()->data->getPrice() << endl;
			x = x->next;
			x->data->getListProduct()->getHead()->next;
		}
		delete x;
		fileout.close();
	}*/
};

