#pragma once
#include "Student.h"
class StudentDb
{
public:
	StudentDb();
	~StudentDb();
	void addStudent();//����ѧ����¼
	void deleteStudent();//ɾ��ѧ����¼
	void sortStudent();//��ѧ������
	void allStudent();//��ӡȫ��ѧ������Ϣ
	void checkStudent(int);
	void checkStudent(string);
	void checkStudent();
	void updateStudent();//����ѧ����Ϣ
	void error();

	StudentSc *head1;
	StudentTi *head2;
private:
	int volumnSc; //�ƿ�ͬѧ������
	int volumnTi; //���ͬѧ������

};

