//#include <bits/stdc++.h>
//using namespace std;
//class employee {
//private:
//	string _name, _department;
//	int _income, id;
//	static int nums;
//	static double rate;
//public:
//	employee(string name, string department, int income) {
//		_name = name;
//		_department = department;
//		_income = income;
//		id = nums++;
//	}
//	static int getNumber() {
//		return nums;
//	}
//	void print() {
//		cout << "The employee's uid is " << id << ",name is " << _name
//			<< ",department is " << _department << ",income is " << _income << ".\n";
//	}
//	void getTax() {
//		cout << "this one's tax is:" << rate * _income << endl;
//	}
//	bool operator<(const employee& x) {
//		return _income < x._income;
//	}
//};
//int employee::nums = 0;
//double employee::rate = 0;
//int main()
//{
//	vector<employee> v;
//	int n;
//	cout << "请输入成员数目" << endl;
//	cin >> n;
//	cout << "请输入名字 部门 工资" << endl;
//	string name, department; int income;
//	for (int i = 0; i < n; i++) {
//		cin >> name >> department >> income;
//		v.push_back(employee(name, department, income));
//	}
//	sort(v.begin(), v.end());
//	for (int i = 0; i < n; i++) {
//		v[i].print();
//	}
//}







//#include<bits/stdc++.h>
//using namespace std;
//class Vec {
//    int* a;
//    int count;
//public:
//    Vec(int* arr=nullptr, int n=0) {
//        swap(a, arr);
//    }
//    int operator*(int n) {
//
//    }
//};
//int main() {
//    int n;
//    cin >> n;
//    int* arr1 = new int[n];
//    int* arr2 = new int[n];
//    for (int i = 0; i < n; ++i)
//        cin >> arr1[i];
//    for (int i = 0; i < n; ++i)
//        cin >> arr2[i];
//    Vec v1(arr1, n);
//    Vec v2(arr2, n);
//    Vec v3 = 3 * v1 + 2 * v2;
//    v3.print();
//    return 0;
//}





文件路径都和.cpp文件所在位置相同，经检查，结果是对的


//第一题
//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//
//	FILE* p = fopen("text.txt", "r");
//	char t[100], ch;
//	int sum = 0, flag=1;
//	while (!feof(p)) {
//		ch = fgetc(p);
//		if (ch == '\n') flag = 0;
//		else {
//			if (flag == 0) sum++, flag = 1;
//		}
//		if (ch >= 65 && ch <= 90) ch += 32;
//		cout << ch;
//	}
//	cout << endl << sum;
//}


//第三题
//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//
//	FILE* p = fopen("text2.txt", "r");
//	char t[100], ch;
//	int count = 0;
//	int flag = 1;
//	int sum = 0;
//	while (!feof(p)) {
//		ch = fgetc(p);
//		if (ch >= '0' && ch <= '9')
//		{
//			count = count * 10 + ch - '0';
//		}
//		else {
//			sum += count;
//			count = 0;
//		}
//	}
//	p = fopen("text2.txt", "a+");
//	fprintf(p, "%d", sum);
//	fclose(p);
//	
//	cout << endl << sum;
//}



//第二题
//本题一个文件里放本来的密码
//我把加密后的文件放到了另一个文件里
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{

	FILE* p = fopen("text3.txt", "a+");
	FILE* p2 = fopen("jiami.txt", "w");
	char ch = '0';
	while (!feof(p)) {
		ch = fgetc(p);
		if (ch == '\n') {
			fputc('\n', p2);
			continue;
		}
		else if (ch == ' ') {
			fputc(' ', p2);
			continue;
		}
		ch += 3;
		if (ch <= 70 && ch > '9') ch -= 10;
		else if (ch > 122) ch -= 26;
		fputc(ch, p2);
	}

}




#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{

	FILE* p = fopen("text.txt", "a+");
	FILE* p2 = fopen("jiami.txt", "w");
	char ch = '0';
	char t[100];
	while (!feof(p)) {
		fgets(t, 100, p);
		if (strstr(t, "for"))
			cout << t;
	}

}