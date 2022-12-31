#include"manage.h"

//默认构造函数
Manager::Manager()
{

}

//含参构造函数
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器 获取到所有文件中学生信息
	this->initVector();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << " 登录！" << endl;
	cout << "\t\t=================================\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1、添加账号          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2、查看所有账号      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3、清除体检信息      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4、添加体检信息      |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          5、发布公告          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0、注销账号          |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t=================================\n";
	cout << "请选择你的操作：" << endl;
}
//添加账号
void Manager::addperson()
{
	string fileName;
	string tip;
	string errorTip;//错误提示

	ofstream ofs;//文件的操作对象
	
	int select = 0;
	cout << "是否要添加学生账号？（是：1/否：0）" ;
	cin >> select;//接受用户的选择

	if(select ==1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入。";
	}
	else 
	{
		system("pause");
		system("cls");

		return;
	}	

	//利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;//姓名
	string pwd;//密码
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);

		if (ret)//重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << "  " << pwd <<" " << endl;
	cout << "添加成功!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//调用初始化容器接口，重新获取新的文件内容
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << "  姓名：" << s.m_Name << "  密码：" << s.m_Pwd << endl;
}

//查看账号
void Manager::show_Pwd()
{
	cout << "所有学生信息如下：" << endl;
	for_each(vStu.begin(), vStu.end(), printStudent); 
	
	system("pause");
	system("cls");
}

//添加学生体检报告
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

	cout << "请选择学号：" << endl;
	cin >> bb;
	cout << "----------选择体检日期-------------" << endl;
	
	cout << "请选择年份：" << endl;
	cin >> year;

	cout << "请选择月份：" << endl;
	while (true)
	{
		cin >> month;
		if (month >= 1 && month <= 12)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "请选择日期：" << endl;
	while (true)
	{
		cin >> day;
		if (day >= 1 && day <= 30)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "=========体检结果输入==============" << endl;
	cout << "输入身高（cm）："<<endl;
	cin >> h;
	cout << "输入体重（kg）：" << endl;
	cin >> w;
	cout << "输入视力：" << endl;
	cin >> s;
	cout << "输入转氨酶：" << endl;
	cin >> z;
	
	ofstream ofs;
	ofs.open("C:\\Users\\HP\\Desktop\\c++\\大学生健康管理系统\\大学生健康管理系统\\Student_all\\file_" + bb + ".txt", ios::app);
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

//清空学生信息
void Manager::cleanFile()
{
	cout << "输入您想清空的学生学号：" << endl;
	string bb = "";
	cin >> bb;
	ofstream ofs("C:\\Users\\HP\\Desktop\\c++\\大学生健康管理系统\\大学生健康管理系统\\Student_all\\file_" + bb + ".txt", ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;//可以再造一个二次的清空

	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	vStu.clear();

	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "当前学生数量：" << vStu.size() << endl;
	ifs.close();
}

//检测重复 参数：（传入id，传出类型）返回值：（true：重复，false没重复）
bool Manager::checkRepeat(int id, int type)
{
	//主页面按下1的时候，检测学生的值
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
	cout << "请输入公告：" << endl;
	cin >> anounce;

	ofs << anounce;
	ofs.close();

	system("pause");
	system("cls");

	return;
}