#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename Type>
struct Node {
	Type info;
	Node *link;
};

template <typename Type>
class UnorderedLinkedList {
	Node<Type> *head = NULL;
	Node<Type> *last = NULL;
public:
	UnorderedLinkedList();
	bool search(const Type&) const;
	void insertFirst(const Type&);
	void insertLast(const Type&);
	void deleteNode(const Type&);
	void divideList(Node<Type>*, Node<Type>*&);
	void print() const;
	Node<Type>* mergeList(Node<Type>*&, Node<Type>*);
	void recursiveSort(Node<Type>*&);
	void mergeSort();
};

template <typename Type>
void UnorderedLinkedList<Type>::print() const {
	Node<Type> *current = NULL;
	int count = 0;
	if (head != NULL) {
		current = head;
		cout << current->info;
		count++;
	}
	while (current->link != NULL) {
		current = current ->link;
		cout << " " << current->info;
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}

template <typename Type>
bool UnorderedLinkedList<Type>::search(const Type &item) const {
	Node<Type> *current;
	current = head;
	while (current != NULL) {
		if (current->info == item) {
			return true;
		}
		else {
			current = current->link;
		}
	}
	if (current == NULL) {
		return false;
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::insertFirst(const Type &item) {
	Node<Type> *current;
	current = new Node<Type>;
	current->info = item;
	current->link = head;
	head = current;
	if (last == NULL) {
		last = head;
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::insertLast(const Type &item) {
	Node<Type> *current;
	current = new Node<Type>;
	current->info = item;
	current->link = NULL;
	if (last == NULL) {
		last = current;
		head = last;
	}
	else {
		last->link = current;
		last = last->link;
	}
}

template <typename Type>
UnorderedLinkedList<Type>::UnorderedLinkedList() {
	head = NULL;
	last = NULL;
}

template <typename Type>
void UnorderedLinkedList<Type>::divideList(Node<Type> *first1, Node<Type> *&first2) {
	Node<Type> *middle, *current;
	if (first1 == NULL) { //list is empty
		first2 = NULL;
	}
	else if (first1->link == NULL) { //list only has one node
		first2 = NULL;
	}
	else {
		middle = first1;
		current = first1->link;
		if (current != NULL) {
			current = current->link;
		}
		while (current != NULL) {
			middle = middle->link;
			current = current->link;
			if (current != NULL) {
				current = current->link;
			}
		}
		first2 = middle->link; //points to first node of second sublist
		middle->link = NULL; //link of last node of first sublist set to null
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::deleteNode(const Type &item) {
	Node<Type> *current, *trailCurrent;
	bool found = false;
	current = head;
	while (current != NULL) {
		if (current->info == item) {
			found = true;
			if (current == head) {
				current = current->link;
				delete head;
				head = current;
				count--;
				break;
			}
			else {
				trailCurrent->link = current->link;
				if (current == last) {
					last = trailCurrent;
				}
				delete current;
				count--;
				break;
			}
		}
		else {
			trailCurrent = current;
			current = current->link;
		}
	}
	if (!found) {
		cout << "Item does not exist\n";
	}
}

template <typename Type>
Node<Type>* UnorderedLinkedList<Type>::mergeList(Node<Type> *&first1, Node<Type> *first2) {
	Node<Type> *lastSmall, *newHead;
	if (first1 == NULL) { //first sublist is empty
		return first2;
	}
	else if (first2 == NULL) { //second sublist is empty
		return first1;
	}
	else {
		if (first1->info < first2->info) {
			newHead = first1;
			first1 = first1->link;
			lastSmall = newHead;
		}
		else {
			newHead = first2;
			first2 = first2->link;
			lastSmall = newHead;
		}
		while ((first1 != NULL) && (first2 != NULL)) {
			if (first1->info < first2->info) {
				lastSmall->link = first1;
				lastSmall = lastSmall->link;
				first1 = first1->link;
			}
			else {
				lastSmall->link = first2;
				lastSmall = lastSmall->link;
				first2 = first2->link;
			}
		}
		if (first1 == NULL) { //first sublist is processed first
			lastSmall->link = first2;
		}
		else { //second sublist is processed first
			lastSmall->link = first1;
		}
		return newHead;
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::recursiveSort(Node<Type> *&ihead) {
	Node<Type> *otherHead;
	otherHead = new Node<Type>;
	if (ihead != NULL) {
		if (ihead->link != NULL) {
			divideList(ihead, otherHead);
			recursiveSort(ihead);
			recursiveSort(otherHead);
		}
		if (otherHead->link == NULL) {
			head = mergeList(head, otherHead);
		}
	}
}

template <typename Type>
void UnorderedLinkedList<Type>::mergeSort() {
	recursiveSort(head);
	if (head == NULL) {
		last = NULL;
	}
	else {
		last = head;
		while (last->link != NULL) {
			last = last->link;
		}
	}
}

#endif