#pragma once
#include"Admin.h"
#include"Client.h"
#include"Product.h"
#include"List.h"
#include"User.h"
#include"List.h"
#include<iostream>
#include<fstream>
#include<string>
class Interface
{
private:
	Admin admin;
	Client client;
public:
	Interface() {};
	void menu_admin() {
		int check;
		do {
			system("cls");
			cout << "0) Exit"<<endl;
			cout << "1) Add products" << endl;
			cout << "2) Edit product information" << endl;
			cout << "3) Delete product" << endl;
			cout << "4) Product information" << endl;
			cout << "5) Client information" << endl;
			cout << "6) Delete client" << endl;
			cout << "7) read_list_order" << endl;
			cout << "Your choice is:" ;
			cin >> check;
			switch (check) {
			case 0:
				system("cls");
				cout << "Exit";
				system("pause");
				break;
			case 1:
				system("cls");
				admin.add_product();
				system("pause");
				break;
			case 2:
					system("cls");
					admin.update_product();
					system("pause");
					break;
			case 3:
					system("cls");
					admin.delete_product();
					system("pause");
					break;
			case 4:
					system("cls");
					admin.display_product();
					system("pause");
					break;
			
			case 5:
				system("cls");
				admin.display_client();
				system("pause");
				break;

			case 6:
				system("cls");
				admin.del_client();
				system("pause");
				break;
			case 7:
				system("cls");
				admin.read_list_order();
				system("pause");
				break;
						}

			} while (check != 0);
		}
	void menu_client() {
		int check;
		do {
			system("cls");
			cout << "Menu" << endl;
			cout << "1) Product information" << endl;
			cout << "2) Laptop information" << endl;
			cout << "3) Computer information" << endl;
			cout << "4) Other information" << endl;
			cout << "5) Add product to order" << endl;
			cout << "6) Display order" << endl;
			cout << "0) Exit" << endl;
			cout << "Your choice is:";
			cin >> check;
			switch (check) {
			case 0:
				system("cls");
				cout << "Exit";
				system("pause");
				break;
			case 1:
				system("cls");
				client.display_product();
				system("pause");
				break;
			case 2:
				system("cls");
				client.display_laptop();
				system("pause");
				break;
			case 3:
				system("cls");
				client.display_computer();
				system("pause");
				break;
			case 4:
				system("cls");
				client.display_other();
				system("pause");
				break;
			case 5:
				system("cls");
				client.add_product_to_order();
				system("pause");
				break ;
			case 6:
				system("cls");
				client.read_order();
				system("pause");
				break;
			}

		} while (check !=0);

	}
	void menu() {
		int choose;
		do {
			cout << "Access by:" << endl;
			cout << "1) Admin" << endl;
			cout << "2) Client" << endl;
			cout << "0) Exit" << endl;
			cout << "Your choice is:";
			cin >> choose;
			switch (choose) {
			case 0:
				system("cls");
				cout << "Exit";
				system("pause");
				break;
			case 1:
				system("cls");
				if (admin.log_in_admin() == true) { menu_admin(); }
				else menu();
				system("pause");
			case 2:
				system("cls");
				cout << "1)Sign in" << endl;
				cout << "2)Sign up" << endl;
				cout << "3)Sign in as a guest" << endl;
				cout << "0) Exit" << endl;
				cout << "Your choice is:";
				int n; cin >> n;
				switch (n) {
				case 0:
					system("cls");
					cout << "Exit";
					system("pause");
					break;
				case 1:
					system("cls");
					cout << "Sign in:" << endl;
					if (client.log_in_client() == true)
						menu_client();
					
					system("pause");
					break;
				case 2:
					system("cls");
					client.registerUser();
					system("cls");
					cout << "Sign in:" << endl;
					if (client.log_in_client() == true)
						menu_client();
					system("pause");
					break;

				case 3:
					system("cls");
					client.display_product();
					cout << "\nLogin to order!!!";
					system("pause");
					break;
				default:
					cout << "FAULT";
					break;
				}
				system("pause");
			}
		} while (choose != 0);

	}
};
