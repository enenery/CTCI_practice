//Author: Erii Sugimoto Date: Spring 2016
#include "CircularSortedDoublyLinkedList.cpp"
#include <iostream>
using namespace std;

void main()
{
	CircularSortedDoublyLinkedList<int> csdll1;
	int input;
	do
	{
		cout << "Enter a number to insert in your ull1 list";
		cout << " (Enter 0 to finish): ";
		cin >> input;
		if (input != 0)
			csdll1.insertItem(input);
	} while (input != 0);

	//cout << "\nprintForward(): ";
	//csdll1.printForward();

	cout << "\ncallPrintBothways(): ";
	csdll1.callPrintBothwaysR();

	cout << "\nprintForward(): ";
	csdll1.printForward();

	cout << "\ncallPrintBackwardR(): ";
	csdll1.callPrintBackwardR();

	cout << "\ndeleteLast(): ";
	csdll1.deleteLast();

	cout << "\nprintForward(): ";
	csdll1.printForward();

	cout << "\nEnter a number, and we will tell you how many elements are smaller than the number: ";
	cin >> input;
	cout << csdll1.getNumOfSmallerItem(input);
}