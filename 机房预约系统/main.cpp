#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"global_file.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"

//进入管理员子菜单界面
void admin_menu(Identity*& admin) {

	while (true)
	{
		admin->open_menu();

		//将父类指针转为子类指针，调用子类里其它接口
		Admin* man = (Admin*)admin;

		int select = 0;
		cin >> select;//接收用户选择
		if (select == 1) {//添加账号
			//cout << "添加账号" << endl;
			man->add_member();
		}
		else if (select==2)//查看账号
		{
			//cout << "查看账号" << endl;
			man->show_member();
		}
		else if(select==3)//查看机房
		{
			//cout << "查看机房" << endl;
			man->show_computer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			man->clear_file();
		}
		else {
			delete admin;
			cout << "退出成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacher_menu(Identity*& teacher) {
	while (true)
	{
		teacher->open_menu();

		Teacher* tec = (Teacher*)teacher; //将指向student的父类指针转成student指针

		int select = 0;
		cin >> select;

		if (select == 1) {//申请预约
			tec->show_all_order();
		}
		else if (select == 2) {//查看自身预约
			tec->valid_order();
		}
		else//退出登录
		{
			delete teacher;
			teacher = nullptr;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生界面
void student_menu(Identity*& student) {
	while (true)
	{
		student->open_menu();

		Student* stu = (Student*)student; //将指向student的父类指针转成student指针

		int select = 0;
		cin >> select;

		if (select == 1) {//申请预约
			stu->apply_order();
		}
		else if (select==2) {//查看自身预约
			stu->show_order();
		}
		else if (select == 3) {//查看所有人预约
			stu->show_all_order();
		}
		else if (select == 4) {//取消预约
			stu->cancel_order();
		}
		else//退出登录
		{
			delete student;
			student = nullptr;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void login(string file_name, int type) {
	Identity* person = NULL;//父类指针，用于指向子类对象

	//读文件
	ifstream ifs;
	ifs.open(file_name, ios::in);

	//判断是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) {//学生
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	if (type == 2) {
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}//老师
	cout << "请输入用户名:" << endl;
	cin >> name;

	cout << "请输入密码:" << endl;
	cin >> pwd;

	if (type == 1) {
		int fid;
		string fname;
		string fpsw;

		while (ifs>>fid&&ifs>>fname&&ifs>>fpsw)
		{

			if (id == fid && name == fname && pwd == fpsw) {
				//cout << fid << endl;
				//cout << fname << endl;
				//cout << fpsw << endl;
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单
				student_menu(person);

				return;
			}
		}
	}

	else if (type == 2) {
		int fid;
		string fname;
		string fpsw;
		while (ifs >> fid && ifs >> fname && ifs >> fpsw)
		{

			if (id == fid && name == fname && pwd == fpsw) {
				//cout << fid << endl;
				//cout << fname << endl;
				//cout << fpsw << endl;
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师子菜单
				teacher_menu(person);

				return;
			}
		}
	}
	
	else if (type == 3) {
		string fname;
		string fpsw;
		while ( ifs >> fname && ifs >> fpsw)
		{

			if ( name == fname && pwd == fpsw) {
				//cout << fid << endl;
				//cout << fname << endl;
				//cout << fpsw << endl;
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Admin(name, pwd);
				//进入管理员子菜单
				admin_menu(person);

				return;
			}
		}
	}

	cout << "登录失败" << endl;
	system("pause");
	system("cls");
}


int main() {
	int select = 0;//接收用户选择
	while(1){
		cout << "\t ========欢迎使用机房预约系统========" << endl;
		cout << "\t------------------------------------" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          1.学生代表               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          2.老    师               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          3.管 理 员               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          0.退    出               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t------------------------------------" << endl;
		cout << "请输入你的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1://学生身份
			login(STUDENT_FILE,select);
			break;
		case 2://老师身份
			login(TEACHER_FILE,select);
			break;
		case 3://管理员身份
			login(ADMIN_FILE,select);
			break;
		case 4:
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，重新选择。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}