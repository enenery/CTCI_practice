//Author: Erii Sugimioto Date: Spring 2016
#include "UnsortedLinkedList.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/*template <class Type>
istream& operator >> (istream& in, SortedLinkedList<Type> &other)
{
string s;
in >> s[0];
return in;
}*/

template <class x>
UnsortedLinkedList<x>::UnsortedLinkedList(int m)
{
	max = m;
	length = 0;
	first = NULL;
	last = NULL;
}

template <class x>
UnsortedLinkedList<x>::~UnsortedLinkedList()
{
	if (!isEmpty())
	{
		nodeType<x> *current;

		while (first != NULL)
		{
			current = first;
			first = first->next;
			delete current;
		}
		last = NULL;
		length = 0;
	}
}

template <class x>
UnsortedLinkedList<x>::UnsortedLinkedList(const UnsortedLinkedList<x>& other)
{
	if (this != &other)
	{
		if (other.length == 0)
		{
			first = last = NULL;
			length = 0;
			max = 100;
		}
		else
		{
			length = other.length;
			max = other.max;
			first = new nodeType<x>;
			nodeType<x> *p = first;
			nodeType<x> *q = other.first;

			while (q != NULL)
			{
				p->info = q->info;
				q = q->next;

				if (q != NULL)
				{
					p->next = new nodeType<x>;
					p = p->next;
				}
				else
				{
					p->next = NULL;
					last = p;
				}
			}
		}
	}
}

template <class x>
void UnsortedLinkedList<x>::operator=(const UnsortedLinkedList<x>& other)
{
	if (this != &other)
	{
		if (other.length == 0)
		{
			first = last = NULL;
			length = 0;
			max = 100;
		}
		else
		{
			length = other.length;
			max = other.max;

			first = new nodeType<x>;
			nodeType<x> *p = first;
			nodeType<x> *q = other.first;

			while (q != NULL)
			{
				p->info = q->info;
				q = q->next;

				if (q != NULL)
				{
					p->next = new nodeType<x>;
					p = p->next;
				}
				else
				{
					p->next = NULL;
					last = p;
				}
			}
		}
	}
}

template <class x>
void UnsortedLinkedList<x>::printForward()
{
	if (!isEmpty())
	{
		nodeType<x> *current;
		current = first;

		while (current != NULL)
		{
			cout << current->info << ' ';
			current = current->next;
		}
	}
}

template <class x>
void UnsortedLinkedList<x>::insertItemFront(x item)
{
	if (!isFull())
	{
		nodeType<x> *newNode = new nodeType<x>;
		newNode->info = item;
		newNode->next = NULL;

		//When the list is empty
		if (first == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			newNode->next = first;
			first = newNode;
		}
		length++;
	}
}

template <class x>
void UnsortedLinkedList<x>::insertItemBack(x item)
{
	if (!isFull())
	{
		nodeType<x> *newNode = new nodeType<x>;
		newNode->info = item;
		newNode->next = NULL;

		//When the list is empty
		if (first == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
		length++;
	}
}

template <class x>
bool UnsortedLinkedList<x>::isEmpty()
{
	return (length == 0);
}

template <class x>
bool UnsortedLinkedList<x>::isFull()
{
	return (length == max);
}

template <class x>
int UnsortedLinkedList<x>::getLength()
{
	return length;
}

template <class x>
int UnsortedLinkedList<x>::getNumOfItem(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			nodeType<x> *current = first;
			int count = 0;

			while (current != NULL)
			{
				if (current->info == item)
					count++;

				current = current->next;
			}
			return count;
		}
		else return 0;
	}
	else return 0;
}
template <class x>
int UnsortedLinkedList<x>::getNumOfSmaller(x item)
{
	if (!isEmpty())
	{
		//checks if the first element in the list is larger than the item,
		//which means the num of smaller elements is 0.
		if (first->info >= item)
			return 0;
		else
		{
			//checks if the last element in the list is larger than the item,
			//which means the num of smaller elements is the length of the list
			if (last->info < item)
				return length;
			else
			{
				nodeType<x> *current = first;
				int count = 0;
				while (current != NULL && current->info < item)
				{
					count++;
					current = current->next;
				}
				return count;

			}
		}
	}
}

template <class x>
int UnsortedLinkedList<x>::getNumOfLarger(x item)
{
	if (!isEmpty())
	{
		//case 1: when all the elements in the list are bigger than the parameter
		if (first->info > item)
			return length;
		else
		{
			if (last->info <= item)
				return  0;
			else
			{
				nodeType<x> *current = first;
				int count = 0;
				while (current != NULL && current->info <= item)
				{
					count++;
					current = current->next;
				}
				count = length - count;
				return count;
			}
		}
	}

}

template <class x>
void UnsortedLinkedList<x>::deleteItem(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			nodeType<x> *current = first;
			nodeType<x> *trailing = NULL;
			nodeType<x> *temp = NULL;

			while (current != NULL)
			{
				if (current->info == item)
				{
					if (first == last)
					{
						first = last = NULL;
						delete current;
					}
					else
					{
						if (first == current)
						{
							trailing = current;
							first = first->next;
							current = current->next;
							delete trailing;
						}
						else
						{
							if (last == current)
							{
								last = trailing;
								last->next = NULL;
								trailing = current;
								current = current->next;
								delete trailing;
							}
							else
							{
								temp = current;
								current = current->next;
								trailing->next = current;
								trailing->next = current->next;
								delete temp;
							}
						}
					}
					length--;
				}
				else
				{
					trailing = current;
					current = current->next;
				}
			}
		}
	}
}

template <class x>
void UnsortedLinkedList<x>::deleteItem2(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			nodeType<x> *current = first;
			nodeType<x> *trailing = NULL;
			//nodeType<x> *temp = NULL;

			while (current != NULL)
			{
				if (current->info == item)
				{
					if (first == last)
					{
						first = last = NULL;
						delete current;
						current = NULL;
					}
					else
					{
						if (first == current)
						{
							//trailing = current;
							first = first->next;
							//current = current->next;
							delete current;
							current = first;
						}
						else
						{
							if (last == current)
							{
								last = trailing;
								last->next = NULL;
								//trailing = current;
								//current = current->next;
								delete current;
								current = NULL;
							}
							else
							{
								/*temp = current;
								current = current->next;
								trailing->next = current;*/
								trailing->next = current->next;
								delete current;
								current = trailing->next;
							}
						}
					}
					length--;
				}
				else
				{
					trailing = current;
					current = current->next;
				}
			}
		}
	}
}
template <class x>
void UnsortedLinkedList<x>::deleteSmaller(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			cout << "\nitem was found in your list...: ";
			nodeType<x> *current = first;
			nodeType<x> *trailing = NULL;

			while (current != NULL)
			{
				if (current->info < item)
				{
					cout << "\ndeleting the item in the list...";

					if (first == last)//case 2: single element list
					{
						cout << "\nsingle element...";
						first = NULL;
						last = NULL;
						delete current;
						current = NULL;

					}
					else
					{
						if (first == current)//case 3: deleting the first element
						{
							first = first->next;
							trailing = current;
							current = current->next;
							delete trailing;
						}
						else
						{
							if (current == last)//case 4: deleting the last element
							{
								last = trailing;
								last->next = NULL;
								delete current;
								current = NULL;
							}
							else
							{
								nodeType<x> *temp = current;
								trailing->next = current->next;
								current = current->next;
								delete temp;
							}
						}
					}
					length--;
				}
				else
				{
					trailing = current;
					current = current->next;
				}

			}

		}
	}
}

template <class x>
void UnsortedLinkedList<x>::deleteLarger(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			cout << "\nitem was found in your list...: ";
			nodeType<x> *current = first;
			nodeType<x> *trailing = NULL;

			while (current != NULL)
			{
				if (current->info > item)
				{
					cout << "\ndeleting the item in the list...";

					if (first == last)//case 2: single element list
					{
						cout << "\nsingle element...";
						first = NULL;
						last = NULL;
						delete current;
						current = NULL;

					}
					else
					{
						if (first == current)//case 3: deleting the first element
						{
							first = first->next;
							trailing = current;
							current = current->next;
							delete trailing;
						}
						else
						{
							if (current == last)//case 4: deleting the last element
							{
								last = trailing;
								last->next = NULL;
								delete current;
								current = NULL;
							}
							else
							{
								nodeType<x> *temp = current;
								trailing->next = current->next;
								current = current->next;
								delete temp;
							}
						}
					}
					length--;
				}
				else
				{
					trailing = current;
					current = current->next;
				}

			}

		}
	}
}

template <class x>
int UnsortedLinkedList<x>::replace_item(x olditem, x newitem)
{
	int count = 0;
	if (!isEmpty())
	{
		if (search_item(olditem))
		{
			nodeType<x> *current = first;

			while (current != NULL)
			{
				if (current->info == olditem)
				{
					current->info = newitem;
					count++;
				}
				current = current->next;
			}
		}
	}
	return count;
}

template <class x>
void UnsortedLinkedList<x>::callReplace_itemR(x olditem, x newitem)
{
	if (!isEmpty())
	{
		int count = 0;
		replace_itemR(olditem, newitem, first, count);
	}
}

template <class x>
int UnsortedLinkedList<x>::replace_itemR(x olditem, x newitem, nodeType<x> *current, int count)
{
	if (current != NULL)
	{
		if (current->info == olditem)
		{
			current->info = newitem;
			count++;
		}
		replace_itemR(olditem, newitem, current->next, count);
	}
	else return count;
}
template <class x>
bool UnsortedLinkedList<x>::search_item(x item)
{
	if (!isEmpty())
	{
		nodeType<x> *current = first;

		while (current != NULL)
		{
			if (current->info == item)
				return true;

			current = current->next;
		}
	}
     return false;
}

template <class x>
x UnsortedLinkedList<x>::getLargest()
{
	if (isEmpty())
	{
		cout << "\nError: Empty list-System Exit";
		exit(0);
	}
	else
	{
		x largest;
		nodeType<x> *current = first;
		largest = current->info;

		while (current != NULL)
		{
			if (current->info > largest)
			{
				largest = current->info;
			}
			current = current->next;
		}
		return largest;
	}
	
	
}

template <class x>
bool UnsortedLinkedList<x>::dummySearch(x item)
{
	return searchR(first, item);
}

template <class x>
bool UnsortedLinkedList<x>::searchR(nodeType<x> *current, x item)
{
	if (current == NULL)
		return false;
	else {
		if (current->info == item)
			return true;
		else
			searchR(current->next, item);
	}

}

template <class x>
void UnsortedLinkedList<x>::devideInHalf(nodeType<x> *L1, nodeType<x> *&L2)
{
	if (L1 == NULL || L1->next == NULL)
		L2 = NULL;
	else
	{
		nodeType<x> *current = L1->next;
		nodeType<x> *middle = L1;

		if (current != NULL)
			current = current->next;
		while (current != NULL)
		{
			middle = middle->next;
			current = current->next;

			if (current != NULL)
				current = current->next;
		}

		L2 = middle->next;
		middle->next = NULL;
	}
}

template <class x>
nodeType<x>* UnsortedLinkedList<x>::merge(nodeType<x> *L1, nodeType<x> *L2)
{
	if (L1 == NULL)
		return L2;
	else
	{
		if (L2 == NULL)
			return L1;
		else {
			nodeType<x> *lastSmall;
			nodeType<x> *mergedFirst;

			if (L1->info < L2->info)
			{
				mergedFirst = L1;
				L1 = L1->next;
			}
			else
			{
				mergedFirst = L2;
				L2 = L2->next;
			}

			lastSmall = mergedFirst;

			while (L1 != NULL && L2 != NULL)
			{
				if (L1->info < L2->info)
				{
					lastSmall->next = L1;
					L1 = L1->next;
				}
				else
				{
					lastSmall->next = L2;
					L2 = L2->next;
				}

				lastSmall = lastSmall->next;
			}

			if (L1 == NULL)
			{
				lastSmall->next = L2;
			}
			else
			{
				lastSmall->next = L1;
			}

			return mergedFirst;
		}
	}
}


template <class x>
void UnsortedLinkedList<x>::recMergeSort(nodeType<x> *&L1)
{
	nodeType<x> *L2;

	if (L1 != NULL)
		if (L1->next != NULL)
		{
			devideInHalf(L1, L2);
			recMergeSort(L1);
			recMergeSort(L2);
			L1 = merge(L1, L2);
		}
}

template <class x>
void UnsortedLinkedList<x>::mergeSort()
{
	if (first != NULL)
	{
		recMergeSort(first);
	}

	if (first == NULL)
		last = NULL;
	else
	{
		last = first;
		while (last->next != NULL)
			last = last->next;
	}
}

template <class x>
void UnsortedLinkedList<x>::split(nodeType<x> *L1, nodeType<x> *&L2)
{
	if (L1 != NULL)
	{
		nodeType<x> *pivot = L1;
		nodeType<x> *current = L1->next;
		nodeType<x> *small = L1;
		x temp;

		while (current != NULL)
		{
			if (current->info < pivot->info)
			{
				small = small->next;

				if (small != current)
				{
					temp = small->info;
					small->info = current->info;
					current->info = temp;
				}
			}
			current = current->next;
		}

		temp = small->info;
		small->info = pivot->info;
		pivot->info = temp;

		L2 = small->next;
		small->next = NULL;
	}
	
}

template <class x>
void UnsortedLinkedList<x>::recQuickSort(nodeType<x> *&L1)
{
	if (L1 != NULL)
	{
		nodeType<x> *L2;
		if (L1->next != NULL)
		{
			split(L1, L2);
			recQuickSort(L1);
			recQuickSort(L2);
		}
	}
}

template <class x>
void UnsortedLinkedList<x>::quickSort()
{
	if (first != NULL)
	{
		recMergeSort(first);
	}

	/*if (first == NULL)
		last = NULL;
	else
	{
		last = first;
		while (last->next != NULL)
			last = last->next;
	}*/
}
