/*
@author Erii Sugimoto
@last modified 04132016
*/

#ifndef CircularSortedLinkedList_h
#define CircularSortedLinkedList_h
#include <iostream>
using namespace std;

template <class x>
	struct nodeType
	{	
		nodeType<x> *next;
		x info;
	};

template <class x>
class CircularSortedLinkedList
{	
	friend ostream& operator << (ostream& out, const CircularSortedLinkedList<x>& other)
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
	//friend istream& operator >> (istream& in, CircularSortedLinkedList &other);

private:
	nodeType<x> *first; //points to the last element
	int max, length;

public:
	CircularSortedLinkedList(int m = 100);//default constructor
	CircularSortedLinkedList(const CircularSortedLinkedList &other);
	~CircularSortedLinkedList();
	void makeEmpty();
	bool search_item(x item);
	void insertItem(x item);
	int howMany(x item);
	int getNumOfItem(x item);
	bool isEmpty();
	bool isFull();
	void printForward();
	x getSmallest();
	x getLargest();
	void printPosition(x item);
	void deleteSmaller(x item);
};
#endif // !CircularSortedLinkedList.h

