#pragma once
#include"identity.h"
#include<map>
class Order_file
{
public:
	Order_file();
	~Order_file();

	//����ԤԼ��¼
	void update_order();

	//��¼ԤԼ����
	int m_size;

	//��¼����ԤԼ��¼������
	map<int, map<string, string>>morder;

private:

};

