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
	char sex;
	string name;
	string major;
	StudentSc* next;
	double ave;
private:
	//int id;
	//string name;
	//string major;
	double score[6];
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
	char sex;
	string name;
	string major;
	StudentTi* next;
	double ave;
private:
	//int id;
	//string name;
	//string major;
	double score[6];
	double best;
	double worst;
};
