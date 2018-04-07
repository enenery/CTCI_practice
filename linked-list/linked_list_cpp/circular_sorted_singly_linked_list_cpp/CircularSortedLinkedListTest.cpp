#include "CircularSortedLinkedList.cpp"
#include <iostream>
using namespace std;

void main()
{	
	CircularSortedLinkedList <int> csll1;
	

	int input;
	cout << "Insert a number in your list:" << endl;
	do
	{
		cout << "\nEnter a number, enter 0 to end:";
		cin >> input;
		if (input != 0)
			csll1.insertItem(input);
	} while (input != 0);
	
	cout << "\nPrintingForward: ";
	csll1.printForward();

	cout << "\calling deleteSmaller(x item): ";
	cout << "\nEnter a number, and we will delete numbers smaller than that: ";
	cin >> input;
	csll1.deleteSmaller(input);

	cout << "\nPrintingForward: ";
	csll1.printForward();

	/*
	cout << "\ncalling printPostion(x item): ";
	cout << "\nEnter a number, and we will tell you the position(s) of the number in the list: ";
	cin >> input;
	csll1.printPosition(input);
	
	cout << "\nsearch_item, pick a number to search: ";
	cin >> input;
	if (csll1.search_item(input))
		cout << "\nitem found.";
	else
		cout << "\nitem Not found.";

	cout << "\ngetNumOfItem, pick a number to find how many of them there are in the list: ";
	cin >> input;
	cout << csll1.getNumOfItem(input);

	cout << "\nmakeEmpty(): ";
	csll1.makeEmpty();
	cout << "\nPrintingForward: ";
	csll1.printForward();

	cout << endl;

	cout << "There is " << csll1.howMany(2) << " 2s.\n";

	cout << "PrintingForward: \n"; 
	csll1.printForward();

	cout << "\nThe smallest element in the list: " << csll1.getSmallest();
	cout << "\nThe largest element in the list: " << csll1.getLargest();
	cout << "\n";
	cout << csll1;*/
}