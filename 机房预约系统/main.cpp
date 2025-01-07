#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"global_file.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"

//�������Ա�Ӳ˵�����
void admin_menu(Identity*& admin) {

	while (true)
	{
		admin->open_menu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Admin* man = (Admin*)admin;

		int select = 0;
		cin >> select;//�����û�ѡ��
		if (select == 1) {//����˺�
			//cout << "����˺�" << endl;
			man->add_member();
		}
		else if (select==2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->show_member();
		}
		else if(select==3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->show_computer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->clear_file();
		}
		else {
			delete admin;
			cout << "�˳��ɹ�" << endl;
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

		Teacher* tec = (Teacher*)teacher; //��ָ��student�ĸ���ָ��ת��studentָ��

		int select = 0;
		cin >> select;

		if (select == 1) {//����ԤԼ
			tec->show_all_order();
		}
		else if (select == 2) {//�鿴����ԤԼ
			tec->valid_order();
		}
		else//�˳���¼
		{
			delete teacher;
			teacher = nullptr;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ������
void student_menu(Identity*& student) {
	while (true)
	{
		student->open_menu();

		Student* stu = (Student*)student; //��ָ��student�ĸ���ָ��ת��studentָ��

		int select = 0;
		cin >> select;

		if (select == 1) {//����ԤԼ
			stu->apply_order();
		}
		else if (select==2) {//�鿴����ԤԼ
			stu->show_order();
		}
		else if (select == 3) {//�鿴������ԤԼ
			stu->show_all_order();
		}
		else if (select == 4) {//ȡ��ԤԼ
			stu->cancel_order();
		}
		else//�˳���¼
		{
			delete student;
			student = nullptr;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void login(string file_name, int type) {
	Identity* person = NULL;//����ָ�룬����ָ���������

	//���ļ�
	ifstream ifs;
	ifs.open(file_name, ios::in);

	//�ж��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼���û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) {//ѧ��
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	if (type == 2) {
		cout << "���������ְ����:" << endl;
		cin >> id;
	}//��ʦ
	cout << "�������û���:" << endl;
	cin >> name;

	cout << "����������:" << endl;
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
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
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
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ�Ӳ˵�
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
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Admin(name, pwd);
				//�������Ա�Ӳ˵�
				admin_menu(person);

				return;
			}
		}
	}

	cout << "��¼ʧ��" << endl;
	system("pause");
	system("cls");
}


int main() {
	int select = 0;//�����û�ѡ��
	while(1){
		cout << "\t ========��ӭʹ�û���ԤԼϵͳ========" << endl;
		cout << "\t------------------------------------" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          1.ѧ������               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          2.��    ʦ               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          3.�� �� Ա               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t|          0.��    ��               |" << endl;
		cout << "\t|                                   |" << endl;
		cout << "\t------------------------------------" << endl;
		cout << "���������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1://ѧ�����
			login(STUDENT_FILE,select);
			break;
		case 2://��ʦ���
			login(TEACHER_FILE,select);
			break;
		case 3://����Ա���
			login(ADMIN_FILE,select);
			break;
		case 4:
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}