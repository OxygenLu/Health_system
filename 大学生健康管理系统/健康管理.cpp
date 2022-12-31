#include<iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"manage.h"

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//查看最新次体检信息
		{
			stu->newreport();
		}
		else if (select == 2)//查看历史上全部的体检信息
		{
			stu->allreport();
		}
		else if (select == 3)//多次结果对比
		{
			stu->compare();
		}
		else if (select == 4)//本次体检的建议
		{
			stu->advise();
		}
		else if (select == 5)//分享
		{
			stu->announcement();
		}
		else 
		{
			//注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单		
		manager->operMenu();

		//将父类的指针转为子类的指针，可以调用子类的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户的选择

		cin >> select;
	
		if (select == 1)//添加账号
		{
			man->addperson();
		}
		else if (select == 2)//查看所有账号
		{
			man->show_Pwd(); 
		}
		else if (select == 3)//清空学生体检信息
		{
			man->cleanFile();
		}
		else if (select == 4)//添加体检信息
		{
			man->addReport();
		}
		else if (select == 5)//发布公告
		{
			man->addannoun();
		}
		else
		{
			delete manager;//销毁管理员这个堆区 的对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");

			return;
		}
		
	}
}
//登录功能
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;
	int h = 0;
	int w = 0;
	int s = 0;
	int z = 0;
	//判断身份
	if (type == 1)//student
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}

	
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	
	//判断结果反馈
	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的id
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//一行一行的读取代码
		{
			//与用户输入信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd, h, w, s, z);
				//进入学生类的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//验证输入是否正确
			if (fName == name && fPwd == pwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				//进入管理员子目录
				managerMenu(person);

				return;
			}
		}
	}

	cout << "验证失败" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	//使用 system() 调用 dos 命令添加一个总的学生文件夹
	/*string folderPath = "C:\\Users\\HP\\Desktop\\c++\\大学生健康管理系统\\大学生健康管理系统";

	string command;
	command = "mkdir Student_all " + folderPath;
	system(command.c_str());*/

	

	//创建100个txt文件
	/*
	ofstream File;
	string bb = "";

	for (int i = 0; i < 100; i++)
	{

		bb = to_string(static_cast<long long>(i));
		File.open("C:\\Users\\HP\\Desktop\\c++\\大学生健康管理系统\\大学生健康管理系统\\Student_all\\file_" + bb + ".txt");
		File.close();
	}*/
	

	int select = 0;//接受用户选择
	while (true)
	{
		cout << "=============================  GUET学生健康管理系统  ========================" << endl;
		cout << endl << "\t\t                      登录" << endl;
		cout << "\t\t====================================================" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t|                   1.学生窗口                     |" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t|                   2.管理员                       |" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t|                   0.退出                         |" << endl;
		cout << "\t\t|                                                  |" << endl;
		cout << "\t\t====================================================" << endl;
		cout << "请输入你的选择：" << endl;

		cin >> select;//接收用户选择

		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://管理员
			LoginIn(ADMIN_FILE, 2);
			break;
		case 0://退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！！！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}