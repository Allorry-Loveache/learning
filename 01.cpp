#include"string.h"
int main()
{
	allorry::string s1("liuhaoran");
	allorry::string s2(s1);
	allorry::string s3("wujiahao");
	allorry::string s4("xxxx");
	/*s1 = s3;
	cout << s2.c_str() << endl << s1.c_str()<<endl;
	s1.everyone();
	cout << endl;
	s2 += " shi dog";
	cout << s2.c_str()<<endl;
	s2.resize(3, '8');
	cout << s2.c_str() << endl;
	cout << s1.find("jiaa") << endl;

	cout << (s1 >= s2) << endl;
	cout << (s2 <= s3) << endl;*/

	allorry::string s5;
	allorry::string s6;
	cin >> s5;
	getline(cin, s6);
	s5 += "haoye";
	s6 += s5;
	cout << s5 << endl << s6 << endl;
}

