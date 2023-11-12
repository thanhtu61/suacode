#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"OtherProduct.h"
using namespace std;
template <class T>
struct Item {
    T* data;
    Item<T>* next;
    Item<T>* prev;
   
};

template <class T>
class List  {
private:
    Item<T>* head;
    Item<T>* tail;
    int length;

public:
    List() : head(nullptr), tail(nullptr), length(0) {}
    /* ~List() {
         while (head != nullptr) {
             Item<T>* temp = head;
             head = head->next;
             delete temp;
         }
     }*/
    Item<T>* getHead();
    
    void insert_front(T* value);
    void insert_back(T* value);
    void insert(T* value, int pos);
    void delete_front();
    void delete_back();
    void deleteAt(int pos);
    void update(T* value, int pos);
    void display();
    
    //List <OtherProduct>read_file_other();
    //void read_file(string FILE_OF_DATA);	
    //void write_file(string FILE_OF_DATA);
};
template <class T>
Item<T>* List<T> ::getHead() {
    return head;
}


template <class T>
void List<T> ::insert_front(T* value) {
    Item<T>* newItem = new Item<T>;
    newItem->data = value;
    newItem->prev = nullptr;
    length++;

    if (head == nullptr) {
        newItem->next = nullptr;
        head = newItem;
        tail = newItem;
       // std::cout << "Element inserted1" << std::endl;
    }
    else {
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
       // std::cout << "Element inserted2" << std::endl;
    }
}

//insert_back
template <class T>
void List<T> ::insert_back(T* value) {
    Item<T>* newItem = new Item<T>;
    newItem->data = value;
    newItem->next = nullptr;
    length++;
    if (head == nullptr) {
        newItem->prev = nullptr;

        head = newItem;
        tail = newItem;
       // std::cout << "Element inserted3" << std::endl;
    }
    else {
        newItem->prev = tail;
        tail->next = newItem;
        tail = newItem;
       // std::cout << "Element inserted4" << std::endl;
    }
}

//insert
template <class T>
void List<T> ::insert(T* value, int pos) {
    Item<T>* newItem = new Item<T>;
    newItem->data = value;
    length++;
    if (pos < 0) {
        cout << "Invalid position." << endl;
        length--;
        return;
    }
    if (pos == 0) {
        insert_front(value);
        return;
    }

    Item<T>* current = head;
    int currentPos = 0;

    while (current != nullptr && currentPos < pos) {
        current = current->next;
        currentPos++;
    }

    if (current == nullptr) {
        cout << "Invalid position." << endl;
        length--;
        delete newItem;
        return;
    }

    newItem->prev = current->prev;
    newItem->next = current;
    current->prev->next = newItem;
    current->prev = newItem;
    cout << "Element inserted" << endl;
}

//delete_front
template <class T>
void List<T> ::delete_front() {
    if (head == nullptr) {
        cout << "list is empty." << endl;
        return;
    }

    Item<T>* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;
    cout << "Element deleted" << endl;
    length--;
}

//delete_back
template <class T>
void  List<T>::delete_back() {
    if (head == nullptr) {
        cout << "list is empty." << endl;
        return;
    }

    Item<T>* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }

    delete temp;
    cout << "Element deleted" << endl;
    length--;
}

//deleteAt
template <class T>
void List<T>::deleteAt(int pos) {
    if (pos < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 0) {
        delete head;
        length--;
        cout << "Element deleted" << endl;
        return;
    }

    Item <T>* current = head;
    int currentPos = 0;

    while (current != nullptr && currentPos < pos) {
        current = current->next;
        currentPos++;
    }

    if (current == nullptr) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    current->prev->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }

    delete current;
    length--;
    cout << "Element deleted" << endl;
}

//update
template <class T>
void List <T> ::update(T* value, int pos) {

    if (pos < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    if (pos == 0) {
        head->data = value;
        cout << "Node updated" << endl;
        return;
    }

    Item<T>* current = head;
    int currentPos = 0;

    while (current != nullptr && currentPos < pos) {
        current = current->next;
        currentPos++;
    }

    if (current == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }

    current->data = value;
    cout << "Node updated" << endl;
}

//template <class T>
//void List <Product> ::display() {
//    Item<Product>* current =new Item<Product>;
//    current = head;
//    while (current != nullptr) {
//        cout<<"ID:" << current->data->getproductId()<<"   ";
//        cout<<"name:" << current->data->getName() << "   ";
//        cout<<"price:" << current->data->getPrice() << "   ";
//        current = current->next;
//        cout << endl;
//    }
//}
