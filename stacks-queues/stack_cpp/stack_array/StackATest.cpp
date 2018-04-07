#include "StackA.cpp"
#include <iostream>
using namespace std;
#include <string>

int main()
{
	stackA<int> age;
	int input;

	cout << "Insert a number at the beginning of your list:" << endl;
	do
	{
		cout << "\nEnter a number, enter 0 to end:";
		cin >> input;
		if (input != 0)
			age.push(input);
	} while (input != 0);

	age.print();

	cout << "\nLet me pop the list:";
	age.pop();

	cout << "\nPrintint out:";
	age.print();

	cout << "\nEnter a number to search in the list: ";
	cin >> input;
	if (age.search(input))
		cout << "\nItem found.";
	else
		cout << "\nItem not found.";

	//age.reverse(age);
}