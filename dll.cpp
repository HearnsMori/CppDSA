#include <iostream>
#include "dll.h"
using namespace std;

template <typename T>
DNode<T>::DNode(T val) {
	data = val;
	prev = nullptr;
	next = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr
}

template <typename T>
void DoublyLinkedList<T>::create(T val) {
	DNode<T> node = new DNode(val);
	if(!head) {
		head = node;
	} else {
		DNode<T> temp = head;
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = node;
	}
}

template <typename T>
T DoublyLinkedList<T>::read(int index) {
	if(!head) {
		throw empty("empty.");
	}
	DNode<T> node = head;
	while(index>0 && node) {
		node = node->next;
	}
	if(!node) {
		throw index_out_of_range("Index out of range.");
	}
	retrun node->data;
}

template<typename T>
void DoublyLinkedList<T>::update(int index, T newData) {
	if(!head) {
                throw empty("empty.");
        }
        DNode<T> node = head;
        while(index>0 && node) {
                node = node->next;
        }
	if(!node) {
		throw index_out_of_range("Index out of range");
	}
        node->data = newData;
}

template<typename T>
void DoublyLinkedList<T>::deleteDNode(int index) {
	if(!head) {
  throw empty("empty.");
 }
 DNode<T> node = head;
 while(index>0 && node) {
  node = node->next;
 }
 if(!node) {
  throw index_out_of_range("Index out of range");
 }
}
