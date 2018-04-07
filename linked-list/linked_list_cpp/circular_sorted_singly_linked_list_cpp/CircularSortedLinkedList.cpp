#include "CircularSortedLinkedList.h"
#include <iostream>
using namespace std;



template <class x>
CircularSortedLinkedList <x> ::CircularSortedLinkedList(int m)
{
	max = m;
	length = 0;
	first = NULL;
}

template <class x>
CircularSortedLinkedList <x> ::CircularSortedLinkedList(const CircularSortedLinkedList <x> &other)
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
CircularSortedLinkedList <x> :: ~CircularSortedLinkedList()
{
	makeEmpty();
}

template <class x>
void CircularSortedLinkedList<x>::makeEmpty()
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

			if (current == first)
			{
				delete current;
				current = NULL;
			}

		} while (current != NULL);
		
		length = 0;
	}
}


template <class x>
bool CircularSortedLinkedList<x>::search_item(x item)
{
	if (!isEmpty())
	{
		nodeType<x> *current = first->next;
		bool found = false;

		do
		{
			if (current->info == item)
			{
				found = true;
				return true;
			}
			current = current->next;
		} while (current != first->next && !found);

			return false;
	}
	else return false;
}
template <class x>
void CircularSortedLinkedList <x>::insertItem(x item)
{
	if (!isFull())
	{
		nodeType<x> *newNode = new nodeType<x>;
		newNode->info = item;
		newNode->next = NULL;

		if (isEmpty())
		{
			cout << "\empty list";
			first = newNode;
			first->next = newNode;
		}
		else
		{
			if (first->next->info >= item)
			{
				newNode->next = first->next;
				first->next = newNode;
			}
			else
			{
				if (first->info <= item)
				{
					newNode->next = first->next;
					first->next = newNode;
					first = newNode;
				}
				else
				{
					nodeType<x> *current = first->next;
					nodeType<x> *trailing = NULL;

					while (current->info < item)
					{
						trailing = current;
						current = current->next;
					}
					newNode->next = current;
					trailing->next = newNode;
				}
			}
			
		}
		length++;
	}
}
template <class x>
int CircularSortedLinkedList <x> :: howMany(x item)
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
int CircularSortedLinkedList<x>::getNumOfItem(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			if (first == first->next)
			{
				if (first->info == item)
					return 1;
				else
					return 0;
			}
			else
			{
				nodeType<x> *current = first->next;
				int count = 0;

				while (current->info != item)
					current = current->next;

				do
				{
					count++;
					current = current->next;
				}while (current != first->next && current->info == item);
				return count;
			}
		}
		else return 0;
	}
	else return 0;
}

template <class x>
bool CircularSortedLinkedList<x>::isEmpty()
{
	return (length == 0);
}

template <class x>
bool CircularSortedLinkedList<x>::isFull()
{
	return (max == length);
}

template <class x>
void CircularSortedLinkedList<x>::printForward()
{
	nodeType<x> *current = first->next;

	if(!isEmpty())
	{
		do
		{
			cout << current->info << ' ';
			current = current->next;

		} while (current != first->next);
	}
	
}

template <class x>
x CircularSortedLinkedList<x>::getSmallest()
{
	return first->next->info;
}


template <class x>
x CircularSortedLinkedList<x>::getLargest()
{
	return first->info;
}

template <class x>
void CircularSortedLinkedList<x>::printPosition(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			nodeType<x> *current = first->next;
			int count = 0;

			do
			{
				count++;
				if (current->info == item)
					cout << count << " ";
				current = current->next;
			} while (current != first->next && current->info <= item);
		}
		else cout << "\nitem not found.";
	}
	else cout << "\nempty list.";
}

template <class x>
void CircularSortedLinkedList<x>::deleteSmaller(x item)
{
	if (!isEmpty())
	{
		if (first->next->info < item)
		{
			nodeType<x> *current;
			cout << "\nfirst->next is smaller than the item:";
			do
			{
				if (first != first->next)
				{
					current = first->next;
					first->next = first->next->next;
					first->next = first->next;
					delete current;
					length--;
					cout << "\ndeleting current:";
				}

				if (first == first->next && first->info < item)
				{
					delete first;
					length = 0;
					cout << "\ndeleting first: ";
				}

			} while (length > 0 && first->next->info < item);
		}
	}
}


