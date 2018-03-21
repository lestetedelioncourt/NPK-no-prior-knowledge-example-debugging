#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <iostream>
#include "binaryTreeType.h"

using namespace std;

template <typename eType>
class SearchTree : public BinaryTree<eType> {
public:
	bool search(const eType&) const;
	void insert(const eType&);
	void deleteNode(const eType&);
private:
	void deleteFromTree(Node<eType> *&);
};

template <typename eType>
bool SearchTree<eType>::search(const eType &item) const {
	Node<eType> *current;
	bool found = false;
	if (root == NULL) {
		cout << "The tree is empty.\n";
	}
	else {
		current = root;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else if (current->info > item) {
				current = current->leftLink;
			}
			else {
				current = current->rightLink;
			}
		}
	}
	if (found) {
		cout << "\nfound item\n";
	}
	return found;
}

template <typename eType>
void SearchTree<eType>::insert(const eType &item) {
	Node<eType> *current, *trail, *newNode;
	newNode = new Node<eType>;
	newNode->info = item;
	newNode->leftLink = NULL;
	newNode->rightLink = NULL;
	if (root == NULL) {
		root = newNode;
	}
	else {
		current = root;
		while (current != NULL) {
			trail = current;
			if (current->info == item) {
				cout << "Item is already in tree, no duplicates.\n";
				return;
			}
			else if (current->info > item) {
				current = current->leftLink;
			}
			else {
				current = current->rightLink;
			}
		}
		if (trail->info > item) {
			trail->leftLink = newNode;
		}
		else {
			trail->rightLink = newNode;
		}
	}
}

template <typename eType>
void SearchTree<eType>::deleteFromTree(Node<eType> *&p) {
	Node<eType> *current, *trail, *temp;
	if (p == NULL) {
		cout << "The node is NULL.\n";
	}
	else if ((p->leftLink == NULL) && (p->rightLink == NULL)) {
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->leftLink == NULL) {
		temp = p;
		p = temp->rightLink;
		delete temp;
	}
	else if (p->rightLink == NULL) {
		temp = p;
		p = temp->leftLink;
		delete temp;
	}
	else {
		current = p->leftLink;
		trail = NULL;
		while (current->rightLink != NULL) {
			trail = current;
			current = current->rightLink;
		}
		p->info = current->info;
		if (trail == NULL) {
			p->leftLink = current->leftLink;
		}
		else {
			trail->rightLink = current->leftLink;
			delete current;
		}
	}
}

template <typename eType>
void SearchTree<eType>::deleteNode(const eType &item) {
	Node<eType> *current, *trail;
	bool found = false;
	if (root == NULL) {
		cout << "The tree is empty\n";
	}
	else {
		current = root;
		trail = root;
		while ((current != NULL) && (!found)) {
			if (current->info == item) {
				found = true;
			}
			else {
				trail = current;
				if (current->info > item) {
					current = current->leftLink;
				} 
				else {
					current = current->rightLink;
				}
			}
		}
		if (current == NULL) {
			cout << "Item is not found in tree\n";
		}
		else if (found) {
			if (current == root) {
				deleteFromTree(root);
			}
			else if (trail->info > item) {
				deleteFromTree(trail->leftLink);
			}
			else {
				deleteFromTree(trail->rightLink);
			}
		}
		else {
			cout << "Item not found in tree\n";
		}
	}
}

#endif