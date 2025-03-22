#ifndef MINHEAP_H
#define MINHEAP_H
#include <queue>

template <typename T>
class MinHeap {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    void create(int data);
    void read();
    void deleteNode();
};
#endif
