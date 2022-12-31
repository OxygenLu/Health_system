#include<iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"manage.h"

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//�鿴���´������Ϣ
		{
			stu->newreport();
		}
		else if (select == 2)//�鿴��ʷ��ȫ���������Ϣ
		{
			stu->allreport();
		}
		else if (select == 3)//��ν���Ա�
		{
			stu->compare();
		}
		else if (select == 4)//�������Ľ���
		{
			stu->advise();
		}
		else if (select == 5)//����
		{
			stu->announcement();
		}
		else 
		{
			//ע����¼
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�		
		manager->operMenu();

		//�������ָ��תΪ�����ָ�룬���Ե�������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��

		cin >> select;
	
		if (select == 1)//����˺�
		{
			man->addperson();
		}
		else if (select == 2)//�鿴�����˺�
		{
			man->show_Pwd(); 
		}
		else if (select == 3)//���ѧ�������Ϣ
		{
			man->cleanFile();
		}
		else if (select == 4)//��������Ϣ
		{
			man->addReport();
		}
		else if (select == 5)//��������
		{
			man->addannoun();
		}
		else
		{
			delete manager;//���ٹ���Ա������� �Ķ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");

			return;
		}
		
	}
}
//��¼����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;
	int h = 0;
	int w = 0;
	int s = 0;
	int z = 0;
	//�ж����
	if (type == 1)//student
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}

	
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	
	//�жϽ������
	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��id
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//һ��һ�еĶ�ȡ����
		{
			//���û�������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd, h, w, s, z);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//��֤�����Ƿ���ȷ
			if (fName == name && fPwd == pwd)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				//�������Ա��Ŀ¼
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��֤ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	//ʹ�� system() ���� dos �������һ���ܵ�ѧ���ļ���
	/*string folderPath = "C:\\Users\\HP\\Desktop\\c++\\��ѧ����������ϵͳ\\��ѧ����������ϵͳ";

	string command;
	command = "mkdir Student_all " + folderPath;
	system(command.c_str());*/

	

	//����100��txt�ļ�
	/*
	ofstream File;
	string bb = "";

	for (int i = 0; i < 100; i++)
	{

		bb = to_string(static_cast<long long>(i));
		File.open("C:\\Users\\HP\\Desktop\\c++\\��ѧ����������ϵͳ\\��ѧ����������ϵͳ\\Student_all\\file_" + bb + ".txt");
		File.close();
	}*/
	

	int select = 0;//�����û�ѡ��
	while (true)
	{
		cout << "=============================  GUETѧ����������ϵͳ  ========================" << endl;
		cout << endl << "\t\t                      ��¼" << endl;
		cout << "\t\t====================================================" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t|                   1.ѧ������                     |" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t|                   2.����Ա                       |" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t|                   0.�˳�                         |" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t====================================================" << endl;
		cout << "���������ѡ��" << endl;

		cin >> select;//�����û�ѡ��

		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://����Ա
			LoginIn(ADMIN_FILE, 2);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ�񣡣���" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}