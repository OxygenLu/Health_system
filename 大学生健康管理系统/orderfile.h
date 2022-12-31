#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include<fstream>
#include<map>
#include<string>

class OrderFile
{
public:

	OrderFile();

	map<int, map<string, string>>m_orderData;

	int m_Size;
};