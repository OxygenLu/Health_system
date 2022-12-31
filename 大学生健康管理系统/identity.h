#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;

class Identity
{
public:
	//操作菜单
	virtual void operMenu() = 0;
	//id
	int m_Id;//留意这里，可修改
	//用户名
	string m_Name;
	//密码
	string m_Pwd;
	//身高
	int m_h;
	//体重
	int m_w;
	//视力；
	int m_s;
	//转氨酶
	int m_z;
};

