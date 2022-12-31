#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderfile.h"
#include<fstream>
#include<cstdlib>

//学生类
class Student:public Identity
{
public:
	//默认构造函数
	Student();

	//有参构造（学号，姓名，密码, 身高 ,体重,视力，转氨酶）
	Student(int id, string name, string pwd, int h, int w, int s, int z);

	//菜单界面
	virtual void operMenu();

	//查看最新次体检信息
	void newreport();

	//查看历史上全部的体检信息
	void allreport();

	//查看每次体检的比较
	void compare();

	//查看建议健康调理方案
	void advise();

	//公告
	void announcement();
};