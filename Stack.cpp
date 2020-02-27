#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() : _first(NULL), _count(0)
{ }

void Stack::push(double num)
{
	Element* elem = new Element(num);

	if(_first == NULL)
		_first = elem;
	else
	{
		elem->_next = _first;
		_first = elem;
	}

	_count++;
}

double Stack::pop()
{
	if(_first == NULL)
		return 0;

	double temp = _first->_val;
	Element* elem = _first;

	_first = _first->_next;
	delete elem;

	_count--;

	return temp;
}

void Stack::clear()
{
	if(_first == NULL)
		return;

	Element* elem = _first;

	for(int x = 0; x < _count; x++)
	{
		Element* temp = elem;
		elem = elem->_next;
		delete temp;
	}
	/*int x = 0;
	while(elem != NULL)
	{
		cout << "Cantidad de iteraciones: " << ++x << endl;
		cout << "Cantidad en la pila: " << _count << endl;
		cout << "elem == NULL: " << (elem == NULL) << endl;
		Element* temp = elem;
		elem = elem->_next;
		delete temp;
		cout << "Eliminado en iteracion " << x << endl;
	}*/

	_count = 0;
}