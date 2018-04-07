//Author: Erii Sugimoto Date: Spring 2016
#include "CircularSortedDoublyLinkedList.h"
#include <iostream>
using namespace std;

template <class x>
CircularSortedDoublyLinkedList<x>::CircularSortedDoublyLinkedList(int m)
{
	max = m;
	length = 0;
	first = NULL;
}

template <class x>
CircularSortedDoublyLinkedList <x> ::CircularSortedDoublyLinkedList(const CircularSortedDoublyLinkedList <x> &other)
{
	assert(this != &other) //<<later go look up for what this statement is trully doing

	max = &other.max;
	length = &other.length;

	nodeType<x> *current = new nodeType<x>;
	current = &other.first;

	do
	{
		first = current;
		current = current->next;
	} while (current != &other.first->next);
}

template <class x>
CircularSortedDoublyLinkedList<x>::~CircularSortedDoublyLinkedList()
{
	if (!isEmpty())
	{
		nodeType<x> *current = first->next;
		nodeType<x> *trailing = NULL;

		do
		{
			trailing = current;
			current = current->next;
			delete trailing;
		} while (current != first);
	}
}

template <class x>
void CircularSortedDoublyLinkedList <x>::insertItem(x item)
{
	if (!isFull())
	{
		nodeType<x> *newNode = new nodeType<x>;
		newNode->info = item;
		newNode->next = newNode;
		newNode->back = newNode;

		if (isEmpty())
		{
			first = newNode;
		}
		else
		{
			if (first->next->info >= item || first->info <= item)
			{
				newNode->next = first->next;
				first->next->back = newNode;
				first->next = newNode;
				newNode->back = first;
				if (first->info <= item)
					first = newNode;
			}
			else
			{
				nodeType<x> *current = first->next;
				nodeType<x> *trailing = NULL;

				do
				{
					trailing = current;
					current = current->next;
				} while (current->info < item);

				newNode->next = current;
				current->back = newNode;
				trailing->next = newNode;
				newNode->back = trailing;
			}
		}
	}
	length++;
}
template <class x>
int CircularSortedDoublyLinkedList <x> ::howMany(x item)
{
	if (isEmpty())
	{
		cout << "The list is empty.\n";
		return 0;
	}
	else
	{
		cout << "The list is not empty.\n";

		nodeType<x> *current = first->next;
		int count = 0;
		do
		{
			if (current->info == item)
				count++;

			current = current->next;
		} while (current != first->next);

		return count;
	}
}

template <class x>
bool CircularSortedDoublyLinkedList<x>::isEmpty()
{
	return (length == 0);
}

template <class x>
bool CircularSortedDoublyLinkedList<x>::isFull()
{
	return (length == max);
}
template <class x>
void CircularSortedDoublyLinkedList<x>::printForward()
{
	if (!isEmpty())
	{
		nodeType<x> *current = first->next;

		do
		{
			cout << current->info << ' ';
			current = current->next;

		} while (current != first->next);
	}

}

template <class x>
void CircularSortedDoublyLinkedList<x>::printBackward()
{
	if (!isEmpty())
	{
		nodeType<x> *current = first;
		do
		{
			cout << current->info << " ";
			current = current->back;
		} while (current != first);
	}
}

template <class x>
void CircularSortedDoublyLinkedList<x>::callPrintBackwardR()
{
	printBackwardR(first->next);
}
template <class x>
void CircularSortedDoublyLinkedList<x>::printBackwardR(nodeType<x> *current)
{
	if(current != first)
	printBackwardR(current->next);
	cout << current->info << " ";
}
template <class x>
void CircularSortedDoublyLinkedList<x>::printBothways()
{
	if (!isEmpty())
	{
		nodeType<x> *current = first->next;

		do
		{
			cout << current->info << ' ';
			current = current->next;

		} while (current != first->next);

		current = first;
		do
		{
			cout << current->info << " ";
			current = current->back;
		} while (current != first);
	}

}

template <class x>
void CircularSortedDoublyLinkedList<x>::callPrintBothwaysR()
{
	printBothwaysR(first->next);
}
template <class x>
void CircularSortedDoublyLinkedList<x>::printBothwaysR(nodeType<x> *current)
{
		cout << current->info << " ";
		if(current != first)
		printBothwaysR(current->next);
		cout << current->info << " ";
}
template <class x>
x CircularSortedDoublyLinkedList<x>::getSmallest()
{
	return first->next->info;
}


template <class x>
x CircularSortedDoublyLinkedList<x>::getLargest()
{
	return first->info;
}

template <class x>
int CircularSortedDoublyLinkedList<x>::getNumOfSmallerItem(x item)
{
	if (!isEmpty())
	{
		if (first->next->info >= item)
			return 0;
		else
		{
			if (first->info < item)
				return length;
			else
			{
				nodeType<x> *current = first->next;
				int count = 0;

				while (current->info < item)
				{
					count++;
					current = current->next;
				}
				return count;
			}
		}
	}
	return 0;
}

template <class x>
void CircularSortedDoublyLinkedList<x>::deleteLast()
{
	if (!isEmpty())
	{
		if (first == first->next)
		{
			delete first;
			first =  NULL;
		}
		else
		{
			nodeType<x> *temp = first;
			first = first->back;
			first->next->back = first;
			first->next = temp->next;
			delete temp;
		}
		length--;
	}
}


