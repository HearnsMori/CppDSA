#include <iostream>
#include "sll.h"
using namespace std;

string inputDataStructure;
	
void whatMethod() {
	cout << "What method? \n 1 for create (push) \n 2 for read (access) \n 3 for update (change) \n 4 for delete (remove) \n ";
}
void whatValue() {
	cout << "What value to create (datetype): ";
}
void whatIndex() {
	cout << "What index (integer): ";
}
void whatNewValue() {
	cout << "What new value (datetype): ";
}
void whatDataType() {
	cout << "What data type? \n 1 for character \n 2 for integer \n 3 for double \n 4 for string \n ";
}
bool firsttime = true;
template <typename T>
void startMethod(int m) {
	int method = m;
	SinglyLinkedList<T> sll;
	T input;
	while (true) {
	int index;
	if(method==1) {
                whatValue();
                cin >> input;
                sll.create(input);
        } else if(method==2) {
                whatIndex();
                cin >> index;
                cout << sll.read(index);
        } else if(method==3) {
                whatIndex();
                cin >> index;
                whatNewValue();
                cin >> input;
                sll.update(index, input);
        } else if(method==4) {
                whatIndex();
                cin >> input;
                sll.deleteSNode(index);
        } else {
		sll.display();
		break;
	}
	whatMethod();
	cout <<"0 for end \n ";
        cin >> method;
	}
}
//DataStructure Code Logic
void methodSinglyLinkedList() {
	int method;
	int datatype;
	whatDataType();
	cin >> datatype;
	whatMethod();
        cin >> method;
	switch(datatype) {
		case 1:
			startMethod<char>(method);
			break;
		case 2:
			startMethod<int>(method);
			break;
		case 3:
			startMethod<double>(method);
			break;
		case 4:
			startMethod<string>(method);
			break;
	}
}
void methodDoublyLinkedList() {
        
}
void methodCircularLinkedList() {
	
}
void methodQueue() {
	
}
void methodStack() {
}
void methodMaxHeap() {
}
void methodMinHeap() {
}
void methodGraph() {
}
void methodTree() {
}
void methodSorting() {
	
}
void methodSearching() {

}
int main() {
	while(true) {
	cout << "What data structure would you like to work on: ";
	cin >> inputDataStructure;
        if (inputDataStructure == "SLL") {
                methodSinglyLinkedList();
        } else if (inputDataStructure == "DLL") {    
		methodDoublyLinkedList();                               } else if (inputDataStructure == "CLL") {                               methodCircularLinkedList();
        } else if (inputDataStructure == "Q") {
                methodQueue();
	} else if (inputDataStructure == "S") {
                methodStack();
        } else if (inputDataStructure == "MaxH") {
                methodMaxHeap();
        } else if (inputDataStructure == "MinH") {  
		methodMinHeap();
        } else if (inputDataStructure == "G") {
                methodGraph();
        } else if (inputDataStructure == "T") {
                methodTree();
        } else if (inputDataStructure == "Sorting") {                           methodSorting();                                        } else if (inputDataStructure == "Searching") {
                methodSearching();
        } else {
                cout << "Invalid data structure selection.\
n";
        }
	}
        return 0;
}
