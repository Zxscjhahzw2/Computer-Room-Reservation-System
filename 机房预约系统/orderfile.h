#pragma once
#include"identity.h"
#include<map>
class Order_file
{
public:
	Order_file();
	~Order_file();

	//更新预约记录
	void update_order();

	//记录预约条数
	int m_size;

	//记录所有预约记录的容器
	map<int, map<string, string>>morder;

private:

};

