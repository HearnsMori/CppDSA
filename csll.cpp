#include <iostream>
#include <stdexcept>
#include "csll.h"

using namespace std;

template <typename T>
CSNode<T>::CSNode(T val) {
	data = val;
	next = nullptr;
}

template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList() {
	head = nullptr;
}

template <typename T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() {
	if (!head) return;
	CSNode<T>* temp = head->next;
	while (temp != head) {
		CSNode<T>* next = temp->next;
		delete temp;
		temp = next;
	}
	delete head;
	head = nullptr;
}

template <typename T>
void CircularSinglyLinkedList<T>::createNode(T data) {
	pushTail(data);
}

template <typename T>
T CircularSinglyLinkedList<T>::readNode(int index) {
	if (!head) throw runtime_error("List is empty.");
	CSNode<T>* node = head;
	while (index-- > 0) {
		node = node->next;
		if (node == head) throw out_of_range("Index out of range.");
	}
	return node->data;
}

template <typename T>
void CircularSinglyLinkedList<T>::updateNode(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	CSNode<T>* node = head;
	while (index-- > 0) {
		node = node->next;
		if (node == head) throw out_of_range("Index out of range.");
	}
	node->data = data;
}

template <typename T>
void CircularSinglyLinkedList<T>::deleteNode(int index) {
	if (!head) throw runtime_error("List is empty.");

	if (index == 0) {
		if (head->next == head) {
			delete head;
			head = nullptr;
		} else {
			CSNode<T>* tail = head;
			while (tail->next != head) tail = tail->next;
			CSNode<T>* temp = head;
			head = head->next;
			tail->next = head;
			delete temp;
		}
		return;
	}

	CSNode<T>* prev = head;
	for (int i = 0; i < index - 1; ++i) {
		prev = prev->next;
		if (prev->next == head) throw out_of_range("Index out of range.");
	}

	CSNode<T>* toDelete = prev->next;
	if (toDelete == head) throw out_of_range("Index points to head, use index 0.");

	prev->next = toDelete->next;
	delete toDelete;
}

template <typename T>
int CircularSinglyLinkedList<T>::length() {
	if (!head) return 0;
	int len = 1;
	CSNode<T>* temp = head->next;
	while (temp && temp != head) {
		++len;
		temp = temp->next;
	}
	return len;
}

template <typename T>
int CircularSinglyLinkedList<T>::indexOf(T data) {
	if (!head) throw runtime_error("List is empty.");
	CSNode<T>* temp = head;
	int index = 0;
	do {
		if (temp->data == data) return index;
		temp = temp->next;
		++index;
	} while (temp && temp != head);
	throw runtime_error("Data not found.");
}

template <typename T>
void CircularSinglyLinkedList<T>::pushHead(T data) {
	try {
		CSNode<T>* node = new CSNode<T>(data);
		if (!head) {
			head = node;
			node->next = node;
		} else {
			CSNode<T>* tail = head;
			while (tail->next != head) tail = tail->next;
			node->next = head;
			tail->next = node;
			head = node;
		}
		cout << "Push at Head: " << data << "\n";
	} catch (bad_alloc& e) {
		cout << "Memory allocation failed: " << e.what() << endl;
	}
}

template <typename T>
void CircularSinglyLinkedList<T>::pushTail(T data) {
	try {
		CSNode<T>* node = new CSNode<T>(data);
		if (!head) {
			head = node;
			node->next = node;
		} else {
			CSNode<T>* temp = head;
			while (temp->next != head) temp = temp->next;
			temp->next = node;
			node->next = head;
		}
		cout << "Push at Tail: " << data << "\n";
	} catch (bad_alloc& e) {
		cout << "Memory allocation failed: " << e.what() << endl;
	}
}

template <typename T>
T CircularSinglyLinkedList<T>::popHead() {
	if (!head) throw runtime_error("List is empty.");
	T val = head->data;

	if (head->next == head) {
		delete head;
		head = nullptr;
	} else {
		CSNode<T>* tail = head;
		while (tail->next != head) tail = tail->next;
		CSNode<T>* temp = head;
		head = head->next;
		tail->next = head;
		delete temp;
	}
	return val;
}

template <typename T>
T CircularSinglyLinkedList<T>::popTail() {
	if (!head) throw runtime_error("List is empty.");

	if (head->next == head) {
		T val = head->data;
		delete head;
		head = nullptr;
		return val;
	}

	CSNode<T>* prev = head;
	while (prev->next->next != head) {
		prev = prev->next;
	}
	T val = prev->next->data;
	delete prev->next;
	prev->next = head;
	return val;
}

template <typename T>
void CircularSinglyLinkedList<T>::display() {
	if (!head) {
		cout << "List is empty.\n";
		return;
	}
	CSNode<T>* temp = head;
	do {
		cout << temp->data << " -> ";
		temp = temp->next;
	} while (temp && temp != head);
	cout << "(HEAD)\n";
}

template <typename T>
void CircularSinglyLinkedList<T>::readLine() {
	if (!head) {
		cout << "List is empty.\n";
		return;
	}
	CSNode<T>* temp = head;
	string input;
	while (true) {
		cout << temp->data << " -> ";
		cout << "(press 'n' for next, any other key to exit): ";
		cin >> input;
		if (input != "n") break;
		temp = temp->next;
	}
}

template <typename T>
void CircularSinglyLinkedList<T>::insertNextTo(int index, T data) {
	if (!head) throw runtime_error("List is empty.");
	CSNode<T>* node = head;
	while (index-- > 0) {
		if (node->next == head) throw out_of_range("Index out of range.");
		node = node->next;
	}
	try {
		CSNode<T>* newNode = new CSNode<T>(data);
		newNode->next = node->next;
		node->next = newNode;
		cout << "Inserted " << data << " after index.\n";
	} catch (bad_alloc& e) {
		cout << "Memory allocation failed: " << e.what() << endl;
	}
}

// Explicit template instantiations
template class CircularSinglyLinkedList<int>;
template class CircularSinglyLinkedList<char>;
template class CircularSinglyLinkedList<double>;
template class CircularSinglyLinkedList<string>;