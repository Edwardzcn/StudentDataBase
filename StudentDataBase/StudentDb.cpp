#include "StudentDb.h"
#include <iostream>
using namespace std;
//
//void addStudent();//增加学生记录
//void deleteStudent();//删除学生记录
//void sortStudent();//对学生排序
//void allStudent();//打印全部学生的信息
//void checkStudent(int);
//void checkStudent(string);
//void checkStudent();
//void updateStudent();//更新学生信息
//void error();

StudentDb::StudentDb() //构造函数
{
	cout << "Successfully create studentdb" << endl;
	head1 = NULL;
	head2 = NULL;
	volumnSc = 0;
	volumnTi = 0;
}

StudentDb::~StudentDb() //析构函数
{
	cout << "Successfully delete studentdb" << endl;
}

void StudentDb::addStudent() //增加学生记录
{
	int tempid;
	string tempname;
	char tempsex;
	string tempmajor;
	cout << "Please input id, name, sex(M/F) and major(SC/TI)" << endl;
	cin >> tempid >> tempname >> tempsex >> tempmajor;
	if (tempmajor == "SC")
	{
		//待补充，如果id和姓名已经存在，则error
		StudentSc* pnew = new StudentSc(tempid, tempname, tempsex, tempmajor); //调用无参数的构造函数
		pnew->next = head1;
		head1 = pnew;
		//pnew->set(tempid,tempname,tempsex,tempmajor);
		volumnSc++;
	}
	else if(tempmajor=="TI")
	{
		StudentTi* pnew = new StudentTi(tempid,tempname,tempsex,tempmajor); //调用无参数的构造函数
		pnew->next = head2;
		head2 = pnew;
		//pnew->set(tempid, tempname, tempsex, tempmajor);
		volumnTi++;
	}
	else
	{
		cout << "Error: Not match the major" << endl;
	}
}

void StudentDb::deleteStudent()//删除学生记录
{
	string row;
	int num;
	cin >> row;
	if (row[0] >= '0'&&row[0] <= '9')//输入的是数字
	{
		num = stoi(row);
		//开始遍历两个链表
		bool flag = 0;
		StudentSc* pnsc = head1, *plsc = head1;
		while (pnsc != NULL && pnsc->id != num) plsc = pnsc, pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			if (pnsc == head1) //如果在首部
			{
				head1 = pnsc->next;
				delete pnsc;
				pnsc = NULL;
			}
			else //不在首部
			{
				plsc->next = pnsc->next;
				delete pnsc;
				pnsc = NULL;
			}
		}
		if (!flag) return;
		StudentTi* pnti = head2, *plti = head2;
		while (pnti != NULL && pnti->id != num) plti = pnti, pnti = pnti->next;
		if (pnti == NULL)
		{
			cout << "Error : Not Found" << endl;
			return;
		}
		else
		{
			if (pnti == head2)//在首部
			{
				head2 = pnti->next;
				delete pnti;
				pnti = NULL;
			}
			else
			{
				plti->next = pnti->next;
				delete pnti;
				pnti = NULL;
			}
		}
	}
	else //如果输入的是姓名
	{
		//开始遍历两个链表
		bool flag = 0;
		StudentSc* pnsc = head1, *plsc = head1;
		while (pnsc->name != row && pnsc != NULL) plsc = pnsc, pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			if (pnsc == head1) //如果在首部
			{
				head1 = pnsc->next;
				delete pnsc;
				pnsc = NULL;
			}
			else //不在首部
			{
				plsc->next = pnsc->next;
				delete pnsc;
				pnsc = NULL;
			}
		}
		if (!flag) return;
		StudentTi* pnti = head2, *plti = head2;
		while (pnti->name != row && plti != NULL) plti = pnti, pnti = pnti->next;
		if (pnti == NULL)
		{
			cout << "Error : Not Found" << endl;
			return;
		}
		else
		{
			if (pnti == head2)//在首部
			{
				head2 = pnti->next;
				delete pnti;
				pnti = NULL;
			}
			else
			{
				plti->next = pnti->next;
				delete pnti;
				pnti = NULL;
			}
		}
	}

}

void StudentDb::sortStudent()//对学生排序
{
	;
}

void StudentDb::allStudent()//打印全部学生的信息
{
	//遍历链表，先打印计科，再打印
}

void StudentDb::checkStudent()//查看单独学生信息
{
	string row;
	int num;
	cin >> row;
	if (row[0] >= '0'&&row[0] <= '9')//输入的是数字
	{
		num = stoi(row);
		//开始遍历两个链表
		bool flag = 0;
		StudentSc* pnsc = head1;
		while (pnsc != NULL && pnsc->id != num) pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			//找到位置
			pnsc->check();
		}
		if (!flag) return;
		StudentTi* pnti = head2, *plti = head2;
		while (pnti != NULL && pnti->id != num) pnti = pnti->next;
		if (pnti == NULL)
		{
			cout << "Error : Not Found" << endl;
			return;
		}
		else
		{
			pnti->check();
		}
	}
	else //如果输入的是姓名
	{
		//开始遍历两个链表
		bool flag = 0;
		StudentSc* pnsc = head1;
		while (pnsc != NULL && pnsc->name != row) pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			pnsc->check();
		}
		if (!flag) return;
		StudentTi* pnti = head2;
		while (pnti != NULL && pnti->name != row) pnti = pnti->next;
		if (pnti == NULL)
		{
			cout << "Error : Not Found" << endl;
			return;
		}
		else
		{
			pnti->check();
		}
	}
}

void StudentDb::updateStudent()//更新学生信息
{
	string row;
	int num;
	cin >> row;
	if (row[0] >= '0'&&row[0] <= '9')//输入的是数字
	{
		num = stoi(row);
		//开始遍历两个链表
		bool flag = 0;
		StudentSc* pnsc = head1;
		while (pnsc != NULL && pnsc->id != num) pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			//找到位置
			pnsc->set();
		}
		if (!flag) return;
		StudentTi* pnti = head2, *plti = head2;
		while (pnti != NULL && pnti->id != num) pnti = pnti->next;
		if (pnti == NULL)
		{
			cout << "Error : Not Found" << endl;
			return;
		}
		else
		{
			pnti->set();
		}
	}
	else //如果输入的是姓名
	{
		//开始遍历两个链表
		bool flag = 0;
		StudentSc* pnsc = head1;
		while (pnsc != NULL && pnsc->name != row) pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			pnsc->set();
		}
		if (!flag) return;
		StudentTi* pnti = head2;
		while (pnti != NULL && pnti->name != row) pnti = pnti->next;
		if (pnti == NULL)
		{
			cout << "Error : Not Found" << endl;
			return;
		}
		else
		{
			pnti->set();
		}
	}
}

void StudentDb::error()
{
	cout << "Error: nonsensical instructions. Try again" << endl;
}