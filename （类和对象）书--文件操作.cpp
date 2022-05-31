#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cmath>
using namespace std;



class book {
	string name;
	string id;
	string author;
	string brand;
public:
	book(string a = "", string b = "", string c = "", string d = "") :
		name(a), id(b), author(c), brand(d) {}
	void info() {
		cout << name << '\t' << id << '\t' << author << '\t' << brand << '\t' << endl;
	}
	void info_out() {
		ofstream f("book.dat", ios::binary | ios::app);
		f << name << '\t' << id << '\t' << author << '\t' << brand << '\t' << endl;
		f.close();
	}
	string getn() {
		return name;
	}
	bool operator<(book& x) {
		return name < x.name;
	}
};

void show(vector<book>& x) {
	cout << "书名\t" << "编号\t" << "作者\t" << "出版社\t" << endl;
	for (int i = 0; i < x.size(); i++) {
		x[i].info();
	}
}

void find(vector<book>& x, string& n) {
	int flag = 1;
	for (int i = 0; i < x.size(); i++) {
		if (x[i].getn() == n) {
			x[i].info();
			flag = 0;
			break;
		}
	}
	if (flag)  cout << "查无此书" << endl;
}

void sortt(vector<book>& x) {
	sort(x.begin(), x.end());
}

void another(vector<book>& x) {
	sortt(x);
	vector<bool> f(x.size(), 0);
	for (int i = 0; i < x.size() - 1; i++) {
		if (x[i].getn() == x[i + 1].getn())
			f[i] = 1, f[i + 1] = 1;
	}
	for (int i = 0; i < f.size(); i++) {
		if (f[i]) x[i].info();
	}
}

void menu() {
	printf("********************************\n");
	printf("******   0. 退出      **********\n");
	printf("******   1. 添加      **********\n");
	printf("******   2. 显示      **********\n");
	printf("******   3. 查找      **********\n");
	printf("******   4. 排序      **********\n");
	printf("***  5. 查重（兼并排序）  ******\n");
	printf("********************************\n");
}

int main()
{
	vector<book> v;
	string a, b, c, d;
	int n;
	int count = 0;
	ofstream f("book.dat", ios::binary | ios::app);
	f << "书名\t" << "编号\t" << "作者\t" << "出版社\t" << endl;
	f.close();

	while (1) {
		menu();
		cin >> n;
		if (n == 0) return 0;
		if (n == 1) {
			cout << "注意：书名短一点，bug不想改了" << endl;
			cout << "请分别输入 书名 编号 作者 出版社：（用空格间隔）" << endl;
			cin >> a >> b >> c >> d;
			v.push_back(book(a, b, c, d));
			v[count++].info_out();
		}
		if (n == 2) {
			show(v);
		}
		if (n == 3) {
			string t;
			cout << "请输入书名:" << endl;
			cin >> t;
			find(v, t);
		}
		if (n == 4) {
			sortt(v);
		}
		if (n == 5) {
			another(v);
		}
		system("pause");
		system("cls");
	}
}






#include<iostream>
using namespace std;

template <class T>
void sortt(T arr[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}



template<class T>
int find(T a[], int n, T base)
{
	for (int i = 0; i < n; i++)
		if (a[i] == base)
			return i;
	return -1;

}
int main()
{
	int base;
	int a[] = { 3, 5,2,1,43,87,23,777 };
	int n = sizeof(a) / sizeof(int);
	sortt(a, n);
	for (int i : a) cout << i << ' ';
	cout << endl;
	cout << "input a base:" << endl;
	cin >> base;
	cout << find(a, n, base) << endl;
}
