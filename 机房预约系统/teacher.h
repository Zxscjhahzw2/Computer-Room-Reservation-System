#pragma once
#include"identity.h"

class Teacher:public Identity
{
public:
	Teacher();
	Teacher(int id, string name,string pwd);
	~Teacher();
	
	virtual void open_menu();

	void show_all_order();//�鿴����ԤԼ
	
	void valid_order();//���ԤԼ

	int m_id;
	string m_name;
	string m_psw;

private:

};

