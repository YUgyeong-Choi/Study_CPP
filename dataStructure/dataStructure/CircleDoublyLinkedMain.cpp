#include "CirlceDoublyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
	CircleDoublyList<int> aa;

	aa.InsertFront(10);
	aa.InsertFront(20);
	aa.InsertFront(30);
	aa.PrintList();

	cout << "==============================" << endl;

	aa.InsertBack(50);
	aa.InsertBack(20);
	aa.PrintList();
	cout << "==============================" << endl;
	aa.DeleteData(20);
	aa.PrintList();

	return 0;
}