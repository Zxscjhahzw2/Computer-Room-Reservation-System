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
	 cout << "��ӭ��ʦ:" << this->m_name << "��¼" << endl;
	 cout << "\t------------------------------------" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t|          1.�鿴����ԤԼ           |" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t|          2.��  �� Ԥ Լ           |" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t|          0.��        ��           |" << endl;
	 cout << "\t|                                   |" << endl;
	 cout << "\t------------------------------------" << endl;
	 cout << "��ѡ�������" << endl;
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
		if (it->second["time"] == "1")temp_time = "����";
		else temp_time = "����";
		if (it->second["status"] == "0")status = "ԤԼ�ɹ�";
		else if (it->second["status"] == "1")status = "�����";
		else if (it->second["status"] == "-1")status = "ԤԼʧ��";
		else if (it->second["status"] == "2")status = "ȡ��ԤԼ";
		cout << "���ڣ�����" << it->second["date"] << temp_time << " " << "ʹ���ߣ�" << it->second["stuname"];
		cout << " " << "ԤԼ״̬:" << status;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::valid_order() {
	Order_file of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
	
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "����˼�¼����" << endl;
	for (int i = 0; i < of.m_size; i++) {
		if (of.morder[i]["status"] == "1") {
			v.push_back(i);
			cout<<++index<<"��";
			cout << "ԤԼ���ڣ���" << of.morder[i]["date"]<<" ";
			cout << "ʱ���:" << (of.morder[i]["time"] == "1" ? "����" : "����")<<" ";
			cout << "ѧ�����:" << of.morder[i]["stuid"]<<" ";
			cout << "ѧ������:" << of.morder[i]["stuname"]<<" ";
			cout << "�������:" << of.morder[i]["roomid"];
			string status = "�����";
			cout << "  " << status << endl;

		}
	}
	cout << "������˵�ԤԼ��¼��0����" << endl;
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
				cout << "��������˽����1ͨ����2��ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {//ͨ��
					of.morder[v[select - 1]]["status"] = "0";
				}
				else {
					of.morder[v[select - 1]]["status"] = "-1";
				}
				of.update_order();
				cout << "������" << endl;
				break;
			}
		}
	}

	system("pause");
	system("cls");
}