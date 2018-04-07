#ifndef StackLinkedList_h
#define StackLinkedList_h

template <class x>
struct node
{
	x info;
	node *next;
};

template <class x>
class stackLL
{
private:
	node<x> *top;
public:
	void makeEmpty();
	stackLL();
	~stackLL();
	stackLL(const stackLL& other);
	void operator=(const stackLL& other);
	void push(x item);
	void pop();
	x getTop();
	void getTop(x &item);
	bool isFull();
	bool isEmpty();
	void printFromTop();
	void printReverse();
	bool search(x item);
	void reverse();
};
#endif // !StackLinkedList_h
#pragma once
