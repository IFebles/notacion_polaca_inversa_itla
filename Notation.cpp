#include <iostream>
#include <cstdlib>
#include "Notation.h"

using namespace std;

Stack mystack;

Notation::Notation() { }

bool Notation::process(string str)
{
	int len = str.length();
	string buffer = "";

	for(int x = 0; x < len; x++)
	{
		switch(str[x])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
				buffer += str[x];
			break;

			case '+':
			case '-':
			case '*':
			case '/':
				if(buffer != "")
				{
					mystack.push(atof(buffer.c_str()));
					buffer = "";
				}
				if(mystack._count < 2)
				{
					mystack.clear();
					//cout << "ERR1" << endl;
					return false;
				}
				double val1, val2;
				val2 = mystack.pop();
				val1 = mystack.pop();
				switch(str[x])
				{
					case '+':
						mystack.push(val1 + val2);
					break;
					case '-':
						mystack.push(val1 - val2);
					break;
					case '*':
						mystack.push(val1 * val2);
					break;
					case '/':
						mystack.push(val1 / val2);
					break;
				}
			break;

			case ' ':
				mystack.push(atof(buffer.c_str()));
				buffer = "";
			break;

			default:
				cout << endl << "* Unknown characters! *" << endl;
				cout << "Only \"0 1 2 3 4 5 6 7 8 9 . + - * /\" allowed\n\n";
				//cout << "Cantidad: " << mystack._count << endl;
				mystack.clear();
				//cout << "ERR2" << endl;
				return false;
			break;
		}
	}

	if(mystack._count != 1 || buffer != "")
	{
		mystack.clear();
		//cout << "ERR3" << endl;
		return false;
	}

	cout << "The result is " << mystack.pop();

	return true;;
}