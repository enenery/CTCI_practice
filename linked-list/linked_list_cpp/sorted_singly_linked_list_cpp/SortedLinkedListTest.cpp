#include "SortedLinkedList.cpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	SortedLinkedList<int> sll;
	int input;
	do
	{
		cout << "\nEnter a number, enter 0 to end:";
		cin >> input;
		if (input != 0)
			sll.insertItem(input);
	} while (input != 0);
	
	//cout << "\nPrinting out the elements in the list in sll1: ";
	//sll.printForward();

	//cout << "\ncalling callInsertitem(x item): ";
	//cout << "\nEnter a number to insert:";
	//cin >> input;
	//sll.callInsertItemR(input);

	cout << "\nPrinting out the eslements in the list in sll: ";
	sll.printForward();

	//cout << "\ncall sihan";
	//sll.displayKtoLast(2);

	cout << "\ncall has_cycle_dummy";
	cout << sll.has_cycle_dummy();
	
	//cout << "\nCalling mergeSort: ";
	//sll.mergeSort();

	cout << "\nPrinting out the elements-- in the list in sll1: ";
	sll.printForward();
	

	/*
	cout << "\nEnter a number and all the elements larger than the number will be deleted.";
	cin >> input;
	sll.deleteLarger2(input);
	
	cout << "\nPrinting out the elements in the list in sll1: ";
	sll.printForward();
	
	cout << "\ncalling getNumOfSmaller: ";
	cout << "\nEnter a number, and we tell you how many elements in the list are smaller than the number: ";
	cin >> input;
	cout << sll.getNumOfSmaller(input);
	cout << "\nPrinting out the elements in the list in sll1";
	sll.printForward();

	cout << "\nThe number of the elements in the list of sll: " << sll.getLength();


	int num = 4;
	cout << "\nThe number of the elements smaller than " << num << " is: " << sll.getNumOfSmaller(num);

	cout << "\nThe number of the elements smaller than " << num << " is: " << sll.getNumOfLarger(num);

	cout << endl;

	cout << "\nColling the copy constructor: ";
	SortedLinkedList<int> sll2(sll);

	cout << "\nPrinting out the elements in the list in sll2";
	sll2.printForward();
	cout << "\nThe number of the elements in the list of sll2: " << sll2.getLength();

	cout << endl;

	cout << "\nCalling the overloaded = operator: ";
	SortedLinkedList<int> sll3 = sll;

	cout << "\nPrinting out the elements in the list in sll3";
	sll3.printForward();
	cout << "\nThe number of the elements in the list of sll3: " << sll3.getLength();

	int input;

		cout << "Enter a number to insert:" << endl;
		do
		{
			cout << "enter a number, enter 0 to end:";
			cin >> input;
			if (input != 0)
				sll3.insertItem(input);
		} while (input != 0);
		cout << "\nPrinting out the elements in the list in sll3";
		sll3.printForward();

		cout << "\nEnter a number and all the elements smaller than the number will be deleted.";
		cin >> input;
		sll3.deleteSmaller(input);

		cout << "\nPrinting out the elements in the list in sll3, see?";
		sll3.printForward();

		cout << "\nEnter a number and all the elements larger than the number will be deleted.";
		cin >> input;
		sll3.deleteLarger(input);

		cout << "\nPrinting out the elements in the list in sll3, see?";
		sll3.printForward();

		cout << "\nEnter a number and we look for it in the list: ";
		cin >> input;
		cout << "\nCalling search_item: ";
		if (sll3.search_item(input))
			cout << "\nfound";
		else
			cout << "\nNot found";

		int input2;

		cout << "\nEnter a number: ";
		cin >> input;
		cout << "\nEnter a number to replace the previous number with: ";
		cin >> input2;
		cout << "The number of replacements taken place: ";
		cout << sll3.replace_item(input, input2);
		
		cout << "\nPrinting out the elements in the list in sll: ";
		sll.printForward();
		
		cout << "\nCalling getNumOfItem2 function, pick a number: ";
		cin >> input;
		cout << sll.getNumOfItem2(input);
		

		cout << "\nPrinting out the elements in the list in sll1: ";
		sll.printForward();

	cout << "\nCalling printPositionOfItem, pick a number: ";
	cin >> input;
	sll.printPositionOfItem(input);

	cout << "\nCalling printPosition, pick a number: ";
	cin >> input;
	sll.printPosition(input);*/

	cout << endl;
}
