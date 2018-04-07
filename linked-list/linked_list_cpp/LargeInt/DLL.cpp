#include "DoublyLinkedList1.h"
#include <iostream>
#include <string>

using namespace std;

//overloaded operator << 
template <class Type>
ostream& operator << (ostream& out, const DoublyLinkedList<Type>& other)
{   nodeType<Type> *current = first;

	while (current != NULL)
	{
		out << current->info << ' ';
		current = current->next;
	}
	return out;
}

//overloaded operator >>
template <class Type>
istream& operator >> (istream& in, DoublyLinkedList<Type> &other)
{
	string s;
	in >> s[0];
	return in;
}

template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
	first = NULL;
	last = NULL;
	iterator = NULL;
	length = 0;
}

template <class Type>
DoublyLinkedList <Type>::~DoublyLinkedList()
{
	if (!isEmpty())
	{
		nodeType<Type> *current;
		while (first != NULL)
		{
			current = first;
			first = first->next;
			delete current;

		}
	}
}

template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type> & other)
{
		max = other.max;
		length = other.length;

		first = new nodeType<Type>;
		nodeType<Type> *q = other.first;
		nodeType<Type> *p = first;
		
		while (q != NULL)
		{
			p->info = q->info;
			q = q->next;

			if (q != NULL)
			{
				p->next = new nodeType<Type>;
				p = p->next;
			}
			else
			{
				p->next = NULL;
				last = p;
			}
		}
}

template <class Type>
void DoublyLinkedList<Type>::initializeList()
{
	first = NULL;
	last = NULL;
	iterator = NULL;
	length = 0;
}

template <class Type>
DoublyLinkedList<Type> DoublyLinkedList<Type>::operator = (const DoublyLinkedList<Type>& other)
{
	if (this != &other)
	{
		if (other.isEmpty())
		{
			first = last = NULL;
			length = 0;
			max = 100;
		}
		else
		{
			first = new nodeType<Type>;
			nodeType<Type> *p;
			p = first;
			nodeType<Type> *q = other.fiirst;


		}
	}
}
template <class Type>
bool DoublyLinkedList <Type> ::isEmpty() 
{
	return (first == NULL);
}

template <class Type>
int DoublyLinkedList <Type> :: getLength()
{
	cout << "\n";
	return length;
}

template <class Type>
void DoublyLinkedList <Type> ::setLength(int n)
{
	length = n;
}

template <class Type>
void DoublyLinkedList <Type> :: insertItemBack(const Type& insertItem)
{	
	nodeType <Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = insertItem;
	newNode->next = NULL;
	newNode->back = NULL;

		if (first == NULL)
		{
			first = last = newNode;
		}
		else
		{
			last->next = newNode;
			newNode->back = last;
			last = newNode;
		}	
		length++;
}

template <class Type>
void DoublyLinkedList <Type> ::insertItemFront(const Type& insertItem)
{
	nodeType <Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = insertItem;
	newNode->next = NULL;
	newNode->back = NULL;

	if (first == NULL)
	{
		first = last = newNode;
		first->back = NULL;
		first->next = NULL;
	}
	else
	{
		newNode->next = first;
		first->back = newNode;
		first = newNode;
	}
	length++;
}
	
template <class Type>
void DoublyLinkedList <Type> ::printForward()
{
	nodeType<Type> *current;
	current = first;

	while(current != NULL)
	{
		cout << current->info << ' ';
		current = current->next;
	}
}

template <class Type>
void DoublyLinkedList <Type> ::printBackward()
{
	nodeType<Type> *current;
	current = last;

	while (current != NULL)
	{
		cout << current->info << ' ';
		current = current->back;
	}

}

template <class Type>
void DoublyLinkedList <Type> ::printForwardCallRec()
{
	printForwardRec(first);
}

template <class Type>
void DoublyLinkedList <Type> ::printForwardRec(nodeType<Type> *p)
{
	if (p != NULL)
	{
		cout << p->info << ' ';
		printForwardRec(p->next);
	}
}

template <class Type>
void DoublyLinkedList <Type> ::printBackwardCallRec()
{
	printBackwardRec(first);
}

template <class Type>
void DoublyLinkedList<Type>::printBackwardRec(nodeType<Type> *p)
{
	if (p != NULL)
	{
		printBackwardRec(p->next);
		cout << p->info << ' ';
	}
}

template <class Type>
void DoublyLinkedList<Type>::deleteLast()
{
	if (!isEmpty())
	{
		if (first == last)
		{
			delete first;
			first = last = NULL;
		}
		else
		{
			nodeType<Type> *temp = last;
			last = last->back;
			last->next = NULL;
			delete temp;
		}
		length--;
	}
}

template <class Type>
void DoublyLinkedList<Type>::deleteFirst()
{
	if (!isEmpty())
	{
		nodeType<Type> *current = first;
		first = first->next;
		delete current;
	}
}
/*
template <class Type>
void DoublyLinkedList :: deleteNode(const Type& deleteItem)
{
	cout << "hi";
}

/*template <class Type>
DoublyLinkedList DoublyLinkedList <Type> ::setIterator(int n)
{
	
}*/

template <class Type>
int DoublyLinkedList<Type>::getNumOfItem(Type item)
{
	if (!isEmpty())
	{
		nodeType<Type> *current = first;
		int count = 0;

		while (current != NULL)
		{
			if (current->info == item)
				count++;

			current = current->next;
		}
		return count;
	}
	return 0;
}

template <class Type>
void DoublyLinkedList<Type>::replace_item(Type olditem, Type newitem)
{
	if (!isEmpty())
	{
		nodeType<Type> *current = first;

		while (current != NULL)
		{
			if (current->info == olditem)
				current->info = newitem;

			current = current->next;
		}
	}
}
template <class Type>
void DoublyLinkedList<Type>::call_replace_itemR(Type olditem, Type newitem)
{
	if (!isEmpty())
		replace_itemR(olditem, newitem, first);
}

template <class Type>
void DoublyLinkedList<Type>::replace_itemR(Type olditem, Type newitem, nodeType<Type> *&current)
{
	if (current != NULL)
	{
		if (current->info == olditem)
			current->info = newitem;

		replace_itemR(olditem, newitem, current->next);
	}
}


/*template <class Type>
void DoublyLinkedList<Type>::iteratorFrontToBack(int n)
{

}*/

template <class Type>
void DoublyLinkedList<Type>::setIteratorFirst()
{
	iterator = first;
}

template <class Type>
void DoublyLinkedList<Type>::setIteratorLast()
{
	iterator = last;
}

template <class Type>
Type DoublyLinkedList<Type>::getIteratorInfo()
{
	return iterator->info;
}

template <class Type>
void DoublyLinkedList<Type>::setIteratorNext()
{
	iterator = iterator->next;
}

template <class Type>
void DoublyLinkedList<Type>::setIteratorBack()
{
	iterator = iterator->back;
}

template <class Type>
bool DoublyLinkedList<Type>::didIteratorFinish()
{
	if (iterator == NULL)
		return true;
	else
		return false;
}

template <class Type>
bool DoublyLinkedList<Type>::isNextNull()
{
	if (iterator->next == NULL)
		return true;
	else
		return false;
}
