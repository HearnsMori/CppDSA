#ifndef CLL_H
#define CLL_H

template <typename T>
class CNode {
public:
    T data;
    CNode<T>* next;
    CNode(T val);
};

template <typename T>
class CircularLinkedList {
private:
 CNode<T>* head;
public:
 CircularLinkedList();
 void create(int index, T data);
 T read(int index);
 void update(int index, T data);
 void deleteNode(int index);

 int length();
 int indexOf(T data);
 void pushFront(T data);
 void pushBack(T data);
 T popFront(T data);
 T popBack(T data);
 void display();
};

#endif
