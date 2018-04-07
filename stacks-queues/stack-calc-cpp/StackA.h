/*Erii Sugimoto
CSC 330 : BMCC
Programming Exercise 4
May 26th, 2016

Purpose: This is a stack class.
*/

#ifndef StackA_h
#define StackA_h

template <class x>
class stackA
{
private:
	x *info; //pointer to an x item
	int max;
	int top; //represents the position of the element on the top or one element after the top
public:
	stackA(int m = 100);
	~stackA();
	stackA(const stackA<x> &other);
	stackA operator = (const stackA<x>& other);
	bool isFull();
	bool isEmpty();
	void push(x item);
	void pop();
	bool getTopItem(x &item);
	x getTopItem();
	void print();
	bool search(x item);
	void reverse(stackA<x> &list);
	stackA<x>& returnCopy(const stackA<x> &other);
	bool operator == (const stackA<x> &other);
	int getTop();
};
#endif // !StackA.h
#pragma once
