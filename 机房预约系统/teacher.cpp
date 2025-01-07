#include"teacher.h"
#include"orderfile.h"
Teacher::Teacher() {
	
}
Teacher::Teacher(int id, string name, string pwd) {
	this->m_id = id;
	this->m_name = name;
	this->m_psw = pwd;
}
Teacher::~Teacher() {

}

 void Teacher::open_menu() {
	 cout << "欢迎老师:" << this->m_name << "登录" << endl;
	 cout << "\t------------------------------------" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t|          1.查看所有预约           |" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t|          2.审  核 预 约           |" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t|          0.退        出           |" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t------------------------------------" << endl;
	 cout << "请选择操作：" << endl;
}

void Teacher::show_all_order() {
	Order_file of;
	string temp_time;
	string status;
	for (map<int, map<string, string>>::iterator it = of.morder.begin(); it != of.morder.end(); it++) {

		cout << "key=" << it->first << "value=";
		//for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
		//	cout << mit->first << mit->second <<" ";
		//}
		if (it->second["time"] == "1")temp_time = "上午";
		else temp_time = "下午";
		if (it->second["status"] == "0")status = "预约成功";
		else if (it->second["status"] == "1")status = "审核中";
		else if (it->second["status"] == "-1")status = "预约失败";
		else if (it->second["status"] == "2")status = "取消预约";
		cout << "日期：星期" << it->second["date"] << temp_time << " " << "使用者：" << it->second["stuname"];
		cout << " " << "预约状态:" << status;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::valid_order() {
	Order_file of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
	
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "待审核记录如下" << endl;
	for (int i = 0; i < of.m_size; i++) {
		if (of.morder[i]["status"] == "1") {
			v.push_back(i);
			cout<<++index<<"、";
			cout << "预约日期：周" << of.morder[i]["date"]<<" ";
			cout << "时间段:" << (of.morder[i]["time"] == "1" ? "上午" : "下午")<<" ";
			cout << "学生编号:" << of.morder[i]["stuid"]<<" ";
			cout << "学生姓名:" << of.morder[i]["stuname"]<<" ";
			cout << "机房编号:" << of.morder[i]["roomid"];
			string status = "审核中";
			cout << "  " << status << endl;

		}
	}
	cout << "输入审核的预约记录，0返回" << endl;
	int select = 0;
	int ret = 0;
	while (true) {

		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else
			{
				cout << "请输入审核结果：1通过，2不通过" << endl;
				cin >> ret;
				if (ret == 1) {//通过
					of.morder[v[select - 1]]["status"] = "0";
				}
				else {
					of.morder[v[select - 1]]["status"] = "-1";
				}
				of.update_order();
				cout << "审核完毕" << endl;
				break;
			}
		}
	}

	system("pause");
	system("cls");
}