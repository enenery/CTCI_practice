#include "SortedLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

/*template <class Type>
istream& operator >> (istream& in, SortedLinkedList<Type> &other)
{
	string s;
	in >> s[0];
	return in;
}*/

template <class x>
SortedLinkedList<x>::SortedLinkedList(int m)
{
	max = m;
	length = 0;
	first = NULL;
	last = NULL;
}

template <class x>
SortedLinkedList<x>::~SortedLinkedList()
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
SortedLinkedList<x>::SortedLinkedList(const SortedLinkedList<x>& other)
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
void SortedLinkedList<x>::operator=(const SortedLinkedList<x>& other)
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
void SortedLinkedList<x>::printForward()
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
void SortedLinkedList<x>::insertItem(x item)
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
			//When the first element(the smallest) in the list is Larger than the item
			//(In case the item is the smallest in the list)
			if (first->info >= item)
			{
				newNode->next = first;
				first = newNode;
			}
			else
			{
				//When the last element (the largest) is smaller than the item
				//(in case the item is the largest in the list)
				if (last->info <= item)
				{
					last->next = newNode;
					last = newNode;
				}
				else
				{
					//When the item should be placed somewhere in the middle of the list
					nodeType<x> *current = first;
					nodeType<x> *trailing = NULL;

					while (current != NULL && current->info <= item)
					{
						trailing = current;
						current = current->next;
					}
					trailing->next = newNode;
					newNode->next = current;
				}
			}

		}
	}
	length++;
	
}

template <class x>
void SortedLinkedList<x>::callInsertItemR(x item)
{
	if (!isFull())
	{
		insertItemR(item, first);
	}
	
}

template <class x>
void SortedLinkedList<x>::insertItemR(x item, nodeType<x> *&current)
{
	
		if (current == NULL || current->info>item)
		{
			nodeType<x> *temp = new nodeType<x>;
			temp->info = item;
			temp->next = current;
			current = temp;
			if (last == NULL || temp->next == NULL)
				last = current;
		}
		else insertItemR(item, current->next);
}
template <class x>
bool SortedLinkedList<x>::isEmpty()
{
	return (length == 0);
}

template <class x>
bool SortedLinkedList<x>::isFull()
{
	return (length == max);
}

template <class x>
int SortedLinkedList<x>::getLength()
{
	return length;
}

template <class x>
int SortedLinkedList<x>::getNumOfSmaller(x item)
{
	if (!isEmpty())
	{
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
				while (current->info < item)
				{
					count++;
					current = current->next;
				}
				return count;

			}
		}
	}
	else return 0;
}

template <class x>
int SortedLinkedList<x>::getNumOfLarger(x item)
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
void SortedLinkedList<x>::deleteSmaller2(x item)
{
	if (!isEmpty())
	{
		nodeType<x> *current;
		while (first != NULL && first->info < item)
		{
			current = first;
			first = first->next;
			delete current;
			length--;
		}
		
		if (first == NULL)
			last = NULL;
	}	
}

template <class x>
void SortedLinkedList<x>::deleteLarger(x item)
{
	if (!isEmpty())
	{
		if(!(last->info < item))
		{
			nodeType<x> *current;

			if (first->info > item)
			{
				while (first != NULL)
				{
					current = first;
					first = first->next;
					delete current;
				}
			}
			else
			{
				current = first;
				nodeType<x> *trailing;
				int count = 0;
				while (current->info <= item)
				{
					count++;
					trailing = current;
					current = current->next;
				}
				last = trailing;
				last->next = NULL;

				while (current != NULL)
				{
					trailing = current;
					current = current->next;
					delete trailing;
				}

			}
		}
		
	}
}

template <class x>
void SortedLinkedList<x>::deleteLarger2(x item)
{
	if (!isEmpty())
	{
			nodeType<x> *current = first;
			nodeType<x> *trailing = NULL;

			while (current != NULL && current->info <= item)
			{
				trailing = current;
				current = current->next;
			}

			if (first != last)
			{
				last = trailing;
				last->next = NULL;
			}

			while (current != NULL)
			{
				trailing = current;
				current = current->next;
				delete trailing;
				length--;
			}
	}
}
template <class x>
int SortedLinkedList<x>::replace_item(x olditem, x newitem)
{
	int count = 0;
	if(!isEmpty())
	{
		if (search_item(olditem))
		{
			nodeType<x> *current = first;

			while (current->info < olditem)
			{
				current = current->next;
			}

			while (current->info == olditem)
			{
				count++;
				current->info = newitem;
				current = current->next;
			}
		}

	}
	 return count;

}

template <class x>
bool SortedLinkedList<x>::search_item(x item)
{
	if (!isEmpty())
	{
		if (first->info > item || last->info < item)
		{
			return false;
		}
		else
		{
			nodeType<x> *current = first;

			while (current->info < item)
			{
				current = current->next;
			}

			if (current->info == item)
			{
				return true;
			}
				
			else
				return false;
		}
	}
	else return false;
}

template <class x>
int SortedLinkedList<x>::getNumOfItem(x item)
{
	if (!isEmpty())
	{
		int count = 0;
		bool found = false;
		nodeType<x> *current = first;

		while (current != NULL & !found)
		{
			if (current->info == item)
			{
				found = true;
				count++;
			}
			current = current->next;
		}

		if (count == 1)
		{
			while (current->info == item)
			{
				count++;
				current = current->next;
			}				
		}
		return count;
	}
	return 0;
}

template <class x>
int SortedLinkedList<x>::getNumOfItem2(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{
			nodeType<x> *current = first;
			int count = 0;

			while (current->info != item)
				current = current->next;

			while (current != NULL && current->info == item)
			{
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
void SortedLinkedList<x>::printPositionOfItem(x item)
{
	if (!isEmpty())
	{
		if(search_item(item))
		{
			nodeType<x> *current = first;
			int count = 1;
			cout << "\nItem(s) Found in the Following Positions:  ";
			while (current != NULL && current->info <= item)
			{
				if (current->info == item)
				{
					cout << count << " ";
				}
				count++;
				current = current->next;
			}
		}
		else cout << "\nThe Item Not Found in the List.";
	}		
	else cout << "\nThe List is Empty.";
}

template <class x>
void SortedLinkedList<x>::printPosition(x item)
{
	if (!isEmpty())
	{
		if (search_item(item))
		{

			nodeType<x> *current = first;
			int count = 0;
			cout << "\nItem(s) Found in the Following Positions:  ";
			while (current != NULL && current->info <= item)
			{
				count++;
				if (current->info == item)
				{
					cout << count << " ";
				}
				current = current->next;
			}
		}
		else cout << "\nThe Item Not Found in the List.";
	}
	else cout << "\nThe List is Empty.";
}

template <class x>
void SortedLinkedList<x>::devideInHalf(nodeType<x> *L1, nodeType<x> *&L2)
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
nodeType<x>* SortedLinkedList<x>::merge(nodeType<x> *L1, nodeType<x> *L2)
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
void SortedLinkedList<x>::recMergeSort(nodeType<x> *&L1)
{
	nodeType<x> *L2;
	
	if(L1 != NULL)
		if (L1->next != NULL)
		{
			devideInHalf(L1, L2);
			recMergeSort(L1);
			recMergeSort(L2);
			L1 = merge(L1, L2);
		}
}

template <class x>
void SortedLinkedList<x>::mergeSort()
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
void SortedLinkedList<x>::displayKtoLast(nodeType<x> *front, int& k)
{
	if (front == NULL)
		return;

	if (front && k > 0)
	{
		displayKtoLast(front->next, --k);
	}
	else
	{
		cout << front->info << " ";
		displayKtoLast(front->next, --k);
	}
}

template <class x>
void SortedLinkedList<x>::displayKtoLast(int k)
{
	displayKtoLast(first, k);
}

template <class x>
bool SortedLinkedList<x>::has_cycle(nodeType<x> *head)
{
	if (head != NULL && head->next != NULL)
	{
		nodeType<x>* trailing = head->next;
		nodeType<x>* current = head->next;

		while (current != NULL)
		{
			cout << current->info << " ";
			if (current->next == trailing)
				return true;

			trailing = current;
			current = current->next;
		}
	}

	return false;
}

template <class x>
bool SortedLinkedList<x>::has_cycle_dummy()
{
	return has_cycle(first);
}