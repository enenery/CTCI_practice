/**
	Course Name: CSC 330 BMCC (Data Structure I)
	Professor Name: Dr. Anna Salvati
	Assignment Name: Programming Project
	FileName: DoublyLinkedList1.h
	Purpose: TBA
	
	@author Erii Sugimoto & Laurent Sanou
	@version 1.0 05/12/2016
*/
#include <iostream>
using namespace std;

#ifndef DoublyLinkedList1_h
#define DoublyLinkedList1_h

template <class Type>
	struct nodeType
	{
		Type info;
		nodeType <Type> *next;
		nodeType <Type> *back;
	};

	template <class Type>
	class DoublyLinkedList
	{
		friend ostream& operator << (ostream& out, const DoublyLinkedList<Type> & other);
		friend istream& operator >> (istream& in, DoublyLinkedList<Type> &other);

	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList<Type>& other);
	    DoublyLinkedList operator= (const DoublyLinkedList<Type> & other);
		void initializeList();
		bool isEmpty() ;
		int getLength();
		void setLength(int n);
		void insertItemFront(const Type&insertItem);
		void insertItemBack(const Type& insertItem);
		bool isNextNull();
		//void deleteItem(Type item);
		//Type iteratorFrontToBack(int n);
		//Type iteratorBackToFront(int n);
		void setIteratorFirst();
		void setIteratorLast();
		void setIteratorNext();
		void setIteratorBack();
		bool didIteratorFinish();
		Type getIteratorInfo();
		void printForward();
		void printForwardCallRec();
		void printForwardRec(nodeType<Type> *p);
		void printBackward();
		void printBackwardCallRec();
		void printBackwardRec(nodeType<Type> *p);
		void deleteLast();
		void deleteFirst();
		int getNumOfItem(Type item);
		void replace_item(Type olditem, Type newitem);
		void call_replace_itemR(Type olditem, Type newitem);
		void replace_itemR(Type olditem, Type newitem, nodeType<Type> *&current);

		
	protected:
		int length, max;
		nodeType <Type> *first; // pointer to the first node
		nodeType <Type> *last; // pointer to the last node
		nodeType <Type> *iterator;
		
	}; 

#endif 