#include"student.h"


Student::Student(int id, string name, string psw) {
	this->m_id = id;
	this->m_name = name;
	this->m_psw = psw;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	Computer_Room com;

	while (ifs >> com.m_id && ifs >> com.m_max_cap)
	{
		vcom.push_back(com);
	}

}//学号、姓名、密码


void Student::open_menu(){
	cout << "欢迎学生代表:" << this->m_name << "登录" << endl;
	cout << "\t------------------------------------" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          1.申请预约               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          2.查看我的预约           |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          3.查看所有预约           |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          4.取消预约               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          0.退    出               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t------------------------------------" << endl;
	cout << "请选择操作：" << endl;

}

void Student::apply_order() {

	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;//日期
	int time = 0;//时间段
	int room = 0;//房间号

	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5)break;
		cout << "输入有误，重输入" << endl;
	}

	cout << "请输入时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> time;
		if (time >= 1 && time <= 2)break;
		cout << "输入有误，重输入" << endl;
	}
	cout << "选择机房" << endl;
	for (int i = 0; i < vcom.size(); i++) {
		cout << vcom[i].m_id << "号机房容量为：" << vcom[i].m_max_cap << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功,待审核" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "time:" << time << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");

}//申请预约

void Student::show_order() {

	Order_file of;
	if (of.m_size == 0) {

		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	string temp_time;
	string status;
	for (int i = 0; i < of.m_size; i++) {
		if (this->m_id == atoi(of.morder[i]["stuid"].c_str())) {
			if (of.morder[i]["time"] == "1")  temp_time = "上午";
			else temp_time = "下午";
			if (of.morder[i]["status"] == "0")status = "预约成功";
			else if (of.morder[i]["status"] == "1")status = "审核中";
			else if (of.morder[i]["status"] == "-1")status = "预约失败";
			else if (of.morder[i]["status"] == "2")status = "取消预约";
			cout << "日期：星期" << of.morder[i]["date"] << temp_time << " " << "使用者：" << of.morder[i]["stuname"];
			cout << " " << "预约状态:" << status;
			cout << endl;
		}
		else break;
	}
	
	system("pause");
	system("cls");


}//查看自身预约

void Student::show_all_order() {

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


}//查看所有预约

void Student::cancel_order() {
	Order_file of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;//存放最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < of.m_size; i++) {

		if (this->m_id = atoi(of.morder[i]["stuid"].c_str())) {

			if (of.morder[i]["status"] == "1" || of.morder[i]["status"] == "0") {
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.morder[i]["date"];
				cout << "时间段:" <<( of.morder[i]["time"] == "1" ? "上午" : "下午");
				cout << "机房编号：" << of.morder[i]["roomid"];
				
				string status = "状态:";
				if (of.morder[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.morder[i]["status"] == "0") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << endl;
	cout << "0返回" << endl;
	int select=0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;

			}
			else {
				of.morder[v[select - 1]]["status"] = "2";
				of.update_order();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，重新输入" << endl;
	}
	system("pause");
	system("cls");
}

Student::Student()
{
}

Student::~Student()
{
}