#include"orderfile.h"

OrderFile::OrderFile()
{
	cout << "请输入学号：" << endl;
	string bb = "";
	cin >> bb;
	ifstream ifs;
	ifs.open("C:\\Users\\HP\\Desktop\\c++\\大学生健康管理系统\\大学生健康管理系统\\Student_all\\file_" + bb + ".txt",ios::in );

	string year;
	string month ;
	string day ;
	string h ;
	string w ;
	string s ;
	string z ;

	this->m_Size = 0;

	while (ifs >> bb && ifs >> year && ifs >> month && ifs >> day && ifs >> h && ifs >> w && ifs >> s && ifs >> z)
	{
		/*cout << year << endl;
		cout << month << endl;
		cout << day << endl;
		cout << h << endl;
		cout << w << endl;
		cout << s << endl;
		cout << z << endl;
		cout << endl;*/

		//year:2020
		string key;
		string value;
		map<string, string>m;

		int pos = year.find(":");//4
		if (pos != -1)
		{
			key = year.substr(0, pos);
			value = year.substr(pos + 1, year.size() - pos-1);

			m.insert(make_pair(key, value));
		}

		pos = bb.find(":");//4
		if (pos != -1)
		{
			key = bb.substr(0, pos);
			value = bb.substr(pos + 1, bb.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = month.find(":");//4
		if (pos != -1)
		{
			key = month.substr(0, pos);
			value = month.substr(pos + 1, month.size() - pos-1);

			m.insert(make_pair(key, value));
		}

		pos = day.find(":");//4
		if (pos != -1)
		{
			key = day.substr(0, pos);
			value = day.substr(pos + 1, day.size() - pos-1 );

			m.insert(make_pair(key, value));
		}

		pos = h.find(":");//4

		if (pos != -1)
		{
			key = h.substr(0, pos);
			value = h.substr(pos + 1, h.size() - pos-1 );

			m.insert(make_pair(key, value));
		}

		pos = w.find(":");//4

		if (pos != -1)
		{
			key = w.substr(0, pos);
			value = w.substr(pos + 1, w.size() - pos -1);

			m.insert(make_pair(key, value));
		}

		pos = s.find(":");//4

		if (pos != -1)
		{
			key = s.substr(0, pos);
			value = s.substr(pos + 1, s.size() - pos-1 );

			m.insert(make_pair(key, value));
		}

		pos = z.find(":");//4
		if (pos != -1)
		{
			key = z.substr(0, pos);
			value = z.substr(pos + 1, z.size() - pos-1 );

			m.insert(make_pair(key, value));
		}
	
		//将小map放入到大map中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "tiao:" << it->first << "value=" << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit !=it->second.end();mit++ )
		{
			cout << " key=" << mit->first << " value=" << mit->second <<endl;
		}
	}*/
	ifs.close();
}