#include "Element.h"

class Stack
{
public:
	Stack();
	void push(double);
	double pop();
	void clear();
	int _count;
private:
	Element* _first;
};