#include "QueuesA.cpp"
#include <iostream>
using namespace std;

bool equal(queueA<int> one, queueA<int> two)
{
	if (one.getCount() == two.getCount())
	{
		while (!one.isEmpty())
		{
			if (one.getFront() != two.getFront())
				return false;
			one.dequeue();
			two.dequeue();
		}
		return true;
	}
	else return false;
}

template <class x>
void reverse(queueA<x> &one)
{
	if (!one.isEmpty())
	{
		queueA<x> temp;
		int num = one.getCount();
		x ti;
		x *tempy = new x[num];

		for (int i = 0; i < num; i++)
		{
			ti = one.getFront();
			tempy[i] = ti;
			one.dequeue();
		}

		int index = num - 1;
		for (int i = 0; i < num; i++)
		{
			ti = tempy[index];
			one.enqueue(ti);
			index--;
		}
	}
}

void main()
{
	queueA<int> qa1;
	qa1.enqueue(1);
	qa1.enqueue(2);
	qa1.dequeue();
	qa1.enqueue(3);
	qa1.enqueue(4);
	qa1.dequeue();
	qa1.enqueue(5);
	qa1.enqueue(6);
	qa1.search(2);
	
	qa1.print();
	cout << "\n";
	qa1.reverse();
	qa1.print();
	cout << "\n";
	queueA<int> qa2;
	qa2.returnAcopy(qa1); 
	cout << "\nlet me print out qa2 after copying qa1: ";
	qa2.print();
	qa2.enqueue(4);
	cout << "\n";
	if (qa2 == qa1)
		cout << "\nThey are equal.";
	else
		cout << "\nThey aren't equal.";


	if(equal(qa1, qa2))
		cout << "\nThey are equal.";
	else
		cout << "\nThey aren't equal.";

	cout << "\nlet me print out qa1: ";
	qa1.print();
	cout << "\nlet me print out qa2: ";
	qa2.print();

	reverse(qa1);

	cout << "\nlet me print out qa1: ";
	qa1.print();


}