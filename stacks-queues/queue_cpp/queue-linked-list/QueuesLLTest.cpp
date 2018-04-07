#include "QueuesLL.h"
#include "QueuesLL.cpp"
#include <iostream>
using namespace std;

void main()
{
	queueLL<int> qLL;
	qLL.enqueue(2);
	qLL.enqueue(4);
	qLL.enqueue(1);
	qLL.enqueue(0);
	qLL.dequeue();
	qLL.print();

	queueLL<int> queue;

	int x, y;

	x = 4;

	y = 5;

	queue.enqueue(x);
	queue.enqueue(y);

	x = queue.getFront();

	queue.dequeue();
	queue.enqueue(x + 5);

	queue.enqueue(16);

	queue.enqueue(x);
	queue.enqueue(y - 3);

	cout << "Queue Elements: ";

	while (!queue.isEmpty())
	{
		cout << queue.getFront() << " ";
		queue.dequeue();
	}
	cout << endl;

	queueLL<int> queue2;

	queue2.enqueue(10);

	queue2.enqueue(20);

	cout << queue2.getFront() << endl;

	queue2.dequeue();

	queue2.enqueue(2 * queue.getRear());

	queue2.enqueue(queue.getFront());

	queue2.enqueue(5);

	queue2.enqueue(queue.getRear() - 2);


	cout << "\nyo!" << endl;

	cout << queue2.getFront() << " " << queue2.getFront() << endl;
	while (!queue2.isEmpty())
	{
		cout << queue2.getFront() << " ";

		queue2.dequeue();

	}
}
