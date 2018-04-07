#include "StackLL.cpp"
#include <iostream>
using namespace std;

void mystery(stackLL<int>& s, stackLL<int>& t)

{

	while (!s.isEmpty())

	{
		t.push(2 * s.getTop());
		s.pop();
	}

}
void main()
{/*
	stackLL<int> sll;
	int input;

	stackLL<int> sll2;

	sll2.push(2);
	sll2.push(3);
	sll2.push(8);
	sll2.pop();
	sll2.push(4);

	cout << "\nprinting out:";
	sll2.printFromTop();

	cout << "Insert a number at the beginning of your list:" << endl;
	do
	{
		cout << "\nEnter a number, enter 0 to end:";
		cin >> input;
		if (input != 0)
			sll.push(input);
	} while (input != 0);

	sll.printFromTop();
	cout << "\n";
	sll.printReverse();

	cout << "\nEnter a number to search in the list:";
	cin >> input;
	if (sll.search(input))
		cout << "\nItem found!";
	else
		cout << "\nItem not found :(";

	cout << "\ncalling reverse:";
	sll.reverse();

	cout << "\nprinting out:";
	sll.printFromTop();

	stackLL<int> s1;
	stackLL<int> s2;

	int list[] = { 5, 10, 15, 20, 25 };


	for (int i = 0; i < 5; i++)

		s1.push(list[i]);

	mystery(s1, s2);

	while (!s2.isEmpty())
	{
		cout << s2.getTop() << " ";
		s2.pop();
	}
		cout << endl;*/

		stackLL<int> myStack;

		myStack.push(10);
		myStack.push(20);
		myStack.pop();

		cout << myStack.getTop() << endl;

		myStack.push(25);
		myStack.push(2 * myStack.getTop());
		myStack.push(-10);
		myStack.pop();

		stackLL<int> tempStack(myStack);

		while (!tempStack.isEmpty())
		{
			cout << tempStack.getTop() << " ";
			tempStack.pop();
		}

		cout << endl;

		cout << myStack.getTop() << endl;
}

