#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

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
void BinarySearchTree<x>::insert(x item)
{
	cout << "\nInsert beg";
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
	cout << "\nInsert end";
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
			trailing->left = current->left;
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
			if (current->info == deleteItem)
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
