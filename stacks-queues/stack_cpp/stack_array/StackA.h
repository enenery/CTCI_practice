#ifndef StackA_h
#define StackA_h

template <class x>
class stackA
{
private:
	x *info; //pointer to an x item
	int max;
	int top; //represents the position of the element on the top or one element after the top
public:
	stackA(int m = 100);
	~stackA();
	stackA(const stackA<x> &other);
	stackA operator = (const stackA<x>& other);
	bool isFull();
	bool isEmpty();
	void push(x item);
	void pop();
	x getTopItem();
	void print();
	bool search(x item);
	void reverse(stackA<x> &list);
};
#endif // !StackA.h

