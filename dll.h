#ifndef DLL_H
#define DLL_H

template <typename T>
class DNode {
public:
    T data;
    DNode<T>* next;
    DNode<T>* prev;
    DNode(T val);
};

template <typename T>
class DoublyLinkedList {
private:
    DNode<T>* head;
public:
    DoublyLinkedList();
    void create(int index, T data);
    T read(int index);
    void update(int index, T newData);
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
