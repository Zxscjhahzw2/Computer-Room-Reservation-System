#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"global_file.h"
#include<algorithm>
#include<functional>
#include<vector>
#include<fstream>
#include"computerroom.h"
class Identity {

public:
	virtual void open_menu()=0;//�����˵������麯��

	string m_name;
	string m_password;
};