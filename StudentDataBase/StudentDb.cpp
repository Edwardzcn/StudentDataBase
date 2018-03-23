#include "StudentDb.h"
#include <iostream>
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
	;
}

void StudentDb::allStudent()//��ӡȫ��ѧ������Ϣ
{
	//���������ȴ�ӡ�ƿƣ��ٴ�ӡ
}

void StudentDb::checkStudent()//�鿴����ѧ����Ϣ
{
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