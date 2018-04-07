//Author: Erii Sugimioto Date: Spring 2016
#include "UnsortedLinkedList.cpp"
#include <iostream>
using namespace std;

void main()
{
	UnsortedLinkedList<int> ull1;
	int input, input2;

	do
	{
		cout << "Enter a number to insert at the front of your ull1 list";
		cout << " (Enter 0 to finish): ";
		cin >> input;
		if(input != 0)
		ull1.insertItemFront(input);
	} while (input != 0);
	
	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	cout << "\nCalling mergeSort: ";
	ull1.mergeSort();

	//cout << "\nCalling split: ";
	//ull1.quickSort();

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	//cout << "\ncalling dummysearch: ";
	//cout << ull1.dummySearch(1);

	/*cout << "\ncalling replace_item(x olditem, x newitem): ";
	cout << "\nEnter a number which will be replaced: ";
	cin >> input;
	cout << "\nEnter a number which will replace " << input << ": ";
	cin >> input2;
	ull1.replace_item(input, input2);*/

	/*cout << "\ncalling callReplace_itemR(x olditem, x newitem): ";
	cout << "\nEnter a number which will be replaced: ";
	cin >> input;
	cout << "\nEnter a number which will replace " << input << ": ";
	cin >> input2;
	ull1.callReplace_itemR(input, input2);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	/*
	cout << "\Calling getNumOfItem: ";
	cout << "\nEnter a number to find out how many of them there are in the list: ";
	cin >> input;
	cout << "\nThere are " <<  ull1.getNumOfItem(input) << ' ' << input << "(s) in the list";

	cout << "\nCalling getLargest: \nThe largest element in the list is ";
	cout << ull1.getLargest();

	/*cout << "\nCalling deleteItem: ";
	cout << "\nEnter a number to delete in the list: ";
	cin >> input;
	ull1.deleteItem(input);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	cout << "\nCalling deleteItem2: ";
	cout << "\nEnter a number to delete in the list: ";
	cin >> input;
	ull1.deleteItem2(input);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	/*
	do
	{
		cout << "\nEnter a number to insert at the back of your ull1 list";
		cout << " (Enter 0 to finish): ";
		cin >> input;
		if (input != 0)
			ull1.insertItemBack(input);
	} while (input != 0);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	cout << "\nEnter a number which will be replaced with 3";
	cin >> input;
	ull1.replace_item(input, 3);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	cout << "\nEnter a number: (Those numbers larger than the number will be deleted from the list) ";
	cin >> input;
	ull1.deleteLarger(input);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	cout << "\nEnter a number: (Those numbers smaller than the number will be deleted from the list) ";
	cin >> input;
	ull1.deleteSmaller(input);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();

	cout << "\nEnter a number in the list to delete: ";
	cin >> input;
	ull1.deleteItem(input);

	cout << "\nPrinting out the element(s) in your ull1 list from the beginning: ";
	ull1.printForward();*/

	//cout << "\ncalling Recursive search: Is there 1 in the list?";
	//if (ull1.dummySearch(1))
		//cout << "\nYes";
	//else
		//cout << "\nNo";
}