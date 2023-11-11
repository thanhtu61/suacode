#pragma once
#include"Admin.h"
#include"Product.h"
#include"List.h"
#include"User.h"
#include"List.h"
#include<iostream>
#include<fstream>
#include<string>
class Interface
{
protected:
	Admin admin;
	//Client client;
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
						}

			} while (check != 0);
		}
	/*void menu_client() {
		int check;
		do {
			cout<<"1) "

		} while ();
	}*/
};
