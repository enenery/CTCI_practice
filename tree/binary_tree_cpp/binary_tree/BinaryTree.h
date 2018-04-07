#include <iostream>
using namespace std;
#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

template <class x>
struct binaryTreeNode
{
	x info;
	binaryTreeNode<x> *left;
	binaryTreeNode<x> *right;
};

template <class x>
class BinaryTree
{

public:
	BinaryTree();
	~BinaryTree();
	void copy(binaryTreeNode<x> *p, binaryTreeNode<x> *&r);
	bool isEmpty();
	void destroyTree(binaryTreeNode<x> *&p);
	void preorder(binaryTreeNode<x> *p);
	void inorder(binaryTreeNode<x> *p);
	void postorder(binaryTreeNode<x> *p);


protected:
	binaryTreeNode<x> *root;


};
#endif // !BinaryTree_hpp
