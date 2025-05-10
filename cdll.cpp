#include <iostream>
#include <stdexcept>
#include "cdll.h"

using namespace std;

template <typename T>
CDNode<T>::CDNode(T val) {
	data = val;
	next = nullptr;
	prev = nullptr;
}

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
	head = nullptr;
}

template <typename T>
void CircularDoublyLinkedList<T>::createNode(T data) {
	pushTail(data);
}

template <typename T>
T CircularDoublyLinkedList<T>::readNode(int index) {
	if (!head) throw runtime_error("List is empty.");
	CDNode<T>* node = head;
	while (index > 0) {
		node = node->next;
		if (node == head) throw out_of_range("Index out of range.");
		--index;
	}
	return node->data;
}

template <typename T>
void CircularDoublyLinkedList<T>::updateNode(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	CDNode<T>* node = head;
	while (index > 0) {
		node = node->next;
		if (node == head) throw out_of_range("Index out of range.");
		--index;
	}
	node->data = data;
}

template <typename T>
void CircularDoublyLinkedList<T>::deleteNode(int index) {
	if (!head) throw runtime_error("List is empty.");

	if (head->next == head && index == 0) {
		delete head;
		head = nullptr;
		return;
	}

	CDNode<T>* node = head;
	while (index > 0) {
		node = node->next;
		if (node == head) throw out_of_range("Index out of range.");
		--index;
	}

	if (node == head) head = head->next;
	node->prev->next = node->next;
	node->next->prev = node->prev;

	delete node;
}

template <typename T>
int CircularDoublyLinkedList<T>::length() {
	if (!head) return 0;
	int len = 1;
	CDNode<T>* temp = head->next;
	while (temp != head) {
		++len;
		temp = temp->next;
	}
	return len;
}

template <typename T>
int CircularDoublyLinkedList<T>::indexOf(T data) {
	if (!head) throw runtime_error("List is empty.");
	CDNode<T>* temp = head;
	int i = 0;
	do {
		if (temp->data == data) return i;
		temp = temp->next;
		++i;
	} while (temp != head);
	throw runtime_error("Data not found.");
}

template <typename T>
void CircularDoublyLinkedList<T>::pushHead(T data) {
	CDNode<T>* node = new CDNode<T>(data);
	if (!head) {
		head = node;
		node->next = node;
		node->prev = node;
	} else {
		CDNode<T>* tail = head->prev;
		node->next = head;
		node->prev = tail;
		head->prev = node;
		tail->next = node;
		head = node;
	}
	cout << "Push at Head: " << data << "\n";
}

template <typename T>
void CircularDoublyLinkedList<T>::pushTail(T data) {
	CDNode<T>* node = new CDNode<T>(data);
	if (!head) {
		head = node;
		node->next = node;
		node->prev = node;
	} else {
		CDNode<T>* tail = head->prev;
		node->next = head;
		node->prev = tail;
		tail->next = node;
		head->prev = node;
	}
	cout << "Push at Tail: " << data << "\n";
}

template <typename T>
T CircularDoublyLinkedList<T>::popHead() {
	if (!head) throw runtime_error("List is empty.");
	T val = head->data;

	if (head->next == head) {
		delete head;
		head = nullptr;
	} else {
		CDNode<T>* tail = head->prev;
		CDNode<T>* temp = head;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete temp;
	}
	return val;
}

template <typename T>
T CircularDoublyLinkedList<T>::popTail() {
	if (!head) throw runtime_error("List is empty.");
	CDNode<T>* tail = head->prev;
	T val = tail->data;

	if (tail == head) {
		delete tail;
		head = nullptr;
	} else {
		CDNode<T>* newTail = tail->prev;
		newTail->next = head;
		head->prev = newTail;
		delete tail;
	}
	return val;
}

template <typename T>
void CircularDoublyLinkedList<T>::display() {
	if (!head) {
		cout << "List is empty.\n";
		return;
	}
	CDNode<T>* temp = head;
	do {
		cout << temp->data << " <-> ";
		temp = temp->next;
	} while (temp != head);
	cout << "(HEAD)\n";
}

template <typename T>
void CircularDoublyLinkedList<T>::readLine() {
	if (!head) {
		cout << "List is empty.\n";
		return;
	}
	CDNode<T>* temp = head;
	string input;

	while (true) {
		cout << temp->data << " <-> ";
		cout << "(press 'n' for next, 'p' for prev, any other key to exit): ";
		cin >> input;

		if (input == "n") {
			temp = temp->next;
		} else if (input == "p") {
			temp = temp->prev;
		} else {
			break;
		}
	}
}

template <typename T>
void CircularDoublyLinkedList<T>::insertNextTo(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	CDNode<T>* node = head;
	while (index > 0) {
		node = node->next;
		if (node == head) throw out_of_range("Index out of range.");
		--index;
	}
	CDNode<T>* newNode = new CDNode<T>(data);
	newNode->next = node->next;
	newNode->prev = node;
	node->next->prev = newNode;
	node->next = newNode;
	cout << "Inserted " << data << " after index.\n";
}

// Explicit instantiations
template class CircularDoublyLinkedList<int>;
template class CircularDoublyLinkedList<char>;
template class CircularDoublyLinkedList<double>;
template class CircularDoublyLinkedList<string>;
