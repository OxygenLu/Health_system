#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderfile.h"
#include<fstream>
#include<cstdlib>

//ѧ����
class Student:public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Student();

	//�вι��죨ѧ�ţ�����������, ��� ,����,������ת��ø��
	Student(int id, string name, string pwd, int h, int w, int s, int z);

	//�˵�����
	virtual void operMenu();

	//�鿴���´������Ϣ
	void newreport();

	//�鿴��ʷ��ȫ���������Ϣ
	void allreport();

	//�鿴ÿ�����ıȽ�
	void compare();

	//�鿴���齡��������
	void advise();

	//����
	void announcement();
};