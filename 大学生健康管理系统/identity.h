#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;

class Identity
{
public:
	//�����˵�
	virtual void operMenu() = 0;
	//id
	int m_Id;//����������޸�
	//�û���
	string m_Name;
	//����
	string m_Pwd;
	//���
	int m_h;
	//����
	int m_w;
	//������
	int m_s;
	//ת��ø
	int m_z;
};

