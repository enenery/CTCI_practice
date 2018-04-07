#ifndef QueuesLL_h
#define QueuesLL_h

template <class x>
struct node
{
	x info;
	node *next;
};

template <class x>
class queueLL
{
private:
	node<x> *front;
	node<x> *rear;

public:
	queueLL();
	~queueLL();
	queueLL(const queueLL& other);
	void operator = (const queueLL&);
	bool isFull();
	bool isEmpty();
	void enqueue(x item);
	void dequeue();
	void print();
	void reverse();
	x getFront();
	x getRear();
	

};
#endif // !QueuesLL

