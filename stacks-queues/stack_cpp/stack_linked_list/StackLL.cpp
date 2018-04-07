#include "StackLL.h"
#include <iostream>
using namespace std;
#include <cassert>

template <class x>
void stackLL<x>::makeEmpty()
{
	node<x> *current;
	while (top != NULL)
	{
		current = top;
		top = top->next;
		delete current;
	}
}
template <class x>
stackLL<x>::stackLL()
{
	top = NULL;
}

template <class x>
stackLL<x>::~stackLL()
{
	node<x> *current;
	while (top != NULL)
	{
		current = top;
		top = top->next;
		delete current;
	}
}
template <class x>
stackLL<x>::stackLL(const stackLL& other)
{
	if (other.top == NULL)
		top = NULL;
	else
	{
		top = new node<x>;
		top->info = other.top->info;
		node<x> *p = other.top;
		node<x>*q = top;

		while (p->next != NULL)
		{
			p = p->next;
			q->next = new node<x>;
			q = q ->next;
			q->info = p->info;
		}
		q->next = NULL;
	}
}

template <class x>
void stackLL<x>::operator=(const stackLL& other)
{
	if (this != &other)
	{
		if (other.top == NULL)
			top = NULL;
		else
		{
			top = new node<x>;
			top->info = other.top->info;
			node<x> *currentOld = other.top;
			node<x> *currentNew = top;

			while (currentOld != NULL)
			{
				currentNew->next = new node<x>;
				currentNew = currentNew->next;
				currentNew->info = currentOld->info;
			}
		}
	}
}
template <class x>
void stackLL<x>::push(x item)
{
	if (!isFull())
	{
		node<x> *newNode = new node<x>;
		newNode->info = item;
		newNode->next = top;
		top = newNode;
	}
}
template <class x>
void stackLL<x>::pop()
{
	if (isEmpty())
		cout << "\nThe list is empty.";
	else
	{
		node<x> *temp = top;
		top = top->next;
		delete temp;
	}
}

template <class x>
void stackLL<x>::getTop(x &item)
{
	if (top != NULL)
		return false;
	else
	{
		item = top->info;
		return true;
	}
}

template <class x>
bool stackLL<x>::isFull()
{
	node<x> *temp = new node<x>;
	if (temp == NULL)
		return true;
	else
	{
		delete temp;
		return false;
	}
}

template <class x>
bool stackLL<x>::isEmpty()
{
	return (top == NULL);
}

template <class x>
void stackLL<x>::printFromTop()
{
	if (!isEmpty())
	{
		node<x> *current = top;
			while (current != NULL)
			{
				cout << current->info << ' ';
				current = current->next;
			}
	}
}

template <class x>
void stackLL<x>::printReverse()
{
	if (!isEmpty())
	{
		stackLL<x> temp;
		
		node<x> *current = top;

		while (current != NULL)
		{
			temp.push(current->info);
			current = current->next;
		}
		temp.printFromTop();
	}
}

template <class x>
bool stackLL<x>::search(x item)
{
	if (!isEmpty())
	{
		node<x> *current = top;
		bool found = false;

		while (current != NULL && !found)
		{
			if (current->info != item)
				found = false;
			current = current->next;
		}

		return true;
	}
	else return false;
}

template <class x>
void stackLL<x>::reverse()
{
	if (!isEmpty())
	{
		stackLL<x> temp;

		node<x> *current = top;

		while (current != NULL)
		{
			temp.push(current->info);
			current = current->next;
		}

		current = top;
		node<x> *tempcurrent = temp.top;

		while (tempcurrent != NULL)
		{
			current->info = tempcurrent->info;
			current = current->next;
			tempcurrent = tempcurrent->next;
		}
	}
}

template <class x>
x stackLL<x>::getTop()
{
	assert(!isEmpty());
	return top->info;
}