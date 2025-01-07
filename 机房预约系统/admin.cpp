#include"admin.h"



Admin::Admin(string name, string psw)
{
	this->m_name = name;
	this->psw = psw;

	//初始化容器
	this->init_vector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	Computer_Room com;
	while (ifs>>com.m_id&&ifs>>com.m_max_cap)
	{
		vcom.push_back(com);
	}
	ifs.close();
	//cout << "机房数量为：" << vcom.size() << endl;
}


Admin::Admin()
{

}

Admin::~Admin()
{

}



void Admin::open_menu() {
	cout << "\twelcom,admin-" <<this->m_name<< endl;
	cout << "\t------------------------------------" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          1.添加账号               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          2.查看账号               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          3.查看机房               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          4.清空预约               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          0.退    出               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t------------------------------------" << endl;

}

void Admin::add_member() {
	cout << "请输入添加的账号的类型:" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	string filename;
	string tip;//提示
	ofstream ofs;//文件操作对象
	string errortip;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//添加学生
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复";
	}
	else {
		filename = TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "职工编号重复";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string psw;


	cout << tip << endl;

	while (1)
	{
		cin >> id;
		bool result=check_repeat(id, select);
		if (result) {
			cout << errortip <<",请重新输入"<< endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> psw;

	ofs << id << " " << name << " " << psw << " " << endl;
	cout << "添加完成" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->init_vector();
}

void Admin::init_vector() {
	this->vstu.clear();
	this->vtec.clear();
	
	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_psw) {
		vstu.push_back(s);
	}
	//cout << "当前学生数量为：" << vstu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_id && ifs >> t.m_name && ifs >> t.m_psw) {
		vtec.push_back(t);
	}
	//cout << "当前老师数量为：" << vtec.size() << endl;
	ifs.close();
}

bool Admin::check_repeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = this->vstu.begin(); it != this->vstu.end(); it++) {
			if (id == it->m_id) {
				return 1;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->vtec.begin(); it != this->vtec.end(); it++) {
			if (id == it->m_id) {
				return 1;
			}
		}
	}
	return 0;
}

void print_student(Student& s) {
	cout << "学号：" << s.m_id << "姓名：" << s.m_name<<endl;
}

void print_tec(Teacher& t) {
	cout << "学号：" << t.m_id << "姓名：" << t.m_name<<endl;
}

void Admin::show_member() {
	cout << "请选择查看的内容：" << endl;
	cout << "1、查看所有的学生" << endl;
	cout << "2、查看所有的老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//遍历算法遍历所有学生
		cout << "所有学生信息如下：" << endl;
		for_each(vstu.begin(), vstu.end(), print_student);

	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vtec.begin(), vtec.end(), print_tec);
	}
	system("pause");
	system("cls");
}//显示所有人员

void Admin::show_computer() {
	cout << "机房信息如下：" << endl;

	for (vector<Computer_Room>::iterator it = vcom.begin(); it != vcom.end(); it++) {
		cout << "机房编号:" << it->m_id << "机房最大容量:" << it->m_max_cap << endl;
	}
	system("pause");
	system("cls");
}//显示电脑预约信息

void Admin::clear_file() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功。" << endl;
	system("pause");
	system("cls");

}//清除预约
