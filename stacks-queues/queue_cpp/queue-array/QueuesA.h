#ifndef QueuesA_h
#define QueuesA_h

template <class x>
class queueA
{
private:
	int max;
	int count;
	int front;
	int rear;
	x *q;

public:
	queueA(int = 100);
	~queueA();
	queueA(const queueA&);
	bool isFull();
	bool isEmpty();
	void enqueue(x item);
	void dequeue();
	x getFront();
	x getRear();
	int getMax();
	int getCount();
	void print();
	bool search(x item);
	queueA<x>& returnAcopy(const queueA& other);
	void reverse();
	bool operator==(const queueA& other);
	//move?? to where?
	
};
#endif // !QueuesA_h

