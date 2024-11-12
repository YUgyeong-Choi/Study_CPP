#pragma once
#include <iostream>
using namespace std;

template <class TYPE> class DoubleList {
public:
	DoubleList();
	~DoubleList();
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
	Node* tail;
	int countList;
};

template<class TYPE>
DoubleList<TYPE>::DoubleList()
{
	head = new Node;
	tail = new Node;
	head->pPre = nullptr;
	tail->pNext = nullptr;
	head->pNext = tail;
	tail->pPre = head;
	countList = 0;
}

template<class TYPE>
DoubleList<TYPE>::~DoubleList()
{
	Node* cur = head->pNext;
	while (cur->pNext != nullptr) {
		Node* Temp = cur;
		cur = cur->pNext;
		delete Temp;
	}

	delete head;
	delete tail;
}

template<class TYPE>
void DoubleList<TYPE>::PrintList()
{
	Node* cur = head->pNext;
	while (cur->pNext != nullptr) {
		cout << cur->data << endl;
		cur = cur->pNext;
	}
}

template<class TYPE>
void DoubleList<TYPE>::InsertFront(TYPE data)
{
	Node* new_Node = new Node;
	new_Node->data = data;
	new_Node->pNext = head->pNext;
	head->pNext = new_Node;
	new_Node->pPre = new_Node->pNext->pPre;
	new_Node->pNext->pPre = new_Node;
	countList++;
}

template<class TYPE>
void DoubleList<TYPE>::InsertBack(TYPE data)
{
	Node* new_Node = new Node;
	new_Node->data = data;
	new_Node->pNext = tail;
	tail->pPre->pNext = new_Node;
	new_Node->pPre = tail->pPre;
	tail->pPre = new_Node;
	countList++;
}

template<class TYPE>
void DoubleList<TYPE>::DeleteData(TYPE data) 
{
	if (countList == 0) return;

	Node* cur = head->pNext;
	while (cur->pNext != nullptr) {
		if (cur->data == data) {
			cur->pPre->pNext = cur->pNext;
			cur->pNext->pPre = cur->pPre;
			Node* temp = cur;
			delete temp;
		}
		cur = cur->pNext;
	}
}
