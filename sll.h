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
class SinglyLinkedList {
private:
 SNode<T>* head;
public:
 SinglyLinkedList();
 void create(int index, T data);
 T read(int index);
 void update(int index, T newData);
 void deleteNode(int index);

 int length();
 int indexOf(T data);
 void pushFront(T data);
 void pushBack(T data);
 T popFront();
 T popBack();
 void display();
};

#endif
