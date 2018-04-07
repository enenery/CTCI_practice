#include <iostream>
#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include "StackLL.h"
using namespace std;

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

	void destroyTreeDummy();
	void destroyTree(binaryTreeNode<x> *&p);

	void preorderDummy();
	void preorder(binaryTreeNode<x> *p);

	void inorderDummy();
	void inorder(binaryTreeNode<x> *p);

	void postorderDummy();
	void postorder(binaryTreeNode<x> *p);

	int getHeightDummy();
	int getHeight(binaryTreeNode<x> *p);
	int max(int x, int y);


protected:
	binaryTreeNode<x> *root;
	


};
#endif // !BinaryTree_hpp
