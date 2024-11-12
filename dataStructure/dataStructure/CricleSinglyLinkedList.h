#pragma once
#include <iostream>
using namespace std;

template <class TYPE> class CricleSinglyList{
public:
	CricleSinglyList();
	~CricleSinglyList();
public:
	void PrintList();
	void InsertFront(TYPE data);
	void DeleteData(TYPE data);
protected:
	struct Node {
		TYPE data;
		Node* pNext;
	};
	Node* head;
};

template<class TYPE>
CricleSinglyList<TYPE>::CricleSinglyList()
{
	head = new Node;
	head->pNext = nullptr;
}

template<class TYPE>
CricleSinglyList<TYPE>::~CricleSinglyList()
{
	Node* cur = head->pNext;
	while (cur != head) {
		Node* temp = cur;
		cur = cur->pNext;
		delete temp;
	}
	delete head;
}

template<class TYPE>
void CricleSinglyList<TYPE>::PrintList()
{
	Node* cur = head->pNext;
	while (cur != head) {
		cout << cur->data << endl;
		cur = cur->pNext;
	}
}

template<class TYPE>
void CricleSinglyList<TYPE>::InsertFront(TYPE data)
{
	if (head->pNext == nullptr) {
		Node* new_Node = new Node;
		new_Node->data = data;
		new_Node->pNext = head;
		head->pNext = new_Node;
	}
	else {
		Node* new_Node = new Node;
		new_Node->data = data;
		new_Node->pNext = head->pNext;
		head->pNext = new_Node;
	}
}

template<class TYPE>
void CricleSinglyList<TYPE>::DeleteData(TYPE data)
{
	Node* cur = head;
	 do{
		if (cur->pNext->data == data) {
			Node* temp = cur->pNext;
			cur->pNext = cur->pNext->pNext;
			delete temp;
		}
		cur = cur->pNext;
	 } while (cur != head);
}
