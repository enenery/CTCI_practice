//Author: Erii Sugimioto Date: Spring 2016
#ifndef UnsortedLinkedList_h
#define UnsortedLinkedList_h
#include <iostream>
using namespace std;

template <class x>
struct nodeType
{
	x info;
	nodeType<x> *next;
};

template <class x>
class UnsortedLinkedList
{
	//friend ostream& operator << (ostream& out, const SortedLinkedList<x> &other);
	//friend istream& operator >> (istream& in, const SortedLinkedList<x> &other);
public:
	UnsortedLinkedList(int m = 100);
	~UnsortedLinkedList();
	UnsortedLinkedList(const UnsortedLinkedList<x> &other);
	void operator=(const UnsortedLinkedList<x> &other);
	void printForward();
	void insertItemFront(x item);
	void insertItemBack(x item);
	bool isEmpty();
	bool isFull();
	int getLength();
	int getNumOfItem(x item);
	int getNumOfSmaller(x item);
	int getNumOfLarger(x item);
	void deleteItem(x item);
	void deleteItem2(x item);
	void deleteSmaller(x item);
	void deleteLarger(x item);
	int replace_item(x olditem, x newitem);
	void callReplace_itemR(x olditem, x newitem);
	int replace_itemR(x olditem, x newitem, nodeType<x> *current, int count);
	bool search_item(x item);
	bool dummySearch(x item);
	bool searchR(nodeType<x> *current, x item);
	x getLargest();
	void devideInHalf(nodeType<x> *L1, nodeType<x> *&L2);
	nodeType<x>* merge(nodeType<x> *L1, nodeType<x> *L2);
	void recMergeSort(nodeType<x> *&L1);
	void mergeSort();
	void split(nodeType<x> *L1, nodeType<x> *&L2);
	void recQuickSort(nodeType<x> *&L1);
	void quickSort();

private:
	int max, length;
	nodeType<x> *first;
	nodeType<x> *last;
};


#endif UnsortedLinkedList_h

#pragma once
