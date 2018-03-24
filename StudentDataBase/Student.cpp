#include "Student.h"
#include <iostream>
#include <iomanip>
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
	cout << "Successfully add: id--" << setfill('0') << setw(10) << id << " name--" << name << " sex--" << sex << " major--" << major << endl;
	
}

StudentSc::~StudentSc()
{
	cout << "Successfully delete: id--" << std::right << setfill('0') << setw(10) << id << " name--" << name << endl;
}

void StudentSc::check()
{
	string course[6] = { "Math","English","C++","PE","Database","Digital" };
	cout << "       id--" << setfill('0') << setw(10) << id << "   name--" << std::left << setw(7) << name << "   sex--" << sex << "   major--" << major << endl;
	cout << "       score--";
	for (int i = 0; i < 6; i++)
	{
		cout << "   " << i+1 << "." << course[i] << "--" << score[i];
	}
	cout << endl;
	if (ave == 0) cout << "       Haven't get ave" << endl;
	else cout << "       ave--" << ave << "   best--" << best << "   worst--" << worst << endl;
	return;
}

void StudentSc::set()
{
	cout << "Please reset 6 scores int a line" << endl;
	double sum = 0;
	double max = -1;
	double min = 999;
	for (int i = 0; i < 6; i++)
	{
		cin >> score[i];
		if (score[i] > max) max = score[i];
		else if (score[i] < min) min = score[i];
		sum += score[i];
	}
	ave = sum / 6;
	best = max;
	worst = min;
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
	cout << "Successfully add: id--" << setfill('0') << setw(10) << id << " name--" << name << " sex--" << sex << " major--" << major << endl;
}

StudentTi::~StudentTi()
{
	cout << "Successfully delete: id--" << std::right << setfill('0') << setw(10) << id << " name--" << name << endl;
}

void StudentTi::check()
{
	string course[5] = { "Math","English","C++","PE","Analog" };
	cout << "       id--" << setfill('0') << setw(10) << id << "   name--" << std::left << setw(7) << name << "   sex--" << sex << "   major--" << major << endl;
	cout << "       score--";
	for (int i = 0; i < 5; i++)
	{
		cout << "   " << i+1 << "." << course[i] << "--" << score[i];
	}
	cout << endl;
	if (ave == 0) cout << "       Haven't get ave" << endl;
	else cout << "       ave--" << ave << "   best--" << best << "   worst--" << worst << endl;
	return;
}

void StudentTi::set()
{
	cout << "Please reset 5 scores int a line" << endl;
	double sum = 0;
	double max = -1;
	double min = 999;
	for (int i = 0; i < 5; i++)
	{
		cin >> score[i];
		if (score[i] > max) max = score[i];
		else if (score[i] < min) min = score[i];
		sum += score[i];
	}
	ave = sum / 5;
	best = max;
	worst = min;
	check();
	cout << "Successfully reset" << endl;
}

