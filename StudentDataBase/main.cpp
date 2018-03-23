#include "Student.h"
#include "StudentDb.h"
#include "public.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	StudentDb db;
	menue();
	int mychoice = 0;
	while (cin>>mychoice)
	{
		switch (mychoice)
		{
		case 1:
			db.addStudent();
			break;
		case 2:
			db.deleteStudent();
			break;
		case 3:
			db.checkStudent();
			break;
		case 4:
			db.updateStudent();
			break;
		case 5:
			db.sortStudent();
			break;
		case 6:
			db.allStudent();
			break;
		default:
			db.error();
			break;
		}
	}
	return 0;
}