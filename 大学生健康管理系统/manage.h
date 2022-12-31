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


//管理员类
class Manager :public Identity
{
public:
	//默认构造函数
	Manager();
	//含参构造函数
	Manager(string name, string pwd);
    //选择菜单
	virtual void operMenu();
	//添加账号
	void addperson();	
	//查看账号
	void show_Pwd();
	//查看学生体检报告
	void addReport();
	//发布公告
	void addannoun();
	//清空学生信息
	void cleanFile();
	//初始化容器
	void initVector();
	//检测重复 参数：（传入id，传出类型）返回值：（true：重复，false没重复）
	bool checkRepeat(int id, int type);
	//学生容器
	vector<Student>vStu;
};
