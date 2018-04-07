/*Erii Sugimoto
  Date: March 5, 2016
  Purpose: The LargeInt class stores and manipulaates very large integers using 
		   dynamic arrays and provides overloading for: input, output, addition
		   and equality operations.*/
#include <iostream>
using namespace std;

#ifndef LargeInt_h
#define LargeInt_h

#include "DLL.cpp"

class LargeInt
{
	friend ostream& operator << (ostream&, LargeInt&);
	friend istream& operator >> (istream&, LargeInt&);

public:
	LargeInt();
	LargeInt operator + (LargeInt other);
	LargeInt operator = (LargeInt other);
	LargeInt operator - (LargeInt other);
	LargeInt operator * (LargeInt other);
	LargeInt multiply(LargeInt value, const int num);
	//bool operator / (const LargeInt&);
	//bool operator %(const LargeInt&);
	bool operator == (LargeInt);
	bool operator < (LargeInt other);
	bool operator > (LargeInt other);

	//LargeInt MakeEmpty();
	//bool IsFull() const;
	//bool IsEmpty();
	//void InsertItem(anytype item);
	//void DeleteItem(anytype item);
	//bool SearchItem(anytype item);
	//void printList();*/

private:
	DoublyLinkedList<int> list;
};

#endif

