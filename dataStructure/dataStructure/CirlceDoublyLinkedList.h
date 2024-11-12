#pragma once
#include <iostream>
using namespace std;

template <class TYPE> class CircleDoublyList {
public:
	CircleDoublyList();
	~CircleDoublyList();
public:
	void PrintList();
	void InsertFront(TYPE data);
	void InsertBack(TYPE data);
	void DeleteData(TYPE data);
protected:
	struct Node {
		Node* pPre;
		TYPE data;
		Node* pNext;
	};
	Node* head;
};

template<class TYPE>
CircleDoublyList<TYPE>::CircleDoublyList()
{
	head = new Node;
	head->pPre = nullptr;
	head->pNext = nullptr;
}

template<class TYPE>
CircleDoublyList<TYPE>::~CircleDoublyList()
{
	Node* cur = head->pNext;
	while (cur != head) {
		Node* temp;
		temp = cur;
		cur = cur->pNext;
		delete temp;
	}
	delete head;
}

template<class TYPE>
void CircleDoublyList<TYPE>::PrintList()
{
	Node* cur = head->pNext;
	while (cur != head) {
		cout << cur->data << endl;
		cur = cur->pNext;
	}
}

template<class TYPE>
void CircleDoublyList<TYPE>::InsertFront(TYPE data)
{
	if (head->pNext == nullptr) {
		Node* new_Node = new Node;
		new_Node->data = data;
		head->pNext = new_Node;
		new_Node->pPre = head;
		new_Node->pNext = head;
		head->pPre = new_Node;
	}
	else {
		Node* new_Node = new Node;
		new_Node->data = data;
		new_Node->pNext = head->pNext;
		new_Node->pPre = head;
		head->pNext->pPre = new_Node;
		head->pNext = new_Node;
	}
}

template<class TYPE>
void CircleDoublyList<TYPE>::InsertBack(TYPE data)
{
	if (head->pNext == nullptr) {
		Node* new_Node = new Node;
		new_Node->data = data;
		head->pNext = new_Node;
		new_Node->pPre = head;
		new_Node->pNext = head;
		head->pPre = new_Node;
	}
	else {
		Node* new_Node = new Node;
		new_Node->data = data;
		head->pPre->pNext = new_Node;
		new_Node->pPre = head->pPre;
		new_Node->pNext = head;
		head->pPre = new_Node;
	}
}

template<class TYPE>
void CircleDoublyList<TYPE>::DeleteData(TYPE data)
{
	Node* cur = head->pNext;
	while (cur != head) {
		if (cur->data == data) {
			Node* temp = cur;
			cur->pPre->pNext = cur->pNext;
			cur->pNext->pPre = cur->pPre;
			cur = cur->pNext;
			delete temp;
		}
		else {
			cur = cur->pNext;
		}
		
	}
}
