#include "Student.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


StudentSc::StudentSc(){}

StudentSc::StudentSc(int tempid, string tempname, char tempsex, string tempmajor)
{
	id = tempid;
	name = tempname;
	sex = tempsex;
	major = tempmajor;
	for (int i = 0; i < 6; i++)
		score[i] = 0;
	cout << "Successfully add: id--" << id << " name--" << name << " sex--" << sex << " major--" << major << endl;
	
}

StudentSc::~StudentSc()
{
	cout << "Successfully delete: id--" << id << " name--" << name << endl;
}

void StudentSc::check()
{
	string course[6] = { "Math","English","C++","PE","Database","Digital" };
	cout << "Check: id--" << id << "   name--" << name << "   sex--" << sex << "   major--" << major << endl;
	cout << "       score--";
	for (int i = 0; i < 6; i++)
	{
		cout << "   " << i << "." << course[i] << "--" << score[i];
	}
	cout << endl;
	if (ave == 0) cout << "Haven't get ave" << endl;
	else cout << "       ave--" << ave << "   best" << best << "   " << worst;
	return;
}

void StudentSc::set()
{
	cout << "Please reset 6 scores int a line" << endl;
	for (int i = 0; i < 6; i++)
		cin >> score[i];
	check();
	cout << "Successfully reset" << endl;

}

StudentTi::StudentTi() {}

StudentTi::StudentTi(int tempid,string tempname,char tempsex,string tempmajor)
{
	id = tempid;
	name = tempname;
	sex = tempsex;
	major = tempmajor;
	for (int i = 0; i < 5; i++)
		score[i] = 0;
	cout << "Successfully add: id--" << id << " name--" << name << " sex--" << sex << " major--" << major << endl;
}

StudentTi::~StudentTi()
{
	cout << "Successfully delete: id--" << id << " name--" << name << endl;
}

void StudentTi::check()
{
	string course[5] = { "Math","English","C++","PE","Analog" };
	cout << "Check: id--" << id << "   name--" << name << "   sex--" << sex << "   major--" << major << endl;
	cout << "       score--";
	for (int i = 0; i < 5; i++)
	{
		cout << "   " << i << "." << course[i] << "--" << score[i];
	}
	cout << endl;
	if (ave == 0) cout << "Haven't get ave" << endl;
	else cout << "       ave--" << ave << "   best" << best << "   " << worst;
	return;
}

void StudentTi::set()
{
	cout << "Please reset 5 scores int a line" << endl;
	for (int i = 0; i < 5; i++)
		cin >> score[i];
	check();
	cout << "Successfully reset" << endl;
}

