#pragma once

#include"identity.h"
#include"orderfile.h"
class Student:public Identity
{
public:
	Student();
	Student(int id,string name,string pwd);//学号、姓名、密码
	~Student();

	virtual void open_menu();
	void apply_order();//申请预约
	void show_order();//查看自身预约
	void show_all_order();//查看所有预约
	void cancel_order();

	int m_id;

	vector<Computer_Room>vcom;
	string m_name;
	string m_psw;
private:

};

