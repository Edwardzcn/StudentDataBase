#include "StudentDb.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;
//
//void addStudent();//����ѧ����¼
//void deleteStudent();//ɾ��ѧ����¼
//void sortStudent();//��ѧ������
//void allStudent();//��ӡȫ��ѧ������Ϣ
//void checkStudent(int);
//void checkStudent(string);
//void checkStudent();
//void updateStudent();//����ѧ����Ϣ
//void error();

StudentDb::StudentDb() //���캯��
{
	//cout << "---------------------" << endl;
	cout << "Successfully create studentdb" << endl;
	head1 = NULL;
	head2 = NULL;
	volumnSc = 0;
	volumnTi = 0;
}

StudentDb::~StudentDb() //��������
{
	cout << "Successfully delete studentdb" << endl;
}

void StudentDb::addStudent() //����ѧ����¼
{
	int tempid;
	string tempname;
	char tempsex;
	string tempmajor;
	cout << "Please input id, name, sex(M/F) and major(SC/TI)" << endl;
	cin >> tempid >> tempname >> tempsex >> tempmajor;
	if (tempmajor == "SC")
	{
		//�����䣬���id�������Ѿ����ڣ���error
		StudentSc* pnew = new StudentSc(tempid, tempname, tempsex, tempmajor); //�����޲����Ĺ��캯��
		pnew->next = head1;
		head1 = pnew;
		//pnew->set(tempid,tempname,tempsex,tempmajor);
		volumnSc++;
	}
	else if(tempmajor=="TI")
	{
		StudentTi* pnew = new StudentTi(tempid,tempname,tempsex,tempmajor); //�����޲����Ĺ��캯��
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

void StudentDb::deleteStudent()//ɾ��ѧ����¼
{
	cout << "Please input id/name to delete a student" << endl;
	string row;
	int num;
	cin >> row;
	if (row[0] >= '0'&&row[0] <= '9')//�����������
	{
		num = stoi(row);
		//��ʼ������������
		bool flag = 0;
		StudentSc* pnsc = head1, *plsc = head1;
		while (pnsc != NULL && pnsc->id != num) plsc = pnsc, pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			if (pnsc == head1) //������ײ�
			{
				head1 = pnsc->next;
				delete pnsc;
				pnsc = NULL;
			}
			else //�����ײ�
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
			if (pnti == head2)//���ײ�
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
	else //��������������
	{
		//��ʼ������������
		bool flag = 0;
		StudentSc* pnsc = head1, *plsc = head1;
		while (pnsc->name != row && pnsc != NULL) plsc = pnsc, pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			if (pnsc == head1) //������ײ�
			{
				head1 = pnsc->next;
				delete pnsc;
				pnsc = NULL;
			}
			else //�����ײ�
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
			if (pnti == head2)//���ײ�
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

void StudentDb::sortStudent()//��ѧ������
{
	//�Ȳ���ð�ݷ�����
	StudentSc* psc = NULL;
	StudentSc* qsc = NULL;
	StudentTi* pti = NULL;
	StudentTi* qti = NULL;
	double temp;
	for (psc = head1; psc != NULL; psc = psc->next)
	{
		for (qsc = psc->next; qsc != NULL; qsc = qsc->next)
		{
			if (psc->ave < qsc->ave)
			{
				temp = psc->ave;
				psc->ave = qsc->ave;
				qsc->ave = temp;
			}

		}
	}
	for (pti = head2; pti != NULL; pti = pti->next)
	{
		for (qti = pti->next; qti != NULL; qti = qti->next)
		{
			if (pti->ave < qti->ave)
			{
				temp = pti->ave;
				pti->ave = qti->ave;
				qti->ave = temp;
			}

		}
	}

	cout << "Successfully sort. Now show all students' rank" << endl;
	cout << "-----------------------------------------------------" << endl;
	int count;
	for (count = 1, psc = head1,pti=head2; psc != NULL&&pti!=NULL;count++)
	{
		//�����޷����ͬһ���Σ�������
		if (psc->ave > pti->ave)
		{
			cout << "   rank " << std::left << setfill(' ') << setw(3) << count << setfill('0') << std::right << setw(10) << psc->id << "   name--" << psc->name << "   sex--" << psc->sex << "   major--" << psc->major << "   averangeScore--" << psc->ave << endl;
			psc = psc->next;
		}
		else 
		{
			cout << "   rank " << std::left << setfill(' ') << setw(3) << count << setfill('0') << std::right << setw(10) << pti->id << "   name--" << pti->name << "   sex--" << pti->sex << "   major--" << pti->major << "   averangeScore--" << pti->ave << endl;
			pti = pti->next;
		}
	}
	if (psc == NULL)
	{
		for (; pti != NULL; pti = pti->next, count++)
		{
			cout << "   rank " << std::left << setfill(' ') << setw(3) << count << setfill('0') << std::right << setw(10) << pti->id << "   name--" << pti->name << "   sex--" << pti->sex << "   major--" << pti->major << "   averangeScore--" << pti->ave << endl;
		}
	}
	else if (pti == NULL)
	{
		for (; psc != NULL; psc = psc->next, count++)
		{
			cout << "   rank " << std::left << setfill(' ') << setw(3) << count << setfill('0') << std::right << setw(10) << psc->id << "   name--" << psc->name << "   sex--" << psc->sex << "   major--" << psc->major << "   averangeScore--" << psc->ave << endl;
		}
	}
	cout << "-----------------------------------------------------" << endl;
}

void StudentDb::allStudent()//��ӡȫ��ѧ������Ϣ
{
	//���������ȴ�ӡ�ƿƣ��ٴ�ӡ
	cout << "---------------------" << endl;
	cout << "Students major in CS:" << endl;
	StudentSc* p1 = head1;
	while (p1 != NULL)
	{
		p1->check();
		p1 = p1->next;
	}

	cout << endl << "Students major in TI:" << endl;
	StudentTi *p2 = head2;
	while (p2 != NULL)
	{
		p2->check();
		p2 = p2->next;
	}
	cout << "---------------------" << endl;
}

void StudentDb::checkStudent()//�鿴����ѧ����Ϣ
{
	cout << "Please input id/name to check a student's information" << endl;
	string row;
	int num;
	cin >> row;
	if (row[0] >= '0'&&row[0] <= '9')//�����������
	{
		num = stoi(row);
		//��ʼ������������
		bool flag = 0;
		StudentSc* pnsc = head1;
		while (pnsc != NULL && pnsc->id != num) pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			//�ҵ�λ��
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
	else //��������������
	{
		//��ʼ������������
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

void StudentDb::updateStudent()//����ѧ����Ϣ
{
	cout << "Please input id/name to update a student's information" << endl;
	string row;
	int num;
	cin >> row;
	if (row[0] >= '0'&&row[0] <= '9')//�����������
	{
		num = stoi(row);
		//��ʼ������������
		bool flag = 0;
		StudentSc* pnsc = head1;
		while (pnsc != NULL && pnsc->id != num) pnsc = pnsc->next;
		if (pnsc == NULL)
			flag = 1;
		else
		{
			//�ҵ�λ��
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
	else //��������������
	{
		//��ʼ������������
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