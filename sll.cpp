#include <iostream>
#include <stdexcept>
#include "sll.h"

using namespace std;

template <typename T>
SNode<T>::SNode(T val) {
	data = val;
	next = nullptr;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::createNode(T data) {
	pushTail(data);
}

template <typename T>
T SinglyLinkedList<T>::readNode(int index) {
	if (!head) throw runtime_error("List is empty.");
	SNode<T>* node = head;
	while (index > 0 && node) {
		node = node->next;
		--index;
	}
	if (!node) throw out_of_range("Index out of range.");
	return node->data;
}

template <typename T>
void SinglyLinkedList<T>::updateNode(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	SNode<T>* node = head;
	while (index > 0 && node) {
		node = node->next;
		--index;
	}
	if (!node) throw out_of_range("Index out of range.");
	node->data = data;
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(int index) {
	if (!head) throw runtime_error("List is empty.");

	if (index == 0) {
		SNode<T>* temp = head;
		head = head->next;
		delete temp;
	} else {
		SNode<T>* prev = head;
		while (index > 1 && prev->next) {
			prev = prev->next;
			--index;
		}
		if (!prev->next) throw out_of_range("Index out of range.");
		SNode<T>* toDelete = prev->next;
		prev->next = toDelete->next;
		delete toDelete;
	}
}

template <typename T>
int SinglyLinkedList<T>::length() {
	int len = 0;
	SNode<T>* temp = head;
	while (temp) {
		++len;
		temp = temp->next;
	}
	return len;
}

template <typename T>
int SinglyLinkedList<T>::indexOf(T data) {
	SNode<T>* temp = head;
	int i = 0;
	while (temp) {
		if (temp->data == data) return i;
		temp = temp->next;
		++i;
	}
	throw runtime_error("Data not found.");
}

template <typename T>
void SinglyLinkedList<T>::pushHead(T data) {
	SNode<T>* node = new SNode<T>(data);
	node->next = head;
	head = node;
	cout << "Push at the Head: " << data << "\n";
}

template <typename T>
void SinglyLinkedList<T>::pushTail(T data) {
	SNode<T>* node = new SNode<T>(data);
	if (!head) {
		head = node;
		cout << "Root created successfully. \n";
	} else {
		SNode<T>* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = node;
	}
	cout << "Push at the Tail: " << data << "\n";
}

template <typename T>
T SinglyLinkedList<T>::popHead() {
	if (!head) throw runtime_error("List is empty.");
	SNode<T>* temp = head;
	T val = temp->data;
	head = head->next;
	delete temp;
	return val;
}

template <typename T>
T SinglyLinkedList<T>::popTail() {
	if (!head) throw runtime_error("List is empty.");
	if (!head->next) {
		T val = head->data;
		delete head;
		head = nullptr;
		return val;
	}
	SNode<T>* temp = head;
	while (temp->next && temp->next->next) {
		temp = temp->next;
	}
	T val = temp->next->data;
	delete temp->next;
	temp->next = nullptr;
	return val;
}

template <typename T>
void SinglyLinkedList<T>::display() {
	SNode<T>* temp = head;
	while (temp) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

template <typename T>
void SinglyLinkedList<T>::readLine() {
	SNode<T>* temp = head;
	string input;
	while (temp) {
		cout << temp->data << " -> ";
		cout << "(press 'n' for next, any other key to exit): ";
		cin >> input;
		if (input != "n") break;
		temp = temp->next;
	}
}

template <typename T>
void SinglyLinkedList<T>::insertNextTo(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	SNode<T>* node = head;
	while (index > 0 && node) {
		node = node->next;
		--index;
	}
	if (!node) throw out_of_range("Index out of range.");
	SNode<T>* newNode = new SNode<T>(data);
	newNode->next = node->next;
	node->next = newNode;
	cout << "Inserted " << data << " after index.\n";
}

// Explicit instantiation
template class SinglyLinkedList<char>;
template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<string>;
