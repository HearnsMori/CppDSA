#include "ds.h"
#ifndef CDLL_H
#define CDLL_H

using namespace std;

template <typename T>
class CDNode {
	public:
		T data;
		CDNode<T>* next;
		CDNode<T>* prev;
		CDNode(T val);
};

template <typename T>
class CircularDoublyLinkedList : public DS<T> {
	private:
		CDNode<T>* head;
	public:
		CircularDoublyLinkedList();
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
