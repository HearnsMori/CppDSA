#include "ds.h"
#ifndef SLL_H
#define SLL_H
using namespace std;

template <typename T>
class SNode {
	public:
		T data;
		SNode<T>* next;
		SNode(T val);
};

template <typename T>
class SinglyLinkedList : public DS<T> {
	private:
		SNode<T>* head;
	public:
		SinglyLinkedList();
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
