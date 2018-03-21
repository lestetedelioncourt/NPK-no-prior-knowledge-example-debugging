#include <iostream>
#include <ctime>
#include <cstdlib>
#include "searchTree.h"

using namespace std;

int main() {
	int num = 0, count = 0;
	SearchTree<int> tree1;
	while (count < 10) {
		num = (rand() + time(0)) % 1000 + 1;
		//cout << num << " ";
		tree1.insert(num);
		count++;
	}

	//cout << endl;
	cout << "Node count: " << tree1.treeNodeCount() << endl;
	tree1.inorderTraversal();
	cout << endl;
	/*tree1.postorderTraversal();
	cout << endl;
	tree1.preorderTraversal();
	cout << endl;*/
	cout << "\n\nEnter a number to find: ";
	cin >> num;
	cout << endl;
	tree1.search(num);
	cout << "\n\nEnter a number to be deleted: ";
	cin >> num;
	cout << endl;
	tree1.deleteNode(num);
	cout << "Node count: " << tree1.treeNodeCount() << endl;

	tree1.inorderTraversal();
	cout << endl;

	SearchTree<int> tree2 = tree1;
	tree2.inorderTraversal();
	system("PAUSE");
	return 0;
}