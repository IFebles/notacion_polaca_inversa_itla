

class Element
{
public:
	Element(double);
private:
	double _val;
	Element* _next;

	friend class Stack;
};