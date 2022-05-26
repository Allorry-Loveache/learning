
#include<iostream>
using namespace std;

int main(void) {
	//打印二进制数
	int a[32];
	int num = 32;
	int tmp = 0;
	for (int i = 31; i >= 0; i--) {
		//第一次向左移动31位，第二次30位 
		tmp = (num >> i) & 1;
		a[31 - i] = tmp;
	}
	for (int i : a) cout << i;
}







//#include <vector> 
//#include <string> 
//#include <fstream>
//#include<sstream>
//#include <iostream> 
//
//using namespace std;
//
//int main()
//{
//    /*int a[] = { 11,22,33,44,55 };
//    ostringstream s("hello world", ios::out);   
//    for (int i = 0; i < 5; i++) {   //写到s里
//        s << a[i] << ' ';
//    }
//    cout << s.str() << endl;*/
//
//    string a;
//    ifstream f("hello.txt", ios::in);
//    while (getline(f, a)) {   //读入a里
//        double d;
//        istringstream s(a);
//        while (s >> d) cout << d << "   ";
//        cout << endl;
//    } 
//}






#include<bits/stdc++.h>
using namespace std;

struct ServerInfo {      //网络信息
	char ip[20];
	int port;
};

class ConfigManager {    //配置
public:
	ConfigManager(const char* name) : filename(name) {}

	void ReadBin(ServerInfo& info) {
		ifstream ifs(filename);
		ifs.read((char*)&info, sizeof(info));
	}

	void WriteBin(const ServerInfo& info) {
		ofstream ofs(filename);
		ofs.write((char*)&info, sizeof(info));
	}

	void WriteTxt(const ServerInfo& info) {
		ofstream ofs(filename);
		/*ofs.write(info.ip, strlen(info.ip));
		ofs.put('\n');
		string t = to_string(info.port);
		ofs.write(t.c_str(), t.size());*/

		ofs << info.ip << '\n' << info.port;
	}

	void ReadTxt(ServerInfo& info) {
		ifstream ifs(filename);
		/*ifs.getline(info.ip, 20);
		char buff[20];
		ifs.getline(buff, 20);
		info.port = stoi(buff);*/

		ifs >> info.ip >> info.port;
	}
private:
	string filename;
};

int main()
{
	ServerInfo rinfo;   //读取
	ServerInfo winfo = { "192.0.0.1", 80 };  //输出
	ConfigManager cfbin("config.bin");
	//读写 二进制
	cfbin.WriteBin(winfo);
	cfbin.ReadBin(rinfo);

	//读写 文本
	ConfigManager cftxt_w("config.txt");
	cftxt_w.WriteTxt(winfo);
	ConfigManager cftxt_r("config.txt");
	cftxt_r.ReadTxt(rinfo);

	ServerInfo info = { "192.0.0.1", 80 };
	char b[128];
	sprintf(b, "%s %d", info.ip, info.port);

	ServerInfo fo;
	sscanf(b, "%s %d", fo.ip, &fo.port);
}