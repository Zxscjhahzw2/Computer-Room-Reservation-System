#include"orderfile.h"

Order_file::Order_file()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string time;
	string stuid;
	string stuname;
	string roomid;
	string status;

	while (ifs >> date && ifs >> time && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		//cout << data << endl;
		//cout << time << endl;
		//cout << stuid << endl;
		//cout << stuname << endl;
		//cout << roomid << endl;
		//cout << status << endl;
		string key;
		string value;
		map<string, string>m;
		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = time.find(":");
		if (pos != -1) {
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuid.find(":");
		if (pos != -1) {
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuname.find(":");
		if (pos != -1) {
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1) {
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//将小map放入大map
		this->morder.insert(make_pair(this->m_size, m));
		this->m_size++;

	}
	ifs.close();
	//string temp_time;
	//for (map<int, map<string, string>>::iterator it = morder.begin(); it != morder.end(); it++) {

	//	cout << "key=" << it->first << "value=" ;
	//	//for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
	//	//	cout << mit->first << mit->second <<" ";
	//	//}
	//	if (it->second["time"] == "1")temp_time = "上午";
	//	else temp_time = "下午";
	//	cout << "日期：星期" << it->second["data"] << temp_time<< " " << "使用者：" << it->second["stuname"];
	//	cout << endl;
	//}
}

Order_file::~Order_file()
{




}

//更新预约记录
void Order_file::update_order() {
	if (this->m_size == 0) {
		return;
	} 
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++) {
		ofs << "date:" << this->morder[i]["date"] << " ";
		ofs << "time:" << this->morder[i]["time"] << " ";
		ofs << "stuid:" << this->morder[i]["stuid"] << " ";
		ofs << "stuname:" << this->morder[i]["stuname"] << " ";
		ofs << "roomid:" << this->morder[i]["roomid"] << " ";
		ofs << "status:" << this->morder[i]["status"] << " ";

	}

	ofs.close();
	system("pause");
	system("cls");
}

