#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define Row 12
#define Col 9
class Room {
	friend class sys;
	vector < vector <char> > room;
	int row, col;
public:
	Room() {
		for (int i = 1; i <= Row + 1; i++)
			room.push_back(vector<char>(Col + 1, '0'));
		row = Row; col = Col;
	}
	void show() {
		cout << 0 << "      ";
		for (int i = 1; i <= col; i++) {
			if (i >= 10) cout << i << " ";
			else cout << i << "  ";
			if (i % 3 == 0) cout << "      ";
		}
		cout << endl << endl << endl;
		for (int i = 1; i <= row; i++) {
			if (i >= 10) cout << i << "     ";
			else cout << i << "      ";
			for (int j = 1; j <= col; j++) {
				cout << room[i][j] << "  ";
				if (j % 3 == 0) cout << "      ";
			}
			if (i % 3 == 0) cout << endl << endl;
			cout << endl;
		}
	}
	void show(int r, int c) {
		cout << 0 << "      ";
		for (int i = 1; i <= col; i++) {
			if (i >= 10) cout << i << " ";
			else cout << i << "  ";
			if (i % 3 == 0) cout << "      ";
		}
		cout << endl << endl << endl;
		for (int i = 1; i <= row; i++) {
			if (i >= 10) cout << i << "     ";
			else cout << i << "      ";
			for (int j = 1; j <= col; j++) {
				if (i == r && j == c) cout << '#' << "  ";
				else cout << room[i][j] << "  ";
				if (j % 3 == 0) cout << "      ";
			}
			if (i % 3 == 0) cout << endl << endl;
			cout << endl;
		}
	}
};

class stu {
	friend class sys;
	int r, c; //ԤԼ��������
public:
	stu() {
		r = c = 0;
	}
};

class sys {
	stu s[10000];
	Room m;
	static int index;
public:
	sys() :s(), m() {}
	void find(int n) {
		if (n >= index) {
			printf("��������\n");
		}
		else m.show(s[n].r, s[n].c);
	}
	void show() {
		m.show();
	}
	void input(int r, int c) {
		if (r > Row || c > Col || r < 0 || c < 0) {
			printf("��������\n");
			return;
		}
		if (m.room[r][c] == '0') {
			m.room[r][c] = 'X';
			s[index].r = r;
			s[index].c = c;
			index++;
		}
		else if (m.room[r][c] == 'X') {
			printf("��������\n");
		}
	}
};
int sys::index = 1;
void menu() {
	printf("*****************\n");
	printf("    0. �˳�      \n");
	printf("    1. ԤԼ      \n");
	printf("    2. �鿴ԤԼ  \n");
	printf("    3. �鿴��λ  \n");
	printf("*****************\n");
}
int main()
{
	int n;
	sys s;
	while (1) {
		menu();
		cin >> n;
		if (n == 0) return 0;
		if (n == 1) {
			s.show();
			printf("��������ҪԤԼ��������\n");
			int r, c;
			cin >> r >> c;
			system("cls");
			s.input(r, c);
		}
		if (n == 2) {
			printf("��������Ҫ���ҵ��˵ı��\n");
			int n;
			cin >> n;
			system("cls");
			s.find(n);
		}
		if (n == 3) {
			system("cls");
			s.show();
		}
	}
}
