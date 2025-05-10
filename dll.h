#include "ds.h"
#ifndef DLL_H
#define DLL_H
using namespace std;

template <typename T>
class DNode {
	public:
		T data;
		DNode<T>* next;
		DNode<T>* prev;
		DNode(T val);
};

template <typename T>
class DoublyLinkedList : public DS<T> {
	private:
		DNode<T>* head;
		DNode<T>* tail;
		
	public:
		DoublyLinkedList();
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
