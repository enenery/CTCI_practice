#include "QueuesLL.h"
#include <iostream>
using namespace std;
#include <cassert>

template <class x>
queueLL<x>::queueLL()
{
	front = NULL;
	rear = NULL;
}

template <class x>
queueLL<x>::~queueLL()
{
	node<x> *temp;

	while(front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}

template <class x>
queueLL<x>::queueLL(const queueLL& other)
{
	if (this != other)
	{
		if (other.front != NULL)
		{
			node<x> *currentO = other.front;
			node<x> *newNode = new node<x>;
			front = rear = newNode;
			newNode->next = NULL;
			newNode->info = currentO->info;
			currentO = currentO->next;

			while (currentO != NULL)
			{
				newNode->next = new node<x>;
				newNode->next = NULL;
				newNode = newNode->next;
				newNode->info = currentO->info;

				if (currentO == other.rear)
					rear = newNode;

				currentO = currentO->next;
			}
		}
	}
}

template <class x>
void queueLL<x>::operator=(const queueLL& other)
{
	if (this != &other)
	{
		if (other.front != NULL)
		{
			node<x> *currentO = other.front;
			node<x> *newNode = new node<x>;
			front = rear = newNode;
			newNode->next = NULL;
			newNode->info = currentO->info;
			currentO = currentO->next;

			while (currentO != NULL)
			{
				newNode->next = new node<x>;
				newNode->next = NULL;
				newNode = newNode->next;
				newNode->info = currentO->info;

				if (currentO == other.rear)
					rear = newNode;

				currentO = currentO->next;
			}
		}
	}
}

template <class x>
void queueLL<x>::enqueue(x item)
{
	if (!isFull())
	{
		node<x> *newNode = new node<x>;
		newNode->info = item;
		newNode->next = NULL;

		if (rear != NULL)
			rear->next = newNode;
		else
			front = newNode;

		rear = newNode;
	}
}

template <class x>
void queueLL<x>::dequeue()
{
	if (!isEmpty())
	{
		node<x> *temp = front;
		front = front->next;
		delete temp;

		if (front == NULL)
			rear = NULL;
	}
}

template <class x>
bool queueLL<x>::isFull()
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
bool queueLL<x>::isEmpty()
{
	return(front == NULL);
}

template <class x>
void queueLL<x>::print()
{
	if (!isEmpty())
	{
		node<x>* current = front;
		
		while(current != NULL)
		{
			cout << current->info << ' ';
			current = current->next;
		}
	}
}

template <class x>
void queueLL<x>::reverse()
{
	if (p != NULL)
		reverse(p->next);

	reverse
}

template <class x>
x queueLL<x>::getFront()
{
	assert(!isEmpty());
		return front->info;
}

template <class x>
x queueLL<x>::getRear()
{
		return rear->info;
}