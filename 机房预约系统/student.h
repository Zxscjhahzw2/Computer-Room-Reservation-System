#pragma once

#include"identity.h"
#include"orderfile.h"
class Student:public Identity
{
public:
	Student();
	Student(int id,string name,string pwd);//ѧ�š�����������
	~Student();

	virtual void open_menu();
	void apply_order();//����ԤԼ
	void show_order();//�鿴����ԤԼ
	void show_all_order();//�鿴����ԤԼ
	void cancel_order();

	int m_id;

	vector<Computer_Room>vcom;
	string m_name;
	string m_psw;
private:

};

