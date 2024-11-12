#include "CricleSinglyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
	CricleSinglyList<int> aa;
	aa.InsertFront(10);
	aa.InsertFront(20);
	aa.InsertFront(30);
	aa.InsertFront(40);
	aa.InsertFront(20);
	aa.InsertFront(60);
	aa.PrintList();

	cout << "============" << endl;
	aa.DeleteData(20);
	aa.PrintList();

	return 0;
}
