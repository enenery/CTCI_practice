#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

template <class x>
BinaryTree<x>::BinaryTree()
{
	root = NULL;
}

template <class x>
BinaryTree<x>::~BinaryTree()
{
	if (root != NULL)
		destroyTree(root);
}

template <class x>
void BinaryTree<x>::copy(binaryTreeNode<x> *p, binaryTreeNode<x> *&r)
{
	if (p == NULL)
		r = NULL;
	else
	{
		r = new binaryTreeNode<x>;
		r->info = p->info;
		copy(p->left, r->left);
		copy(p->right, p->right);
	}
}

template <class x>
bool BinaryTree<x>::isEmpty()
{
	return (root == NULL);
}

template <class x>
void BinaryTree<x>::destroyTreeDummy()
{
	if (root != NULL)
		destroyTree(root);
}

template <class x>
void BinaryTree<x>::destroyTree(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		destroyTree(p->left);
		destroyTree(p->right);
		delete p;
		p = NULL;
	}
}

template <class x>
void BinaryTree<x>::preorderDummy()
{
	if (root != NULL)
		preorder(root);
}

template <class x>
void BinaryTree<x>::preorder(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

template <class x>
void BinaryTree<x>::inorderDummy()
{
	if (root != NULL)
		inorder(root);
}

template <class x>
void BinaryTree<x>::inorder(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->info << " ";
		inorder(p->right);
	}
}

template <class x>
void BinaryTree<x>::postorderDummy()
{
	if (root != NULL)
		postorder(root);
}

template <class x>
void BinaryTree<x>::postorder(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->info << " ";
	}
}

template <class x>
int BinaryTree<x>::getHeightDummy()
{
	if (root != NULL)
		getHeight(root);
	else
		return 0;
}

template <class x>
int BinaryTree<x>::getHeight(binaryTreeNode<x> *p)
{
	if (p != NULL)
		return 1 + max(getHeight(p->left), getHeight(p->right));
	else
		return 0;
}

template <class x>
int BinaryTree<x>::max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}



