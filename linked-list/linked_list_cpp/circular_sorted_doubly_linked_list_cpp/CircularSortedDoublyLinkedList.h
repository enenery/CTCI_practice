//Author: Erii Sugimoto Date: Spring 2016
#ifndef CircularSortedDoublyLinkedList_h
#define CircularSortedDoublyLinkedList_h
#include <iostream>
using namespace std;

template <class x>
struct nodeType
{
	nodeType<x> *next;
	nodeType<x> *back;
	x info;
};

template <class x>
class CircularSortedDoublyLinkedList
{
	/*friend ostream& operator << (ostream& out, const CircularSortedDoublyLinkedList<x>& other)
	{
		nodeType<x> *current = new nodeType<x>;
		current = other.first->next;

		do
		{
			out << current->info << ' ';
			current = current->next;
		} while (current != other.first->next);


		return out;
	}
	//friend istream& operator >> (istream& in, CircularSortedLinkedList &other);*/

private:
	nodeType<x> *first; //points to the last element
	int max, length;

public:
	CircularSortedDoublyLinkedList(int m = 100);//default constructor
	CircularSortedDoublyLinkedList(const CircularSortedDoublyLinkedList &other);
	~CircularSortedDoublyLinkedList();
	void insertItem(x item);
	int howMany(x item);
	bool isFull();
	bool isEmpty();
	void printForward();
	void printBackward();
	void callPrintBackwardR();
	void printBackwardR(nodeType<x> *current);
	void printBothways();
	void callPrintBothwaysR();
	void printBothwaysR(nodeType<x> *current);
	x getSmallest();
	x getLargest();
	int getNumOfSmallerItem(x item);
	void deleteLast();
};
#endif // !CircularSortedDoublyLinkedList.h
#pragma once
