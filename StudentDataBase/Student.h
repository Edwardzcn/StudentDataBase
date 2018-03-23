#pragma once
#include<string>
using namespace std;

class StudentSc
{
public:
	StudentSc();
	StudentSc(int, string, char, string);
	~StudentSc();
	void set();
	void check();
	int id;
	string name;
	string major;
	StudentSc* next;

private:
	//int id;
	//string name;
	char sex;
	//string major;
	double score[6];
	double ave;
	double best;
	double worst;
};

class StudentTi
{
public:
	StudentTi();
	StudentTi(int, string, char, string);
	~StudentTi();
	void set();
	void check();
	int id;
	string name;
	string major;
	StudentTi* next;

private:
	//int id;
	//string name;
	char sex;
	//string major;
	double score[6];
	double ave;
	double best;
	double worst;
};
