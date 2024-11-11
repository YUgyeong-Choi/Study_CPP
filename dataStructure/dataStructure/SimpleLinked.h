#pragma once
#include <iostream>
using namespace std;

template <class TYPE> class SimpleList {
public:
	SimpleList();
	~SimpleList();
public:
	void printList();
	void insert(TYPE new_data);
	void deleteNode(TYPE new_data);
protected:
	struct Node {
		TYPE data;
		Node* pNext;
	};
	Node* head;
};

template<class TYPE>
SimpleList<TYPE>::SimpleList()
{
	head = new Node();
	head->pNext = nullptr;
}

template<class TYPE>
SimpleList<TYPE>::~SimpleList()
{
	Node* cur = head->pNext;
	while (cur->pNext != nullptr) {
		Node* temp = cur;
		cur = cur->pNext;
		delete temp;
	}
}

template<class TYPE>
void SimpleList<TYPE>::printList()
{
	Node* cur = head->pNext;
	while (cur->pNext != nullptr) {
		cout << cur->data << endl;
		cur = cur->pNext;
	}
	cout << cur->data << endl;
}

template<class TYPE>
void SimpleList<TYPE>::insert(TYPE new_data)
{
	if (head->pNext == nullptr) {
		Node* new_Node = new Node();
		new_Node->data = new_data;
		new_Node->pNext = nullptr;
		head->pNext = new_Node;
	}
	else {
		Node* new_Node = new Node();
		new_Node->data = new_data;
		new_Node->pNext = head->pNext;
		head->pNext = new_Node;
	}
}

template<class TYPE>
void SimpleList<TYPE>::deleteNode(TYPE new_data)
{
	Node* cur = head;
	while (cur->pNext != nullptr) {
		if (cur->pNext->data == new_data) {
			Node* temp = cur->pNext;
			cur->pNext = cur->pNext->pNext; 
			delete temp;  
		}
		else {
			cur = cur->pNext; 
		}
	}
}
