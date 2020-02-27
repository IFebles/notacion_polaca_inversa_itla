#include <iostream>
#include <cstdlib>
#include <climits>
#include "Menu.h"

using namespace std;


Menu::Menu() { }

void Menu::clscreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::setpause()
{
	#ifdef _WIN32
	system("pause");
	#else
	system("read -n1 -r -p \"Press any key to continue...\" myvar");
	#endif
}

void Menu::show()
{
	int resp = 0;

	while(resp != 3)
	{
		clscreen();
		cout << "* Polish Notation *\n\n";
		cout << "1- Write operation" << endl;
		cout << "2- Learn how to write an operation" << endl;
		cout << "3- Exit" << endl;

		cout << endl << ">> ";
		cin >> resp;

		if(validate(resp))
			setroute(resp);
	}
}

bool Menu::validate(int resp)
{
	if(resp >= 1 && resp <= 3)
		return true;
	else
	{
		cout << endl << "* Invalid option! *" << endl;
		setpause();
		return false;
	}
}

void Menu::setroute(int resp)
{
	switch(resp)
	{
		case 1:
			getoperation();
		break;
		case 2:
			cout << "\nYou need to write the operands separated by space "
			<< "and the operator after them.\nEx:\n";
			cout << "5 2-3+6/" << endl;
			cout << "That being equal to 1 ([5-2+3]/6)\n\n";
		break;
		case 3:
			cout << "* Goodbye! *" << endl;
		break;
	}

	setpause();
}

void Menu::getoperation()
{
	cin.ignore(INT_MAX, '\n');
	string operation = "";
	cout << "Write your operation in Polish notation:" << endl;
	
	while(operation == "")
	{
		cout << ">> ";
		getline(cin, operation);
	}

	Notation mynotation;
	if(!mynotation.process(operation))
		cout << "* Invalid format! *" << endl;

	cout << endl;
}

