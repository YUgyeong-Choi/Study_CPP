#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int main() {
	SingleList<int> aa;
	aa.insert(10);
	aa.insert(20);
	aa.insert(30);
	aa.insert(40);
	aa.insert(20);
	aa.insert(60);
	aa.printList();

	cout << "============" << endl;
	aa.deleteNode(20);
	aa.printList();

	return 0;
}