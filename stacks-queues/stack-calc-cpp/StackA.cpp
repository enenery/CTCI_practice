/*Erii Sugimoto
CSC 330 : BMCC
Programming Exercise 4
May 26th, 2016

Purpose: This is a implemetation file for stackA.h.
*/

#include "StackA.h"
#include <iostream>
using namespace std;
#include <cassert>

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
bool stackA<x>::getTopItem(x &item)
{
	if (!isEmpty())
	{
		item = info[top];
		return true;
	}
	else
		return false;
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
	stackA<int> temp;
	int i = 0;
	x sth;
	int p = list.top;
	p++;

	while (i <= p)
	{
		if (getTopItem(sth))
			temp.push(sth);
		list.pop();
		i++;
	}
	if (getTopItem(sth))
		temp.push(sth);

	for (int i = 0; i < p; i++)
		list.push(temp.info[i]);
}

template <class x>
stackA<x>& stackA<x>::returnCopy(const stackA<x> &other)
{
	max = other.max;
	top = other.top;
	info = new x[max];

	for (int i = 0; i <= top; i++)
		info[i] = other.info[i];

	return *this;
}

template <class x>
bool stackA<x>::operator==(const stackA<x> &other)
{
	if (top == other.top)
	{
		for (int i = top; i >= 0; i--)
			if (info[i] != other.info[i])
			{
				cout << "\ninfo[i] = " << info[i];
				cout << "\nother.info[i] = " << other.info[i];
				return false;
			}


		return true;
	}
	else return false;
}

template <class x>
int stackA<x>::getTop()
{
	return top;
}

template <class x>
x stackA<x>::getTopItem()
{
	return info[top];

}
