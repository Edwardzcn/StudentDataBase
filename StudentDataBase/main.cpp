#include "Student.h"
#include "StudentDb.h"
#include "public.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	StudentDb db;
	menue();
	cout.precision(4);
	char mychoice = 0;
	while (cin >> mychoice && mychoice != 'Q'&&mychoice != 'q')
	{
		switch (mychoice)
		{
		case 'A':
		case 'a':
			db.addStudent();
			break;
		case 'D':
		case 'd':
			db.deleteStudent();
			break;
		case 'C':
		case 'c':
			db.checkStudent();
			break;
		case 'U':
		case 'u':
			db.updateStudent();
			break;
		case 'S':
		case 's':
			db.sortStudent();
			break;
		case 'Z':
		case 'z':
			db.allStudent();
			break;
		default:
			db.error();
			break;
		}
	}
	return 0;
}