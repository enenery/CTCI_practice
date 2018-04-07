/* Author: Erii Sugimoto
   Date: 11/21/2016
   Professor: Anna Salvati
   Assignment: Project #2
   Class: CSC 430
   School: Borough of Manhattan Community College
   File Name: BinaryTree2.h
   Description Of the Program: A binary tree class that each node contains four information
                            1 info <x>: unique information of type x
							2 *left <binaryTreeNode<x>>: a pointer to the left child 
							3 *right <binaryTreeNode<x>>: a pointer to the right child 
							4 count <int>: a counter that keeps track of the frequency of each "info"
*/

#include <iostream>
using namespace std;
#ifndef BinaryTree2_hpp
#define BinaryTree2_hpp

#include <stdio.h>

template <class x>
struct binaryTreeNode
{
	x info;
	binaryTreeNode<x> *left;
	binaryTreeNode<x> *right;
	int count;
};

template <class x>
class BinaryTree2
{
public:
	BinaryTree2(); //constructor
	~BinaryTree2(); //destructor 
	void copy(binaryTreeNode<x> *p, binaryTreeNode<x> *&r); //copy constructor

	//Function that returns true when the tree is empty
	bool isEmpty(); 
	//Function that destroy the tree
	void destroyTree(binaryTreeNode<x> *&p);

	//Dummy function for the preorder
	void preorderDummy();
	//Function that prints out each info in the tree in preorder
	void preorder(binaryTreeNode<x> *p);

	//Dummy function for the inorder
	void inorderDummy();
	//Function that prints out each info in the tree in preorder
	void inorder(binaryTreeNode<x> *p);

	//Dummy function for the posorder
	void postorderDummy();
	//Function that prints out each info in the tree in postorder
	void postorder(binaryTreeNode<x> *p);

protected:
	binaryTreeNode<x> *root;
};
#endif // !BinaryTree2_hpp
