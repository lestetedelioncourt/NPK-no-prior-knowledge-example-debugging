#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H
#include <iostream>

using namespace std;

template <typename eType>
struct Node {
	eType info;
	Node<eType> *leftLink;
	Node<eType> *rightLink;
};

template <typename eType>
class BinaryTree {
protected:
	Node<eType> *root;
public:
	const BinaryTree<eType>& operator=(const BinaryTree<eType>&); //copy assignment operator
	bool isEmpty() const; //
	void inorderTraversal() const; //
	void preorderTraversal() const; //
	void postorderTraversal() const; //
	int treeHeight() const; //
	int treeNodeCount() const; //
	int treeLeafCount() const; //
	void destroyTree(); //
	virtual bool search(const eType&) const = 0;
	virtual void insert(const eType&) = 0;
	virtual void deleteNode(const eType&) = 0;
	BinaryTree(const BinaryTree<eType>&);
	BinaryTree();
	~BinaryTree();
private:
	void copyTree(Node<eType>* &, Node<eType>*);
	void destroy(Node<eType>* &);
	void inorder(Node<eType>*) const;
	void preorder(Node<eType>*) const;
	void postorder(Node<eType>*) const;
	int height(Node<eType>*) const;
	int max(int, int) const;
	int nodeCount(Node<eType>*) const;
	int leafCount(Node<eType>*) const;
};

template <typename eType>
bool BinaryTree<eType>::isEmpty() const {
	return (root == NULL);
}

template <typename eType>
BinaryTree<eType>::BinaryTree() {
	root = NULL;
}

template <typename eType>
void BinaryTree<eType>::inorderTraversal() const{
	inorder(root);
}

template <typename eType>
void BinaryTree<eType>::preorderTraversal() const {
	preorder(root);
}

template <typename eType>
void BinaryTree<eType>::postorderTraversal() const {
	postorder(root);
}

template <typename eType>
int BinaryTree<eType>::treeHeight() const {
	return height(root);
}

template <typename eType>
int BinaryTree<eType>::treeNodeCount() const {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + nodeCount(root);
	}
}

template <typename eType>
int BinaryTree<eType>::treeLeafCount() const {
	return leafCount(root);
}

template <typename eType>
void BinaryTree<eType>::inorder(Node<eType> *p) const {
	if (p != NULL) {
		inorder(p->leftLink);
		cout << p->info << " ";
		inorder(p->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::preorder(Node<eType> *p) const {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->leftLink);
		preorder(p->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::postorder(Node<eType> *p) const {
	if (p != NULL) {
		postorder(p->leftLink);
		postorder(p->rightLink);
		cout << p->info << " ";
	}
}

template <typename eType>
int BinaryTree<eType>::height(Node<eType> *p) const {
	if (p == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(p->leftLink), height(p->rightLink));
	}
}

template <typename eType>
int BinaryTree<eType>::max(int x, int y) const {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

template <typename eType>
int BinaryTree<eType>::nodeCount(Node<eType> *p) const {
	int count = 0;
	if (p->leftLink != NULL) {
		count += 1 + nodeCount(p->leftLink);	
	}
	if (p->rightLink != NULL) {
		count += 1 + nodeCount(p->rightLink);
	}
	return count;
}

template <typename eType>
void BinaryTree<eType>::copyTree(Node<eType> *&newRoot, Node<eType> *rhsRoot) {
	if (rhsRoot == NULL) {
		newRoot = NULL;
	}
	else {
		newRoot = new Node<eType>;
		newRoot->info = rhsRoot->info;
		copyTree(newRoot->leftLink, rhsRoot->leftLink);
		copyTree(newRoot->rightLink, rhsRoot->rightLink);
	}
}

template <typename eType>
void BinaryTree<eType>::destroy(Node<eType> *&p) {
	if (p != NULL) {
		destroy(p->leftLink);
		destroy(p->rightLink);
		delete p;
		p = NULL;
	}
}

template <typename eType>
void BinaryTree<eType>::destroyTree() {
	destroy(root);
}

template <typename eType>
BinaryTree<eType>::BinaryTree(const BinaryTree<eType> &rhs) {
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(root, rhs.root);
	}
}

template <typename eType>
BinaryTree<eType>::~BinaryTree() {
	destroy(root);
}

template <typename eType>
const BinaryTree<eType>& BinaryTree<eType>::operator=(const BinaryTree<eType> &rhs) {
	if (root != NULL) {
		destroy(root);
	}
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(root, rhs.root);
	}
}

#endif