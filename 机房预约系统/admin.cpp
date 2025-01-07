#include"admin.h"



Admin::Admin(string name, string psw)
{
	this->m_name = name;
	this->psw = psw;

	//��ʼ������
	this->init_vector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	Computer_Room com;
	while (ifs>>com.m_id&&ifs>>com.m_max_cap)
	{
		vcom.push_back(com);
	}
	ifs.close();
	//cout << "��������Ϊ��" << vcom.size() << endl;
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
	cout << "\t|          1.����˺�               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          2.�鿴�˺�               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          3.�鿴����               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          4.���ԤԼ               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t|          0.��    ��               |" << endl;
	cout << "\t|                                   |" << endl;
	cout << "\t------------------------------------" << endl;

}

void Admin::add_member() {
	cout << "��������ӵ��˺ŵ�����:" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;

	string filename;
	string tip;//��ʾ
	ofstream ofs;//�ļ���������
	string errortip;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//���ѧ��
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ�";
	}
	else {
		filename = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errortip = "ְ������ظ�";
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
			cout << errortip <<",����������"<< endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> psw;

	ofs << id << " " << name << " " << psw << " " << endl;
	cout << "������" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->init_vector();
}

void Admin::init_vector() {
	this->vstu.clear();
	this->vtec.clear();
	
	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_psw) {
		vstu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ��" << vstu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_id && ifs >> t.m_name && ifs >> t.m_psw) {
		vtec.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ��" << vtec.size() << endl;
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
	cout << "ѧ�ţ�" << s.m_id << "������" << s.m_name<<endl;
}

void print_tec(Teacher& t) {
	cout << "ѧ�ţ�" << t.m_id << "������" << t.m_name<<endl;
}

void Admin::show_member() {
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1���鿴���е�ѧ��" << endl;
	cout << "2���鿴���е���ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//�����㷨��������ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vstu.begin(), vstu.end(), print_student);

	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vtec.begin(), vtec.end(), print_tec);
	}
	system("pause");
	system("cls");
}//��ʾ������Ա

void Admin::show_computer() {
	cout << "������Ϣ���£�" << endl;

	for (vector<Computer_Room>::iterator it = vcom.begin(); it != vcom.end(); it++) {
		cout << "�������:" << it->m_id << "�����������:" << it->m_max_cap << endl;
	}
	system("pause");
	system("cls");
}//��ʾ����ԤԼ��Ϣ

void Admin::clear_file() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}//���ԤԼ
