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
	bool searchRecDummy(x item);
	bool searchRec(x item, binaryTreeNode<x> *&p);

	void insert(x item);
	void insertRecDummy(x item);
	void insertRec(x item, binaryTreeNode<x> *&p);
	void deleteNode(x item);
	
	void printDescendantsRecDummy(x item);
	void printDescendantsRec(x item, binaryTreeNode<x> *&p);

	int findNumOfDescendants(x item);
	int addAndTravel(binaryTreeNode<x> *&p);

	void printAscendantsRecDummy(x item);
	void printAscendantsRec(x item, binaryTreeNode<x> *&p);

	int findNumOfAscendants(x item);
	int numOfAscendantsRec(x item, binaryTreeNode<x> *&p);

	void printLargestRecDummy();
	void printLargestRec(binaryTreeNode<x> *&p);
	void getMax(int &max);
	void getMax(int &max, binaryTreeNode<x> *p);

	void printSmallestRecDummy();
	void printSmallestRec(binaryTreeNode<x> *&p);

	void printLargerRecDummy(x item);
	void printLargerRec(x item, binaryTreeNode<x> *&p);

	void printSmallerRecDummy(x item);
	void printSmallerRec(x item, binaryTreeNode<x> *&p);

	void countLeavesDummy();
	int countLeaves(binaryTreeNode<x> *p);
	void printLeavesDummy();
	void printLeaves(binaryTreeNode<x> *p);

	void countNodeWatLeastOneChildDummy();
	int countNodeWatLeastOneChild(binaryTreeNode<x> *&p);
	void printNodeWatLeastOneChildDummy();
	void printNodeWatLeastOneChild(binaryTreeNode<x> *&p);

	void countNodeWexactlyTwoChildrenDummy();
	int countNodeWexactlyTwoChildren(binaryTreeNode<x> *&p);
	void printNodeWexactlyTwoChildrenDummy();
	void printNodeWexactlyTwoChildren(binaryTreeNode<x> *&p);
	
	void countNodeWexactlyOneChildDummy();
	int countNodeWexactlyOneChild(binaryTreeNode<x> *&p);
	void printNodeWexactlyOneChildDummy();
	void printNodeWexactlyOneChild(binaryTreeNode<x> *&p);

	int getSumDummy();
	int getSum(binaryTreeNode<x> *&p);
	
	void inorderIterative();
	void preorderIterative();
	void postorderIterative();

private:
	void deleteFromTree(binaryTreeNode<x> *&p);
};
#endif // !BinarySearchTree_hpp

