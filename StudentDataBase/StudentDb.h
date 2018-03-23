#pragma once
#include "Student.h"
class StudentDb
{
public:
	StudentDb();
	~StudentDb();
	void addStudent();//增加学生记录
	void deleteStudent();//删除学生记录
	void sortStudent();//对学生排序
	void allStudent();//打印全部学生的信息
	void checkStudent(int);
	void checkStudent(string);
	void checkStudent();
	void updateStudent();//更新学生信息
	void error();

	StudentSc *head1;
	StudentTi *head2;
private:
	int volumnSc; //计科同学的数量
	int volumnTi; //测控同学的数量

};

