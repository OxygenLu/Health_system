#pragma once
#include <iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include<algorithm>


//����Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Manager();
	//���ι��캯��
	Manager(string name, string pwd);
    //ѡ��˵�
	virtual void operMenu();
	//����˺�
	void addperson();	
	//�鿴�˺�
	void show_Pwd();
	//�鿴ѧ����챨��
	void addReport();
	//��������
	void addannoun();
	//���ѧ����Ϣ
	void cleanFile();
	//��ʼ������
	void initVector();
	//����ظ� ������������id���������ͣ�����ֵ����true���ظ���falseû�ظ���
	bool checkRepeat(int id, int type);
	//ѧ������
	vector<Student>vStu;
};
