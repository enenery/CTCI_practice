#include "LargeInt.h"
#include "DoublyLinkedList1.h"

#include <string>
#include <iostream>
using namespace std;

void main()
{
	LargeInt  x, y, z;

	cout << "Enter an integer of your choice : ";
	cin >> x;

	cout << "Enter an integer of your choice : ";
	cin >> y;	
	
	
	z = x + y;

	cout << "\n\nThe sum of  " << x << " and " << y << " is : " << z << endl;

	z = x - y;

	cout << "\n\nThe difference of  " << x << " and " << y << " is : " << z << endl;

	if (x == y)
		cout << "\n\nThe two numbers entered are equal";
	else
		cout << "\n\nThe two numbers entered are different";

	if(x > y)
		cout << "\n\ncalling is bigger.";
	else
		cout << "\n\ncalling is not bigger.";

	if (x < y)
		cout << "\n\ncalling is smaller.";
	else
		cout << "\n\ncalling is not smaller.";

	z = x * y;

	cout << "\n\nThe product of  " << x << " and " << y << " is : " << z << endl;


}
