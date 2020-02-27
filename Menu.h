#include "Notation.h"

class Menu
{
public:
	Menu();
	void show();
private:
	void clscreen();
	void setpause();
	bool validate(int);
	void setroute(int);
	void getoperation();
};