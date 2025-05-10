#include <iostream>
#include <stdexcept>
#include "dll.h"

using namespace std;

template <typename T>
DNode<T>::DNode(T val) {
	data = val;
	next = nullptr;
	prev = nullptr;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::createNode(T data) {
	pushTail(data);
}

template <typename T>
T DoublyLinkedList<T>::readNode(int index) {
	if (!head) throw runtime_error("List is empty.");
	DNode<T>* node = head;
	while (index > 0 && node) {
		node = node->next;
		--index;
	}
	if (!node) throw out_of_range("Index out of range.");
	return node->data;
}

template <typename T>
void DoublyLinkedList<T>::updateNode(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	DNode<T>* node = head;
	while (index > 0 && node) {
		node = node->next;
		--index;
	}
	if (!node) throw out_of_range("Index out of range.");
	node->data = data;
}

template <typename T>
void DoublyLinkedList<T>::deleteNode(int index) {
	if (!head) throw runtime_error("List is empty.");

	if (index == 0) {
		DNode<T>* temp = head;
		head = head->next;
		if (head) head->prev = nullptr;
		else tail = nullptr;
		delete temp;
	} else {
		DNode<T>* node = head;
		while (index > 0 && node) {
			node = node->next;
			--index;
		}
		if (!node) throw out_of_range("Index out of range.");

		if (node->prev) node->prev->next = node->next;
		if (node->next) node->next->prev = node->prev;
		if (node == tail) tail = node->prev;
		delete node;
	}
}

template <typename T>
int DoublyLinkedList<T>::length() {
	int len = 0;
	DNode<T>* temp = head;
	while (temp) {
		++len;
		temp = temp->next;
	}
	return len;
}

template <typename T>
int DoublyLinkedList<T>::indexOf(T data) {
	DNode<T>* temp = head;
	int i = 0;
	while (temp) {
		if (temp->data == data) return i;
		temp = temp->next;
		++i;
	}
	throw runtime_error("Data not found.");
}

template <typename T>
void DoublyLinkedList<T>::pushHead(T data) {
	DNode<T>* node = new DNode<T>(data);
	node->next = head;
	if (head) head->prev = node;
	head = node;
	if (!tail) tail = node;
	cout << "Push at the Head: " << data << "\n";
}

template <typename T>
void DoublyLinkedList<T>::pushTail(T data) {
	DNode<T>* node = new DNode<T>(data);
	if (!tail) {
		head = tail = node;
		cout << "Root created successfully. \n";
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	cout << "Push at the Tail: " << data << "\n";
}

template <typename T>
T DoublyLinkedList<T>::popHead() {
	if (!head) throw runtime_error("List is empty.");
	DNode<T>* temp = head;
	T val = temp->data;
	head = head->next;
	if (head) head->prev = nullptr;
	else tail = nullptr;
	delete temp;
	return val;
}

template <typename T>
T DoublyLinkedList<T>::popTail() {
	if (!tail) throw runtime_error("List is empty.");
	DNode<T>* temp = tail;
	T val = temp->data;
	tail = tail->prev;
	if (tail) tail->next = nullptr;
	else head = nullptr;
	delete temp;
	return val;
}

template <typename T>
void DoublyLinkedList<T>::display() {
	DNode<T>* temp = head;
	while (temp) {
		cout << temp->data << " <-> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

template <typename T>
void DoublyLinkedList<T>::readLine() {
	DNode<T>* temp = head;
	string input;
	while (temp) {
		cout << temp->data << " <-> ";
		cout << "(press 'n' for next, 'p' for previous, any other key to exit): ";
		cin >> input;

		if (input == "n") {
			if (temp->next)
				temp = temp->next;
			else
				cout << "Reached end of list.\n";
		}
		else if (input == "p") {
			if (temp->prev)
				temp = temp->prev;
			else
				cout << "Already at the head.\n";
		}
		else {
			break;
		}
	}
}

template <typename T>
void DoublyLinkedList<T>::insertNextTo(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	DNode<T>* node = head;
	while (index > 0 && node) {
		node = node->next;
		--index;
	}
	if (!node) throw out_of_range("Index out of range.");

	DNode<T>* newNode = new DNode<T>(data);
	newNode->next = node->next;
	newNode->prev = node;
	if (node->next) node->next->prev = newNode;
	node->next = newNode;
	if (node == tail) tail = newNode;

	cout << "Inserted " << data << " after index.\n";
}

// Explicit template instantiations
template class DoublyLinkedList<int>;
template class DoublyLinkedList<char>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<string>;