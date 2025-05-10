#ifndef DS_H
#define DS_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class DS {
public:
    virtual ~DS() = default;

    // Define pure virtual functions that will be implemented in derived classes.
    virtual void display() = 0;

    // Optional: Any other shared methods you may need for all data structures
    virtual void createNode(T data) = 0;
    virtual T readNode(int index) = 0;
    virtual void updateNode(int index, T data) = 0;
    virtual void deleteNode(int index) = 0;
    virtual int length() = 0;
    virtual int indexOf(T data) = 0;
    virtual void pushHead(T data) = 0;
    virtual void pushTail(T data) = 0;
    virtual T popHead() = 0;
    virtual T popTail() = 0;
    virtual void insertNextTo(int index, T data) = 0;
    virtual void readLine() = 0;
};

#endif