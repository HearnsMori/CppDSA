#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <queue>
#include "sll.h"
#include "dll.h"
#include "csll.h"
#include "cdll.h"
#include "ds.h"

using namespace std;
using namespace chrono;

high_resolution_clock::time_point start_point, end_point;

bool firsttime = true;
int inputDataStructure;
int method;
int datatype;

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;
		Node(T val) : data(val), next(nullptr) {}
};

// Array-based Stack
template <typename T>
class StackArr {
	vector<T> s;
	public:
	void push(T val) { s.push_back(val); }
	T pop() {
		if (s.empty()) throw runtime_error("Stack underflow");
		T val = s.back();
		s.pop_back();
		return val;
	}
	void display() {
		for (auto v : s) cout << v << ' ';
		cout << '\n';
	}
};

// Linked List-based Stack
template <typename T>
class StackLL {
	Node<T>* top;
	public:
	StackLL() : top(nullptr) {}
	void push(T val) {
		Node<T>* newNode = new Node<T>(val);
		newNode->next = top;
		top = newNode;
	}
	T pop() {
		if (!top) throw runtime_error("Stack underflow");
		T val = top->data;
		Node<T>* temp = top;
		top = top->next;
		delete temp;
		return val;
	}
	void display() {
		Node<T>* temp = top;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

// Queue
template <typename T>
class Queue {
	queue<T> q;
	public:
	void enqueue(T val) { q.push(val); }
	T dequeue() {
		if (q.empty()) throw runtime_error("Queue underflow");
		T val = q.front(); q.pop(); return val;
	}
	void display() {
		queue<T> temp = q;
		while (!temp.empty()) {
			cout << temp.front() << ' ';
			temp.pop();
		}
		cout << '\n';
	}
};

// Min Heap
template <typename T>
class MinHeap {
	vector<T> heap;
	void heapifyUp(int i) {
		while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
			swap(heap[i], heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
	public:
	void insert(T val) {
		heap.push_back(val);
		heapifyUp(heap.size() - 1);
	}
	void display() {
		for (T v : heap) cout << v << " ";
		cout << endl;
	}
};

// Max Heap
template <typename T>
class MaxHeap {
	vector<T> heap;
	void heapifyUp(int i) {
		while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
			swap(heap[i], heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
	public:
	void insert(T val) {
		heap.push_back(val);
		heapifyUp(heap.size() - 1);
	}
	void display() {
		for (T v : heap) cout << v << " ";
		cout << endl;
	}
};

// Tree Node
template <typename T>
class TreeNode {
	public:
		T val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(T v) : val(v), left(nullptr), right(nullptr) {}
};

// Binary Search Tree
template <typename T>
class Tree {
	TreeNode<T>* root = nullptr;

	TreeNode<T>* insert(TreeNode<T>* node, T val) {
		if (!node) return new TreeNode<T>(val);
		if (val < node->val) node->left = insert(node->left, val);
		else node->right = insert(node->right, val);
		return node;
	}

	void inorder(TreeNode<T>* node) {
		if (!node) return;
		inorder(node->left);
		cout << node->val << ' ';
		inorder(node->right);
	}

	public:
	void insert(T val) { root = insert(root, val); }
	void display() { inorder(root); cout << '\n'; }
};

// Graph (Undirected)
template <typename T>
class Graph {
	map<T, vector<T>> adj;
	public:
	void addEdge(T u, T v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void display() {
		for (auto& pair : adj) {
			cout << pair.first << ": ";
			for (T v : pair.second) cout << v << " ";
			cout << '\n';
		}
	}
};

template<typename T>
void demoArrayStack() {
	int choice;
	T val;
	StackArr<T> arrStack;

	cout << "\n--- INTERACTIVE DEMO: Array Stack ---\n";
	while (true) {
		cout << "\n[Array Stack] 1-Push 2-Pop 3-Display 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Value to push: ";
			cin >> val;
			start_point = high_resolution_clock::now();
			arrStack.push(val);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			cout << "Popped: " << arrStack.pop() << '\n';
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 3) {
			start_point = high_resolution_clock::now();
			arrStack.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template<typename T>
void demoLinkedListStack() {
	int choice;
	T val;
	StackLL<T> llStack;

	cout << "\n--- INTERACTIVE DEMO: Linked List Stack ---\n";
	while (true) {
		cout << "\n[Linked Stack] 1-Push 2-Pop 3-Display 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Value to push: ";
			cin >> val;
			start_point = high_resolution_clock::now();
			llStack.push(val);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			cout << "Popped: " << llStack.pop() << '\n';
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 3) {
			start_point = high_resolution_clock::now();
			llStack.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template<typename T>
void demoQueue() {
	int choice;
	T val;
	Queue<T> q;

	cout << "\n--- INTERACTIVE DEMO: Queue ---\n";
	while (true) {
		cout << "\n[Queue] 1-Enqueue 2-Dequeue 3-Display 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Value to enqueue: ";
			cin >> val;
			start_point = high_resolution_clock::now();
			q.enqueue(val);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			cout << "Dequeued: " << q.dequeue() << '\n';
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 3) {
			start_point = high_resolution_clock::now();
			q.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template<typename T>
void demoMinHeap() {
	int choice;
	T val;
	MinHeap<T> minH;

	cout << "\n--- INTERACTIVE DEMO: Min Heap ---\n";
	while (true) {
		cout << "\n[Min Heap] 1-Insert 2-Display 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Value to insert: ";
			cin >> val;
			start_point = high_resolution_clock::now();
			minH.insert(val);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			minH.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template<typename T>
void demoMaxHeap() {
	int choice;
	T val;
	MaxHeap<T> maxH;

	cout << "\n--- INTERACTIVE DEMO: Max Heap ---\n";
	while (true) {
		cout << "\n[Max Heap] 1-Insert 2-Display 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Value to insert: ";
			cin >> val;
			start_point = high_resolution_clock::now();
			maxH.insert(val);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			maxH.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template<typename T>
void demoTree() {
	int choice;
	T val;
	Tree<T> tree;

	cout << "\n--- INTERACTIVE DEMO: Binary Search Tree ---\n";
	while (true) {
		cout << "\n[Tree] 1-Insert 2-Display (Inorder) 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Value to insert: ";
			cin >> val;
			start_point = high_resolution_clock::now();
			tree.insert(val);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			tree.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template<typename T>
void demoGraph() {
	int choice;
	T u, v;
	Graph<T> graph;

	cout << "\n--- INTERACTIVE DEMO: Undirected Graph ---\n";
	while (true) {
		cout << "\n[Graph] 1-Add Edge 2-Display 0-Exit: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter node 1: ";
			cin >> u;
			cout << "Enter node 2: ";
			cin >> v;
			start_point = high_resolution_clock::now();
			graph.addEdge(u, v);
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else if (choice == 2) {
			start_point = high_resolution_clock::now();
			graph.display();
			end_point = high_resolution_clock::now();
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
		} else {
			break;
		}
	}
}

template <typename T>
void demoSort() {
    int choice;
    vector<T> arr;
    T val;

    cout << "\n--- INTERACTIVE DEMO: Sorting ---\n";
    while (true) {
        cout << "\n[Sorting] 1-Add Element 2-Sort 3-Display 0-Exit: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Value to add: ";
            cin >> val;
            arr.push_back(val);
        } else if (choice == 2) {
            start_point = high_resolution_clock::now();
            // Bubble Sort
            for (size_t i = 0; i < arr.size() - 1; ++i) {
                for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
            end_point = high_resolution_clock::now();
            duration<double, milli> elapsed = end_point - start_point;
            cout << "Time taken: " << elapsed.count() << " ms" << endl;
        } else if (choice == 3) {
            start_point = high_resolution_clock::now();
            for (T item : arr) {
                cout << item << " ";
            }
            cout << endl;
            end_point = high_resolution_clock::now();
            duration<double, milli> elapsed = end_point - start_point;
            cout << "Time taken: " << elapsed.count() << " ms" << endl;
        } else {
            break;
        }
    }
}

template <typename T>
int binarySearch(const vector<T>& arr, T target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Not found
}

template <typename T>
void demoSearch() {
    int choice;
    vector<T> arr;
    T val;
    
    cout << "\n--- INTERACTIVE DEMO: Searching ---\n";
    while (true) {
        cout << "\n[Searching] 1-Add Element 2-Search 3-Display 0-Exit: ";
        cin >> choice;
        cin.ignore(); // To clear the input buffer before reading further input

        if (choice == 1) {
            cout << "Value to add: ";
            cin >> val;
            arr.push_back(val);
        } else if (choice == 2) {
            cout << "Enter value to search: ";
            cin >> val;
            start_point = high_resolution_clock::now();
            int result = binarySearch(arr, val);
            if (result != -1) {
                cout << "Found at index: " << result << endl;
            } else {
                cout << "Not found" << endl;
            }
            end_point = high_resolution_clock::now();
            duration<double, milli> elapsed = end_point - start_point;
            cout << "Time taken: " << elapsed.count() << " ms" << endl;
        } else if (choice == 3) {
            start_point = high_resolution_clock::now();
            for (T item : arr) {
                cout << item << " ";
            }
            cout << endl;
            end_point = high_resolution_clock::now();
            duration<double, milli> elapsed = end_point - start_point;
            cout << "Time taken: " << elapsed.count() << " ms" << endl;
        } else {
            break;
        }
    }
}

void whatMethod() {
	cout << "\n\nWhat method? \n 1 for create (push) \n 2 for read (access) \n 3 for update (change) \n 4 for delete (remove) \n 5 to show length \n 6 for indexOf \n 7 for pushHead \n 8 for pushTail \n 9 for popHead \n 10 for popTail \n 11 for insertNextTo \n 12 for display \n 13 for readOneByOne \n";
}
void whatValue() {
	cout << "What value to create (datatype): ";
}
void whatIndex() {
	cout << "What index (integer): ";
}
void whatNewValue() {
	cout << "What new value (datatype): ";
}
void whatDataType() {
	cout << "What data type? \n 1 for character \n 2 for integer \n 3 for double \n 4 for string \n";
}

template <typename T>
void startMethod(int m, int i) {
	int method = m;
	DS<T>* ds[4];
	ds[0] = new SinglyLinkedList<T>();
	ds[1] = new DoublyLinkedList<T>();
	ds[2] = new CircularSinglyLinkedList<T>();
	ds[3] = new CircularDoublyLinkedList<T>();
	if (i == 4) {
		demoArrayStack<T>();
		return;
	} else if (i == 5) {
		demoLinkedListStack<T>();
		return;
	} else if (i == 6) {
		demoQueue<T>();
		return;
	} else if (i == 7) {
		demoMinHeap<T>();
		return;
	} else if (i == 8) {
		demoMaxHeap<T>();
		return;
	} else if (i == 9) {
		demoGraph<T>();
		return;
	} else if (i == 10) {
		demoTree<T>();
		return;
	} else if (i == 11) {
		demoSort<T>();
		return;
	} else if (i == 12) {
		demoSearch<T>();
		return;
	}
	
	T input;

	while (true) {
		try {
			int index;
			if(method==1) {
				whatValue();
				cin >> input;
				start_point = high_resolution_clock::now();
				ds[i]->createNode(input);
				end_point = high_resolution_clock::now();
			} else if(method==2) {
				whatIndex();
				cin >> index;
				start_point = high_resolution_clock::now();
				cout << ds[i]->readNode(index) << '\n';
				end_point = high_resolution_clock::now();
			} else if(method==3) {
				whatIndex();
				cin >> index;
				whatNewValue();
				cin >> input;
				start_point = high_resolution_clock::now();
				ds[i]->updateNode(index, input);
				end_point = high_resolution_clock::now();
			} else if(method==4) {
				whatIndex();
				cin >> index;
				start_point = high_resolution_clock::now();
				ds[i]->deleteNode(index);
				end_point = high_resolution_clock::now();
			} else if(method==5) {
				cout << ds[i]->length() << '\n';
			} else if(method==6) {
				whatValue();
				cin >> input;
				start_point = high_resolution_clock::now();
				cout << ds[i]->indexOf(input) << '\n';
				end_point = high_resolution_clock::now();
			} else if(method==7) {
				whatValue();
				cin >> input;
				start_point = high_resolution_clock::now();
				ds[i]->pushHead(input);
				end_point = high_resolution_clock::now();
			} else if(method==8) {
				whatValue();
				cin >> input;
				start_point = high_resolution_clock::now();
				ds[i]->pushTail(input);
				end_point = high_resolution_clock::now();
			} else if(method==9) {
				start_point = high_resolution_clock::now();
				cout << ds[i]->popHead() << '\n';
				end_point = high_resolution_clock::now();
			} else if(method==10) {
				start_point = high_resolution_clock::now();
				cout << ds[i]->popTail() << '\n';
				end_point = high_resolution_clock::now();
			} else if(method==11) {
				whatIndex();
				cin >> index;
				whatValue();
				cin >> input;
				start_point = high_resolution_clock::now();
				ds[i]->insertNextTo(index, input);
				end_point = high_resolution_clock::now();
			} else if(method==12) {
				start_point = high_resolution_clock::now();
				ds[i]->display();
				end_point = high_resolution_clock::now();
			} else if(method==13) {
				ds[i]->readLine();
			} else if(method==0) {
				break;
			} else {
				whatMethod();
				cout <<" 0 for end \n";
				cin >> method;
				continue;
			}
			duration<double, milli> elapsed = end_point - start_point;
			cout << "Time taken: " << elapsed.count() << " ms" << endl;
			whatMethod();
			cout <<" 0 for end \n";
			cin >> method;
		} catch (const exception& e) {
			cout << "\n\nCaught exception: " << e.what() << endl;
			whatMethod();
			cout <<" 0 for end \n";
			cin >> method;
		}
	}
}

void initMethod(int i) {
	whatDataType();
	cin >> datatype;
	if (i < 4) {
		whatMethod();
		cin >> method;
	}
	switch(datatype) {
		case 1: startMethod<char>(method, i); break;
		case 2: startMethod<int>(method, i); break;
		case 3: startMethod<double>(method, i); break;
		case 4: startMethod<string>(method, i); break;
	}
}


int main() {
	while(true) {
		cout << "\n\nSelect an option:\n";
		cout << " 0 - Singly Linked List\n";
		cout << " 1 - Doubly Linked List\n";
		cout << " 2 - Circular Singly Linked List\n";
		cout << " 3 - Circular Doubly Linked List\n";
		cout << " 4 - Array Stack\n";
		cout << " 5 - LinkedList Stack\n";
		cout << " 6 - Queue\n";
		cout << " 7 - Min Heap\n";
		cout << " 8 - Max Heap\n";
		cout << " 9 - Graph\n";
		cout << " 10 - Tree\n";
		cout << "Algorithm:\n";
		cout << " 11 - Sorting\n";
		cout << " 12 - Searching\n";

		cout << "\nWhat data structure would you like to work on: ";
		cin >> inputDataStructure;
		initMethod(inputDataStructure);
	}
	return 0;
}