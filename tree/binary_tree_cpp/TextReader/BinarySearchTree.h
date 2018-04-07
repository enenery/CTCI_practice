#pragma once
#include <iostream>
using namespace std;
#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include "BinaryTree.h"

template <class x>
class BinarySearchTree: public BinaryTree<x>
{
public:
	BinarySearchTree();
	bool search(x item);
	void insert(x item);
	void deleteNode(x item);

private:
	void deleteFromTree(binaryTreeNode<x> *&p);

};
#endif // !BinarySearchTree_hpp

