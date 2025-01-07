#pragma once
#include"identity.h"

class Teacher:public Identity
{
public:
	Teacher();
	Teacher(int id, string name,string pwd);
	~Teacher();
	
	virtual void open_menu();

	void show_all_order();//查看所有预约
	
	void valid_order();//审核预约

	int m_id;
	string m_name;
	string m_psw;

private:

};

