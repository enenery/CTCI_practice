#ifndef SortedLinkedList_h
#define SortedLinkedList_h
#include <iostream>
using namespace std;

template <class x>
struct nodeType
{
	x info;
	nodeType<x> *next;
};

template <class x>
class SortedLinkedList
{
	//friend ostream& operator << (ostream& out, const SortedLinkedList<x> &other);
	//friend istream& operator >> (istream& in, const SortedLinkedList<x> &other);
public:
	SortedLinkedList(int m = 100);
	~SortedLinkedList();
	SortedLinkedList(const SortedLinkedList<x> &other);
	void operator=(const SortedLinkedList<x> &other);
	void printForward();
	void insertItem(x item);
	void callInsertItemR(x item);
	void insertItemR(x item, nodeType<x> *&current);
	bool isEmpty();
	bool isFull();
	int getLength();
	int getNumOfSmaller(x item);
	int getNumOfLarger(x item);
	void deleteSmaller2(x item);
	void deleteLarger(x item);
	void deleteLarger2(x item);
	int replace_item(x olditem, x newitem);
	bool search_item(x item);
	int getNumOfItem(x item);
	int getNumOfItem2(x item);
	void printPositionOfItem(x item);
	void printPosition(x item);
	void devideInHalf(nodeType<x> *L1, nodeType<x> *&L2);
	nodeType<x>* merge(nodeType<x> *L1, nodeType<x> *L2);
	void recMergeSort(nodeType<x> *&L1);
	void mergeSort();

	void displayKtoLast(int k);
	void displayKtoLast(nodeType<x> *front, int& k);

	bool has_cycle(nodeType<x> *head);
	bool has_cycle_dummy();
private:
	int max, length;
	nodeType<x> *first;
	nodeType<x> *last;
};


#endif // !SortedLinkedList_h

