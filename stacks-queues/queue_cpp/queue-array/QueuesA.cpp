#include "QueuesA.h"
#include <iostream>
#include <cassert>
using namespace std;

template <class x>
queueA<x>::queueA(int m)
{
	max = m;
	front = 0;
	rear = max - 1;
	count = 0;
	q = new x[max];
}

template <class x>
queueA<x>::~queueA()
{
	delete[] q;
}

template <class x>
queueA<x>::queueA(const queueA& other)
{
	front = other.front;
	count = other.count;
	max = other.max;
	rear = other.rear;

	q = new x[max];
	for (int i = 0; i < max - 1; i++)
		q[i] = other.q[i];
}

template <class x>
void queueA<x>::enqueue(x item)
{
	
	if (!isFull())
	{
		rear = (rear + 1) % max;
		q[rear] = item;
		count++;
	}
	else cout << "\nThe list is full.";
}
template <class x>
void queueA<x>::dequeue()
{
	if (!isEmpty())
	{
		count--;
		front = (front + 1) % max;
	}
	else
		cout << "\nThe list is empty.";
}

template <class x>
bool queueA<x>::isFull()
{
	return (count == max);
}

template <class x>
bool queueA<x>::isEmpty()
{
	return (count == 0);
}

template <class x>
void queueA<x>::print()
{
	if (!isEmpty())
	{
		int i = front;

		while (i != rear+1)
		{
			cout << q[i] << " ";
			i = (i + 1) % max;
		}
	}
}


template <class x>
bool queueA<x>::search(x item)
{
	if (!isEmpty())
	{
		int i = front;

		while (i != rear + 1)
		{
			if (q[i] == item)
				return true;
			i = (i + 1) % max;
		}

		return false;
	}
	else return false;
}

template <class x>
queueA<x>& queueA<x>::returnAcopy(const queueA& other)
{
	front = other.front;
	count = other.count;
	max = other.max;
	rear = other.rear;

	q = new x[max];
	for (int i = 0; i < max - 1; i++)
		q[i] = other.q[i];

	return *this;
}
template <class x>
void queueA<x>::reverse()
{
	if (!isEmpty())
	{
		int i = front;
		int j = rear;
		int counter = 0;

		while (counter < count / 2)
		{	
			x temp = q[i];
			x temp2 = q[j];

			q[i] = temp2;
			q[j] = temp;
			
			i = (i + 1) % max;
			j = (j - 1) % max;

			counter++;
		}
	}
}

template <class x>
bool queueA<x>::operator==(const queueA& other)
{
	if (count == other.count)
	{
		int i = front;

		while (i != rear + 1)
		{
			if (q[i] != other.q[i])
				return false;
			i = (i + 1) % max;
		}
		return true;
	}
		return false;
}

template <class x>
int queueA<x>::getCount()
{
	return count;
}

template <class x>
x queueA<x>::getFront()
{
	assert(!isEmpty());
	return q[front];
}

template <class x>
x queueA<x>::getRear()
{
	assert(!isEmpty());
	return q[rear];
}

template <class x>
int queueA<x>::getMax()
{
	return max;
}