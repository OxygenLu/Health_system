#include"student.h"

#include<algorithm>


//默认构造
Student::Student()
{

}
//有参构造（学号，姓名，密码, 身高 ,体重,视力，转氨酶）
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

//菜单界面
void Student::operMenu()
{
	cout << "欢迎：" << this->m_Name << "登录！" << endl;
	cout << "\t\t=====================================\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          1、最新体检报告           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          2、历史体检报告           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          3、体检数据对比           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          4、健康建议               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          5、公告                   |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          0、注销账号               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t=====================================\n";
	cout << "请选择你的操作：" << endl;
}
//查看最新次体检信息
void Student::newreport()
{
	OrderFile of;

	int i = of.m_Size - 1;
	if (atoi(of.m_orderData[i]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "您当前无健康体检记录！" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "这是您最新体检报告：" << endl;
		cout << of.m_orderData[i]["year"] << "-";
		cout << of.m_orderData[i]["month"] << "-";
		cout << of.m_orderData[i]["day"] << " ";
		cout << "  身高:" << of.m_orderData[i]["height"] << " ";
		cout << "  体重:" << of.m_orderData[i]["weight"] << " ";
		cout << "  视力:" << of.m_orderData[i]["sight"] << " ";
		cout << "  转氨酶（ATL）:" << of.m_orderData[i]["zhuan"] << endl;
	}
	else
	{
		cout <<  "您的Id输入错误！！！" << endl;

		system("pause");
		system("cls");
		return;
	}
	

	system("pause");
	system("cls");

}

//查看历史上全部的体检信息
void Student::allreport()
{
	OrderFile of;
	int i = 0;
	if (atoi(of.m_orderData[i]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "您当前无健康体检记录！" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "您的历史体检报告：" << endl;
		for ( i = 0; i < of.m_Size; i++)
		{

			cout << of.m_orderData[i]["year"] << "-";
			cout << of.m_orderData[i]["month"] << "-";
			cout << of.m_orderData[i]["day"] << " ";
			cout << "  身高:" << of.m_orderData[i]["height"] << " ";
			cout << "  体重:" << of.m_orderData[i]["weight"] << " ";
			cout << "  视力:" << of.m_orderData[i]["sight"] << " ";
			cout << "  转氨酶（ATL）:" << of.m_orderData[i]["zhuan"] << endl;
		}
	}
	else
	{
		cout <<  "您的Id输入错误!!!" << endl;

		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");

}

//查看每次体检的比较
void Student::compare()
{
	OrderFile of;
	

	int j = of.m_Size - 1;
	if (atoi(of.m_orderData[j]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "您当前无健康体检记录！" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "与最近一次体检对比结果为：" << endl;

		cout << "=====================================================================" << endl;
		
		if (atof(of.m_orderData[j]["height"].c_str()) > atof(of.m_orderData[j + 1]["height"].c_str()))
		{
			cout << "本次身高比上一次高，";
		}
		else if (atof(of.m_orderData[j]["height"].c_str()) < atof(of.m_orderData[j + 1]["height"].c_str()))
		{
			cout << "本次身高比上一次低，";
		}
		else
		{
			cout << "本次身高与上一次相比没有变化，";
		}

		//
		if (atof(of.m_orderData[j]["weight"].c_str()) > atof(of.m_orderData[j + 1]["weight"].c_str()))
		{
			cout << "体重比上一次增重，";
		}
		else if (atof(of.m_orderData[j]["sight"].c_str()) < atof(of.m_orderData[j + 1]["sight"].c_str()))
		{
			cout << "本次体重比上一次减轻，";
		}
		else
		{
			cout << "体重与上一次相比没有变化，";
		}

		//
		if (atof(of.m_orderData[j]["zhuan"].c_str()) > atof(of.m_orderData[j + 1]["zhuan"].c_str()))
		{
			cout << "转氨酶（ATL）比上一次高。" << endl;
		}
		else if (atof(of.m_orderData[j]["zhuan"].c_str()) < atof(of.m_orderData[j + 1]["zhuan"].c_str()))
		{
			cout << "转氨酶（ATL）比上一次低。" << endl;
		}
		else
		{
			cout << "转氨酶（ATL）与上一次相比没有变化。";
		}
	}
	else
	{
		cout << " 您的Id输入错误!!!" << endl;

		system("pause");
		system("cls");
		return;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//查看建议健康调理方案
void Student::advise()
{
	OrderFile of;
	
	int i = of.m_Size - 1;

	if (atoi(of.m_orderData[i]["Id"].c_str()) == this->m_Id)
	{
		if (of.m_Size == 0)
		{
			cout << "您当前无健康体检记录！" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "这是您最新体检报告：" << endl;
		cout << of.m_orderData[i]["year"] << "-";
		cout << of.m_orderData[i]["month"] << "-";
		cout << of.m_orderData[i]["day"] << " ";
		cout << "  身高:" << of.m_orderData[i]["height"] << " ";
		cout << "  体重:" << of.m_orderData[i]["weight"] << " ";
		cout << "  视力:" << of.m_orderData[i]["sight"] << " ";
		cout << "  转氨酶（ATL）:" << of.m_orderData[i]["zhuan"] << endl;

		cout << endl;
		cout << "___________________________________注意事项___________________________________" << endl;
		if (atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str())*0.0001 * atof(of.m_orderData[i]["height"].c_str())) <= 18.5 && atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) > 0)
		{
			cout << "\t您当前的BMI值偏低，需要注意一下事项：" << endl;
			cout << "\t1.吃鸡蛋2.喝牛奶或者酸奶3.喝红糖水4.多吃面食" << endl;
			cout << "\t5.不挑食。6.多运动 7.晚上保证睡眠，不熬夜" << endl;
		}
		else if (atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) >= 32)
		{
			cout << "\t您当前的BMI值偏高，需要注意一下事项：" << endl;
			cout << "\t1.每日保证基本的营养2.多喝水，不喝饮料3.规律进食4.水果别间断" << endl;
			cout << "\t5.简单清淡饮食。6.多运动7.晚上保证睡眠，不熬夜" << endl;
		}
		else if (atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) < 32 && atof(of.m_orderData[i]["weight"].c_str()) / (atoi(of.m_orderData[i]["height"].c_str()) * 0.0001 * atof(of.m_orderData[i]["height"].c_str())) > 18.5)
		{
			cout << "\t恭喜您！您当前的BMI值正常，可以继续保持当前的生活习惯。" << endl;
		}
		cout << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		if (atof(of.m_orderData[i]["sight"].c_str()) < 4.8)
		{
			cout << "\t1.验配一副合适的眼镜 2.养成做眼保健操的习惯 3.多吃新鲜瓜果蔬菜" << endl;
			cout << "\t4.看书和办公时光线充足 5.黑灯后少看手机电脑 6.每天面对电脑屏幕超过2个小时时记得给眼睛放松一下" << endl;
		}
		else if (atof(of.m_orderData[i]["sight"].c_str()) >= 4.8)
		{
			cout << "\t您的视力目前正常，但是不要忘记每天给眼睛放松一下。" << endl;
			cout << "\t1.养成做眼保健操的习惯 2.看书和办公时光线充足 3.黑灯后少看手机电脑" << endl;
			cout << "\t4.每天面对电脑屏幕超过2个小时时记得给眼睛放松一下" << endl;
		}
		cout << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		if (atof(of.m_orderData[i]["zhuan"].c_str()) < 40)
		{
			cout << "\t您当前的ATL（转氨酶）含量正常" << endl;
			cout << "\t可以保持当前的作息饮食习惯" << endl;
		}
		else if (atof(of.m_orderData[i]["zhuan"].c_str()) >= 40)
		{
			cout << "\t您当前的ATL（转氨酶）含量偏高" << endl;
			cout << "\t建议休息一周后，复检！" << endl;
			cout << "\t注意事项：1.少喝酒，少吃辛辣油腻的食物 2.少熬夜，注意作息" << endl;
			cout << "\t          3.如果期间服用药物，建议体检前三天停止服用" << endl;
		}
		cout << "\t\t                                                      仅供参考" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "================================祝您身体健康!==================================" << endl;
	}
	else
	{
		cout << "您的Id输入错误!!!" << endl;

		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

//公告
void Student::announcement()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	char data;
	cout << "_________________公告_________________" << endl;
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
