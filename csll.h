#ifndef CSLL_H
#define CSLL_H

#include "ds.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class CSNode {
public:
	T data;
	CSNode<T>* next;
	CSNode(T val);
};

template <typename T>
class CircularSinglyLinkedList : public DS<T> {
private:
	CSNode<T>* head;
public:
	CircularSinglyLinkedList();
	~CircularSinglyLinkedList();

	void createNode(T data);
	T readNode(int index);
	void updateNode(int index, T data);
	void deleteNode(int index);

	int length();
	int indexOf(T data);
	void pushHead(T data);
	void pushTail(T data);
	T popHead();
	T popTail();
	void display();
	void readLine();

	void insertNextTo(int index, T data);
};

#endif