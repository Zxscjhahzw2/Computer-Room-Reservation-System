#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"

class Admin:public Identity
{
public:
	Admin();
	Admin( string name, string psw);

	virtual void open_menu();

	void add_member();

	void show_member();//显示所有人员

	void show_computer();//显示电脑预约信息

	void clear_file();//清除预约

	void init_vector();



	bool check_repeat(int id, int type);

	vector <Student>vstu;
	vector <Teacher>vtec;
	vector<Computer_Room>vcom;

	~Admin();

	string m_name;
	string psw;

private:

};

