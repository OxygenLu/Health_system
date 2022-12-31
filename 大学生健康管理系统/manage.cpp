#include"manage.h"

//Ĭ�Ϲ��캯��
Manager::Manager()
{

}

//���ι��캯��
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ��ȡ�������ļ���ѧ����Ϣ
	this->initVector();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << " ��¼��" << endl;
	cout << "\t\t=================================\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1������˺�          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2���鿴�����˺�      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3����������Ϣ      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4����������Ϣ      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          5����������          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0��ע���˺�          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t=================================\n";
	cout << "��ѡ����Ĳ�����" << endl;
}
//����˺�
void Manager::addperson()
{
	string fileName;
	string tip;
	string errorTip;//������ʾ

	ofstream ofs;//�ļ��Ĳ�������
	
	int select = 0;
	cout << "�Ƿ�Ҫ���ѧ���˺ţ����ǣ�1/��0��" ;
	cin >> select;//�����û���ѡ��

	if(select ==1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������롣";
	}
	else 
	{
		system("pause");
		system("cls");

		return;
	}	

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;//����
	string pwd;//����
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);

		if (ret)//�ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << "  " << pwd <<" " << endl;
	cout << "��ӳɹ�!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�µ��ļ�����
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "  ������" << s.m_Name << "  ���룺" << s.m_Pwd << endl;
}

//�鿴�˺�
void Manager::show_Pwd()
{
	cout << "����ѧ����Ϣ���£�" << endl;
	for_each(vStu.begin(), vStu.end(), printStudent); 
	
	system("pause");
	system("cls");
}

//���ѧ����챨��
void Manager::addReport()
{
	int year = 0;
	int month = 0;
	int day = 0;
	double h = 0;
	double w = 0;
	double s = 0;
	double z = 0;
	string bb = "";

	cout << "��ѡ��ѧ�ţ�" << endl;
	cin >> bb;
	cout << "----------ѡ���������-------------" << endl;
	
	cout << "��ѡ����ݣ�" << endl;
	cin >> year;

	cout << "��ѡ���·ݣ�" << endl;
	while (true)
	{
		cin >> month;
		if (month >= 1 && month <= 12)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "��ѡ�����ڣ�" << endl;
	while (true)
	{
		cin >> day;
		if (day >= 1 && day <= 30)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "=========���������==============" << endl;
	cout << "������ߣ�cm����"<<endl;
	cin >> h;
	cout << "�������أ�kg����" << endl;
	cin >> w;
	cout << "����������" << endl;
	cin >> s;
	cout << "����ת��ø��" << endl;
	cin >> z;
	
	ofstream ofs;
	ofs.open("C:\\Users\\HP\\Desktop\\c++\\��ѧ����������ϵͳ\\��ѧ����������ϵͳ\\Student_all\\file_" + bb + ".txt", ios::app);
	ofs << "Id:" << bb << " ";
	ofs << "year:" << year << " ";
	ofs << "month:" << month << " ";
	ofs << "day:" << day << " ";
	ofs << "height:" << h << " ";
	ofs << "weight:" << w << " ";
	ofs << "sight:" << s << " ";
	ofs << "zhuan:" << z << endl;

	ofs.close();

	system("pause");
	system("cls");	
}

//���ѧ����Ϣ
void Manager::cleanFile()
{
	cout << "����������յ�ѧ��ѧ�ţ�" << endl;
	string bb = "";
	cin >> bb;
	ofstream ofs("C:\\Users\\HP\\Desktop\\c++\\��ѧ����������ϵͳ\\��ѧ����������ϵͳ\\Student_all\\file_" + bb + ".txt", ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;//��������һ�����ε����

	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	vStu.clear();

	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "��ǰѧ��������" << vStu.size() << endl;
	ifs.close();
}

//����ظ� ������������id���������ͣ�����ֵ����true���ظ���falseû�ظ���
bool Manager::checkRepeat(int id, int type)
{
	//��ҳ�水��1��ʱ�򣬼��ѧ����ֵ
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it!= vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	return false;
}
void Manager::addannoun()
{
	string anounce;
	ofstream ofs;

	ofs.open("order.txt", ios::out | ios::app);
	cout << "�����빫�棺" << endl;
	cin >> anounce;

	ofs << anounce;
	ofs.close();

	system("pause");
	system("cls");

	return;
}