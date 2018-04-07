#include "StackA.h"
#include <iostream>
#include <cassert>
using namespace std;

template <class x>
stackA<x>::stackA(int m)
{
	max = m;
	top = -1; // empty stack when top = -1
	info = new x[m];
}

template <class x>
stackA<x>::~stackA()
{
	delete[] info;
}

template <class x>
stackA<x>::stackA(const stackA<x> &other)
{
	max = other.max;
	top = other.top;
	info = new x[max];

	for (int i = 0; i <= top; i++)
		info[i] = other.info[i];
}

template <class x>
stackA<x> stackA<x>::operator=(const stackA<x> &other)
{
	max = other.max;
	top = other.top;
	info = new x[max];

	for (int i = 0; i <= top; i++)
		info[i] = other.info[i];
}
template <class x>
bool stackA<x>::isFull()
{
	return (top == max - 1);
}

template <class x>
bool stackA<x>::isEmpty()
{
	return (top == -1);
}

template <class x>
void stackA<x>::push(x item)
{
	if (!isFull())
		info[++top] = item;
	else cout << "\nThe list is full.";
}

template <class x>
void stackA<x>::pop()
{
	if (!isEmpty())
		top--;
	else cout << "\nThe list is empty.";
}

template <class x>
x stackA<x>::getTopItem()
{
	assert(isEmpty());
	return info[top];	 
}

template <class x>
void stackA<x>::print()
{
	if (!isEmpty())
	{
		for (int i = 0; i <= top; i++)
			cout << info[i] << " ";
	}
}

template <class x>
bool stackA<x>::search(x item)
{
	if (!isEmpty())
	{
		for (int i = 0; i <= top; i++)
			if (info[i] == item)
				return true;
		return false;
	}
	else return false;
}

template <class x>
void stackA<x>::reverse(stackA<x> &list)
{
	x *temp = new x[max];
	int i = 0;

	while (!isEmpty())
	{
		temp[i] = getTopItem();
		i++;
	}
	i = 0;

	for (int i = 0; i <= top; i++)
		info[i] = temp[i];
}
