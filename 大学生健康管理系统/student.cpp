#include"student.h"

#include<algorithm>


//Ĭ�Ϲ���
Student::Student()
{

}
//�вι��죨ѧ�ţ�����������, ��� ,����,������ת��ø��
Student::Student(int id, string name, string pwd, int h, int w, int s, int z)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->m_h = h;
	this->m_w = w;
	this->m_s = s;
	this->m_z = z;
}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t=====================================\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          1��������챨��           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          2����ʷ��챨��           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          3��������ݶԱ�           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          4����������               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          5������                   |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          0��ע���˺�               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t=====================================\n";
	cout << "��ѡ����Ĳ�����" << endl;
}
//�鿴���´������Ϣ
void Student::newreport()
{
	OrderFile of;

	int i = of.m_Size - 1;
	if (atoi(of.m_orderData[i]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "����ǰ�޽�������¼��" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "������������챨�棺" << endl;
		cout << of.m_orderData[i]["year"] << "-";
		cout << of.m_orderData[i]["month"] << "-";
		cout << of.m_orderData[i]["day"] << " ";
		cout << "  ���:" << of.m_orderData[i]["height"] << " ";
		cout << "  ����:" << of.m_orderData[i]["weight"] << " ";
		cout << "  ����:" << of.m_orderData[i]["sight"] << " ";
		cout << "  ת��ø��ATL��:" << of.m_orderData[i]["zhuan"] << endl;
	}
	else
	{
		cout <<  "����Id������󣡣���" << endl;

		system("pause");
		system("cls");
		return;
	}
	

	system("pause");
	system("cls");

}

//�鿴��ʷ��ȫ���������Ϣ
void Student::allreport()
{
	OrderFile of;
	int i = 0;
	if (atoi(of.m_orderData[i]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "����ǰ�޽�������¼��" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "������ʷ��챨�棺" << endl;
		for ( i = 0; i < of.m_Size; i++)
		{

			cout << of.m_orderData[i]["year"] << "-";
			cout << of.m_orderData[i]["month"] << "-";
			cout << of.m_orderData[i]["day"] << " ";
			cout << "  ���:" << of.m_orderData[i]["height"] << " ";
			cout << "  ����:" << of.m_orderData[i]["weight"] << " ";
			cout << "  ����:" << of.m_orderData[i]["sight"] << " ";
			cout << "  ת��ø��ATL��:" << of.m_orderData[i]["zhuan"] << endl;
		}
	}
	else
	{
		cout <<  "����Id�������!!!" << endl;

		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");

}

//�鿴ÿ�����ıȽ�
void Student::compare()
{
	OrderFile of;
	

	int j = of.m_Size - 1;
	if (atoi(of.m_orderData[j]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "����ǰ�޽�������¼��" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "�����һ�����ԱȽ��Ϊ��" << endl;

		cout << "=====================================================================" << endl;
		
		if (atof(of.m_orderData[j]["height"].c_str()) > atof(of.m_orderData[j + 1]["height"].c_str()))
		{
			cout << "������߱���һ�θߣ�";
		}
		else if (atof(of.m_orderData[j]["height"].c_str()) < atof(of.m_orderData[j + 1]["height"].c_str()))
		{
			cout << "������߱���һ�εͣ�";
		}
		else
		{
			cout << "�����������һ�����û�б仯��";
		}

		//
		if (atof(of.m_orderData[j]["weight"].c_str()) > atof(of.m_orderData[j + 1]["weight"].c_str()))
		{
			cout << "���ر���һ�����أ�";
		}
		else if (atof(of.m_orderData[j]["sight"].c_str()) < atof(of.m_orderData[j + 1]["sight"].c_str()))
		{
			cout << "�������ر���һ�μ��ᣬ";
		}
		else
		{
			cout << "��������һ�����û�б仯��";
		}

		//
		if (atof(of.m_orderData[j]["zhuan"].c_str()) > atof(of.m_orderData[j + 1]["zhuan"].c_str()))
		{
			cout << "ת��ø��ATL������һ�θߡ�" << endl;
		}
		else if (atof(of.m_orderData[j]["zhuan"].c_str()) < atof(of.m_orderData[j + 1]["zhuan"].c_str()))
		{
			cout << "ת��ø��ATL������һ�ε͡�" << endl;
		}
		else
		{
			cout << "ת��ø��ATL������һ�����û�б仯��";
		}
	}
	else
	{
		cout << " ����Id�������!!!" << endl;

		system("pause");
		system("cls");
		return;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//�鿴���齡��������
void Student::advise()
{
	OrderFile of;
	
	int i = of.m_Size - 1;

	if (atoi(of.m_orderData[i]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "����ǰ�޽�������¼��" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "������������챨�棺" << endl;
		cout << of.m_orderData[i]["year"] << "-";
		cout << of.m_orderData[i]["month"] << "-";
		cout << of.m_orderData[i]["day"] << " ";
		cout << "  ���:" << of.m_orderData[i]["height"] << " ";
		cout << "  ����:" << of.m_orderData[i]["weight"] << " ";
		cout << "  ����:" << of.m_orderData[i]["sight"] << " ";
		cout << "  ת��ø��ATL��:" << of.m_orderData[i]["zhuan"] << endl;

		cout << endl;
		cout << "___________________________________ע������___________________________________" << endl;
		if (atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str())*0.0001 * atof(of.m_orderData[i]["height"].c_str())) <= 18.5 && atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) > 0)
		{
			cout << "\t����ǰ��BMIֵƫ�ͣ���Ҫע��һ�����" << endl;
			cout << "\t1.�Լ���2.��ţ�̻�������3.�Ⱥ���ˮ4.�����ʳ" << endl;
			cout << "\t5.����ʳ��6.���˶� 7.���ϱ�֤˯�ߣ�����ҹ" << endl;
		}
		else if (atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) >= 32)
		{
			cout << "\t����ǰ��BMIֵƫ�ߣ���Ҫע��һ�����" << endl;
			cout << "\t1.ÿ�ձ�֤������Ӫ��2.���ˮ����������3.���ɽ�ʳ4.ˮ������" << endl;
			cout << "\t5.���嵭��ʳ��6.���˶�7.���ϱ�֤˯�ߣ�����ҹ" << endl;
		}
		else if (atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) < 32 && atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) > 18.5)
		{
			cout << "\t��ϲ��������ǰ��BMIֵ���������Լ������ֵ�ǰ������ϰ�ߡ�" << endl;
		}
		cout << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		if (atof(of.m_orderData[i]["sight"].c_str()) < 4.8)
		{
			cout << "\t1.����һ�����ʵ��۾� 2.�������۱����ٵ�ϰ�� 3.������ʹϹ��߲�" << endl;
			cout << "\t4.����Ͱ칫ʱ���߳��� 5.�ڵƺ��ٿ��ֻ����� 6.ÿ����Ե�����Ļ����2��Сʱʱ�ǵø��۾�����һ��" << endl;
		}
		else if (atof(of.m_orderData[i]["sight"].c_str()) >= 4.8)
		{
			cout << "\t��������Ŀǰ���������ǲ�Ҫ����ÿ����۾�����һ�¡�" << endl;
			cout << "\t1.�������۱����ٵ�ϰ�� 2.����Ͱ칫ʱ���߳��� 3.�ڵƺ��ٿ��ֻ�����" << endl;
			cout << "\t4.ÿ����Ե�����Ļ����2��Сʱʱ�ǵø��۾�����һ��" << endl;
		}
		cout << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		if (atof(of.m_orderData[i]["zhuan"].c_str()) < 40)
		{
			cout << "\t����ǰ��ATL��ת��ø����������" << endl;
			cout << "\t���Ա��ֵ�ǰ����Ϣ��ʳϰ��" << endl;
		}
		else if (atof(of.m_orderData[i]["zhuan"].c_str()) >= 40)
		{
			cout << "\t����ǰ��ATL��ת��ø������ƫ��" << endl;
			cout << "\t������Ϣһ�ܺ󣬸��죡" << endl;
			cout << "\tע�����1.�ٺȾƣ��ٳ����������ʳ�� 2.�ٰ�ҹ��ע����Ϣ" << endl;
			cout << "\t          3.����ڼ����ҩ��������ǰ����ֹͣ����" << endl;
		}
		cout << "\t\t                                                      �����ο�" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "================================ף�����彡��!==================================" << endl;
	}
	else
	{
		cout << "����Id�������!!!" << endl;

		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

//����
void Student::announcement()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	char data;
	cout << "_________________����_________________" << endl;
	while (!ifs.eof())
	{
		ifs >> data;
		cout << data;
	}
	cout << endl;
	ifs.close();
	
	system("pause");
	system("cls");
}
