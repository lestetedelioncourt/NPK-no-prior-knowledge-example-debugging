#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unorderedLinkedList.h"

using namespace std;

int main() {
	UnorderedLinkedList<int> list1;
	for (int i = 0; i < 10; i++) {
		list1.insertLast((rand() + time(0)) % 100);
	}
	list1.print();

	list1.mergeSort();
	list1.print();

	return 0;
}