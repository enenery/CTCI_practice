/* Author: Erii Sugimoto
   Date: 11/21/2016
   Professor: Anna Salvati
   Assignment: Project #2
   Class: CSC 430
   School: Borough of Manhattan Community College
   File Name: BinaryTree2.cpp
   Description Of the Program: An implementation file for the BinaryTree2.h
*/
#include "BinaryTree2.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template <class x>
BinaryTree2<x>::BinaryTree2()
{
	root = NULL;
}

template <class x>
BinaryTree2<x>::~BinaryTree2()
{
	if (root != NULL)
	{
		destroyTree(root);
	}
}

template <class x>
void BinaryTree2<x>::copy(binaryTreeNode<x> *p, binaryTreeNode<x> *&r)
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
bool BinaryTree2<x>::isEmpty()
{
	return (root == NULL);
}

template <class x>
void BinaryTree2<x>::destroyTree(binaryTreeNode<x> *&p)
{
	if (p != NULL)
	{
		destroyTree(p->left);
		destroyTree(p->right);
		delete p;
	}
}

template <class x>
void BinaryTree2<x>::preorderDummy()
{
	if (root != NULL)
		preorder(root);
}

template <class x>
void BinaryTree2<x>::preorder(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

template <class x>
void BinaryTree2<x>::inorderDummy()
{
	if (root != NULL)
		inorder(root);
}

template <class x>
void BinaryTree2<x>::inorder(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->info << " ";
		inorder(p->right);
	}
}

template <class x>
void BinaryTree2<x>::postorderDummy()
{
	if (root != NULL)
		postorder(root);
}

template <class x>
void BinaryTree2<x>::postorder(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->info << " ";
	}
}



