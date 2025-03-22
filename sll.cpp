#include <iostream>
#include "sll.h"
using namespace std;

template <typename T>
SNode<T>::SNode(T val) {
	data = val;
	next = nullptr;
}
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	//code
	head = nullptr;
}
template <typename T>
void SinglyLinkedList<T>::create(T data) {
	//code
	SNode<T>* node = new SNode<T>(data);
	if(!head) {
		head = node;
		cout << "Root created successfully. \n";
	} else {
		SNode<T>* temp = head;
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = node;
	}
	cout << "Inserted: " << data << "\n";
}
template <typename T>
T SinglyLinkedList<T>::read(int index) {
	if(!head) {
		throw empty("empty.");
	}
	SNode<T>* node = head;
	while(index > 0) {
		node = node->next;
		--index;
	}
	if (!node) {
		throw out_of_range("Index out of range.");
	}
	return node->data;
}
template <typename T>
void SinglyLinkedList<T>::update(int index, T newData) {
	if(!head) {
  throw empty("empty.");
 }
 SNode<T>* node = head;
 while(index > 0 && node) {
  node = node->next;
  --index;
 }
 if (!node) {
  throw out_of_range("Index out of range.");
 }                                                  
 node->data = newData;
}

template <typename T>
void SinglyLinkedList<T>::deleteSNode(int index) {
	if(!head) {
		throw empty("empty.");
	}
	SNode<T>* node = head;
	while(index > 0 && node) {
		node = node->next;
		--index;
	}
	node = node->next->next;
}

template <typename T>
void SinglyLinkedList<T>::display() {
	SNode<T>* temp = head;
    	while (temp) {
     		cout << temp->data << " -> ";
    		temp = temp->next;
    	}
}
template class SinglyLinkedList<char>;
template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<string>;
