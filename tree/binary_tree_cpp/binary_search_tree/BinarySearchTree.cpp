#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "StackLL.h"
#include <iostream>
using namespace std;
#include <string>


template <class x>
BinarySearchTree<x>::BinarySearchTree():BinaryTree()
{
	
}

template <class x>
bool BinarySearchTree<x>::search(x item)
{
	binaryTreeNode<x> *current;
	bool found = false;

	if (root = NULL)
		cout << "\nNo item found";
	else
	{
		current = root;

		while (current != NULL & !found)
		{
			if (current->info == item)
				found = true;
			else if (current->info > item)
				current = current->left;
			else
				current = current->right;
		}
	}

	return found;
}

template <class x>
bool BinarySearchTree<x>::searchRecDummy(x item)
{
	if (root != NULL)
	{
		return searchRec(item, root);
	}
	else return false;
}

template <class x>
bool BinarySearchTree<x>::searchRec(x item, binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->info == item)
			return true;
		else
		{
			if (item < p->info)
				searchRec(item, p->left);
			else
				searchRec(item, p->right);
		}
	}
	else return false;
}


template <class x>
void BinarySearchTree<x>::insert(x item)
{
	binaryTreeNode<x> *current;
	binaryTreeNode<x> *trailing;
	binaryTreeNode<x> *newNode;

	newNode = new binaryTreeNode<x>;
	newNode->info = item;
	newNode->left = NULL;
	newNode->right = NULL;
	
	if (root == NULL)
		root = newNode;
	else
	{
		current = root;

		while (current != NULL)
		{
			trailing = current;

			if (current->info == item)
			{
				cout << "\nDuplicates are not allowed";
				return;
			}
			else if (current->info > item)
				current = current->left;
			else
				current = current->right;
		}

		if (trailing->info > item)
			trailing->left = newNode;
		else
			trailing->right = newNode;
	}
}

template <class x>
void BinarySearchTree<x>::insertRecDummy(x item)
{
	if (root != NULL)
	{
		binaryTreeNode<x> *&current = root;
		insertRec(item, current);
		cout << "\ncurrent = " << current->info;
	}
		
}

template <class x>
void BinarySearchTree<x>::insertRec(x item, binaryTreeNode<x> *&p)
{
	if (p == NULL)
	{
		p = new binaryTreeNode<x>;
		p->info = item;
		p->left = p->right = NULL;
	}
	else
	{
		if (item < p->info)
			insertRec(item, p->left);
		else
		{
			if (item > p->info)
				insertRec(item, p->right);
			else
				cout << "\nNo duplicates allowed.";
		}
	}
}

template <class x>
void BinarySearchTree<x>::deleteFromTree(binaryTreeNode<x> *&p)
{
	binaryTreeNode<x> *current;
	binaryTreeNode<x> *trailing;
	binaryTreeNode<x> *temp;

	if (p == NULL)
		cout << "\nthe node to be deleted is NULL";
	else if (p->left == NULL && p->right == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->left == NULL)
	{
		temp = p;
		p = temp->right;
		delete temp;
	}
	else if (p->right == NULL)
	{
		temp = p;
		p = temp->left;
		delete temp;
	}
	else
	{
		current = p->left;
		trailing = NULL;

		while (current->right != NULL)
		{
			trailing = current;
			current = current->right;
		}

		p->info = current->info;

		if (trailing == NULL)
			p->left = current->left;
		else
			trailing->right = current->left;

		delete current;
	}
}

template <class x>
void BinarySearchTree<x>::deleteNode(x item)
{
	binaryTreeNode<x> *current;
	binaryTreeNode<x> *trailing;
	bool found = false;

	if (root == NULL)
		cout << "\nCannot delete from the empty tree.";
	else
	{
		current = root;
		trailing = root;

		while (current != NULL && !found)
		{
			if (current->info == item)
				found = true;
			else
			{
				trailing = current;
				
				if (current->info > item)
					current = current->left;
				else
					current = current->right;
			}
		}

		if (current == NULL)
			cout << "\nThe to-be-deleted item not found in the tree.";
		else if (found)
		{
			if (current == root)
				deleteFromTree(root);
			else if (trailing->info > item)
				deleteFromTree(trailing->left);
			else
				deleteFromTree(trailing->right);
		}
	}
}

template <class x>
void BinarySearchTree<x>::printDescendantsRecDummy(x item)
{
	if (root != NULL)
		printDescendantsRec(item, root);
}

template <class x>
void BinarySearchTree<x>::printDescendantsRec(x item, binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->info == item)
		{
			if (p->left != NULL)
				postorder(p->left);
			if (p->right != NULL)
				postorder(p->right);

		}
		else
		{
			if (item < p->info)
				printDescendantsRec(item, p->left);
			else
				printDescendantsRec(item, p->right);
		}
	}
	else
		cout << "\nitem not found.";
	
}

template <class x>
int BinarySearchTree<x>::findNumOfDescendants(x item)
{
	binaryTreeNode<x> *current = root;

	while (current != NULL)
	{
		if (current->info == item)
			return addAndTravel(current->left) + addAndTravel(current->right);
		else
		{
			if (item < current->info)
				current = current->left;
			else
				current = current->right;
		}
	}
	return 0;
}

template <class x>
int BinarySearchTree<x>::addAndTravel(binaryTreeNode<x> *&p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + addAndTravel(p->left) + addAndTravel(p->right);
}


template <class x>
void BinarySearchTree<x>::printAscendantsRecDummy(x item)
{
	if (root != NULL)
	{
		if (searchRec(item, root))
			printAscendantsRec(item, root);
	}
}

template <class x>
void BinarySearchTree<x>::printAscendantsRec(x item, binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->info != item)
		{
			cout << p->info << " ";
			if (item < p->info)		
				printAscendantsRec(item, p->left);
			else				
				printAscendantsRec(item, p->right);
				
		}
	}
}

template <class x>
int BinarySearchTree<x>::numOfAscendantsRec(x item, binaryTreeNode<x> *&p)
{
	if (p == NULL)
		return 0;
	else
	{
		if (item == p->info)
			return 0;
		else
		{
			if (item < p->info)
				return 1 + numOfAscendantsRec(item, p->left);
			else
				return 1 + numOfAscendantsRec(item, p->right);
		}
		
	}
}

template <class x>
int BinarySearchTree<x>::findNumOfAscendants(x item)
{
	if (root != NULL)
	{
		if (searchRec(item, root))		
			return numOfAscendantsRec(item, root);
		else
		{
			cout << "\nitem not found.";
			return 0;
		}
	}
	else
	{
		cout << "\nempty tree.";
		return 0;
	}
}



template <class x>
void BinarySearchTree<x>::printLargestRecDummy()
{
	if (root != NULL)
		return printLargestRec(root);
}

template <class x>
void BinarySearchTree<x>::printLargestRec(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->right == NULL && p->left == NULL)
			cout << p->info << " ";
		else
		    printLargestRec(p->right);
	}				
}

template <class x>
void BinarySearchTree<x>::getMax(int &max)
{
	if (root != NULL)
		getMax(max, root);
}

template <class x>
void BinarySearchTree<x>::getMax(int &max, binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		max = p->info;
		getMax(max, p->right);
	}
	    
}

template <class x>
void BinarySearchTree<x>::printSmallestRecDummy()
{
	if (root != NULL)
		 printSmallestRec(root);
}

template <class x>
void BinarySearchTree<x>::printSmallestRec(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
			cout << p->info << " ";
		else
			printSmallestRec(p->left);
	}
}

template <class x>
void BinarySearchTree<x>::printLargerRecDummy(x item)
{
	if (root != NULL)
		printLargerRec(item, root);
}

template <class x>
void BinarySearchTree<x>::printLargerRec(x item, binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->info > item)
			cout << p->info << " ";

		printLargerRec(item, p->left);
		printLargerRec(item, p->right);
	}
}

template <class x>
void BinarySearchTree<x>::printSmallerRecDummy(x item)
{
	if (root != NULL)
		printSmallerRec(item, root);
}

template <class x>
void BinarySearchTree<x>::printSmallerRec(x item, binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->info < item)
			cout << p->info << " ";

		printSmallerRec(item, p->left);
		printSmallerRec(item, p->right);
	}
}



template <class x>
void BinarySearchTree<x>::countLeavesDummy()
{
	if (root != NULL)
		cout << countLeaves(root);
}

template <class x>
int BinarySearchTree<x>::countLeaves(binaryTreeNode<x> *p)
{
	if (p == NULL)
		return 0;
	
	if (p->left == NULL && p->right == NULL)
		return 1;
	else
		return countLeaves(p->left) + countLeaves(p->right);
}

template <class x>
void BinarySearchTree<x>::printLeavesDummy()
{
	if (root != NULL)
		printLeaves(root);
}

template <class x>
void BinarySearchTree<x>::printLeaves(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
			cout << p->info << " ";

		printLeaves(p->left);
		printLeaves(p->right);
	}
}

template <class x>
void BinarySearchTree<x>::countNodeWatLeastOneChildDummy()
{
	if (root != NULL)
		cout << countNodeWatLeastOneChild(root);
}

template <class x>
int BinarySearchTree<x>::countNodeWatLeastOneChild(binaryTreeNode<x> *&p)
{
	if (p == NULL)
		return 0;

	if (p->left != NULL || p->right != NULL)
		return 1 + countNodeWatLeastOneChild(p->left) + countNodeWatLeastOneChild(p->right);
	else
		return 0;
}

template <class x>
void BinarySearchTree<x>::printNodeWatLeastOneChildDummy()
{
	if(root != NULL)
	printNodeWatLeastOneChild(root);
}

template <class x>
void BinarySearchTree<x>::printNodeWatLeastOneChild(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->left != NULL || p->right != NULL)
			cout << p->info << " ";

		printNodeWatLeastOneChild(p->left);
		printNodeWatLeastOneChild(p->right);
	}
}

template <class x>
void BinarySearchTree<x>::countNodeWexactlyTwoChildrenDummy()
{
	if (root != NULL)
		cout << countNodeWexactlyTwoChildren(root);
}

template <class x>
int BinarySearchTree<x>::countNodeWexactlyTwoChildren(binaryTreeNode<x> *&p)
{
	if (p == NULL)
		return 0;
	
	if (p->left != NULL && p->right != NULL)
		return 1 + countNodeWexactlyTwoChildren(p->left) + countNodeWexactlyTwoChildren(p->right);
	else
		return 0 + countNodeWexactlyTwoChildren(p->left) + countNodeWexactlyTwoChildren(p->right);

}

template <class x>
void BinarySearchTree<x>::printNodeWexactlyTwoChildrenDummy()
{
	if (root != NULL)
		printNodeWexactlyTwoChildren(root);
}

template <class x>
void BinarySearchTree<x>::printNodeWexactlyTwoChildren(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->left != NULL && p->right != NULL)
			cout << p->info << " ";

		printNodeWexactlyTwoChildren(p->left);
		printNodeWexactlyTwoChildren(p->right);
	}
}

template <class x>
void BinarySearchTree<x>::printNodeWexactlyOneChildDummy()
{
	if (root != NULL)
		printNodeWexactlyOneChild(root);
}

template <class x>
void BinarySearchTree<x>::printNodeWexactlyOneChild(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		if (p->left != NULL && p->right == NULL)
			cout << p->info << " ";

		if (p->right != NULL && p->left == NULL)
			cout << p->info << " ";

		printNodeWexactlyOneChild(p->left);
		printNodeWexactlyOneChild(p->right);
	}
}


template <class x>
void BinarySearchTree<x>::countNodeWexactlyOneChildDummy()
{
	if (root != NULL)
		cout << countNodeWexactlyOneChild(root);
}

template <class x>
int BinarySearchTree<x>::countNodeWexactlyOneChild(binaryTreeNode<x> *&p)
{
	if (p == NULL)
		return 0;

	if (p->left == NULL && p->right != NULL)
		return 1 + countNodeWexactlyOneChild(p->left) + countNodeWexactlyOneChild(p->right);
	else
	{
		if(p->left != NULL && p->right == NULL)
			return 1 + countNodeWexactlyOneChild(p->left) + countNodeWexactlyOneChild(p->right);
		else
		{
			if (p->left != NULL && p->right != NULL)
				return countNodeWexactlyOneChild(p->left) + countNodeWexactlyOneChild(p->right);
			else
				return 0;
		}
			
	}
}

template <class x>
int BinarySearchTree<x>::getSumDummy()
{
	if (root != NULL)
		return getSum(root);
	else
		return 0;
}

template <class x>
int BinarySearchTree<x>::getSum(binaryTreeNode<x> *&p)
{
	if (p == NULL)
		return 0;
	else
		return p->info + getSum(p->left) + getSum(p->right);
}

template <class x>
void BinarySearchTree<x>::inorderIterative()
{
	binaryTreeNode<x> *current = root;
	stackLL<binaryTreeNode<x>*> s;

	while (current != NULL || !s.isEmpty())
	{
		if (current != NULL)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			current = s.getTop();
			s.pop();
			cout << current->info << " ";
			current = current->right;
		}
	}
}

template <class x>
void BinarySearchTree<x>::preorderIterative()
{
	binaryTreeNode<x> *current = root;
	stackLL<binaryTreeNode<x>*> s;

	while (current != NULL || !s.isEmpty())
	{
		if (current != NULL)
		{
			cout << current->info << " ";
			s.push(current);
			current = current->left;
		}
		else
		{
			current = s.getTop();
			s.pop();			
			current = current->right;
		}
	}
}

template <class x>
void BinarySearchTree<x>::postorderIterative()
{
	if (root != NULL)
	{
		stackLL<binaryTreeNode<x>*> s1;
		stackLL<binaryTreeNode<x>*> s2;
		binaryTreeNode<x> *top;
		s1.push(root);

		while (!s1.isEmpty())
		{
			top = s1.getTop();
			s2.push(top);
			s1.pop();

			if (top->left != NULL)
				s1.push(top->left);
			if (top->right != NULL)
				s1.push(top->right);
		}

		while (!s2.isEmpty())
		{
			top = s2.getTop();
			cout << top->info << " ";
			s2.pop();
		}
	}
	
}


