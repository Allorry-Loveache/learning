#include<bits/stdc++.h>
using namespace std;
class Matrix {
	int row;
	int col;
	int** a;
public:
	Matrix(int r = 2, int c = 3) {
		row = r; col = c;
		a = new int* [row];
		for (int i = 0; i < row; i++) {
			a[i] = new int[col];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				a[i][j] = 0;
			}
		}
	}
	void swap(Matrix& t) {
		::swap(a, t.a);
		::swap(row, t.row);
		::swap(col, t.col);
	}
	Matrix(const Matrix& t) {
		row = t.row; col = t.col;
		a = new int* [row];
		for (int i = 0; i < row; i++) {
			a[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a[i][j] = t.a[i][j];
	}

	friend istream& operator>>(istream& in, Matrix& it) {
		printf("请输入%d行%d列\n", it.row, it.col);
		for (int i = 0; i < it.row; i++)
			for (int j = 0; j < it.col; j++)
				in >> it.a[i][j];
		return in;
	}
	friend ostream& operator<<(ostream& out, Matrix& it) {
		putchar('\n');
		for (int i = 0; i < it.row; i++) {
			for (int j = 0; j < it.col; j++)
				out << it.a[i][j] << ' ';
			out << endl;
		}
		putchar('\n');
		return out;
	}
	void transform() {
		int** b;
		b = new int* [col];
		for (int i = 0; i < col; i++) {
			b[i] = new int[row];
		}
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
				b[i][j] = a[j][i];
		::swap(a, b);
		int t = row; row = col; col = t;
	}
	int& operator() (int r, int c) {   //修改/提取元素，别用友元函数
		return a[r][c];
	}
	Matrix& operator=(const Matrix& t) {
		Matrix tt(t);
		swap(tt);
		return *this;
	}
	Matrix operator+(Matrix& t) {
		if (t.row != row || t.col != col) {
			cout << "不匹配，无法相加" << endl;
			exit(-1);
		}
		Matrix tt(*this);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				tt.a[i][j] += t.a[i][j];
		return tt;
	}
	Matrix operator*(Matrix& t) {
		if (col != t.row) {
			cout << "不匹配，无法相乘" << endl;
			exit(-1);
		}
		Matrix ans(row, t.col);
		int sum = 0;
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < t.col; k++) {
				for (int j = 0; j < col; j++) {
					sum += a[i][j] * t.a[j][k];
				}
				ans.a[i][k] = sum;
				sum = 0;
			}
		}
		return ans;
	}
};
int main()
{
	Matrix a(3, 4);
	Matrix b(4, 5);
	cin >> a >> b;
	cout << a << b;
	Matrix c;
	Matrix d;
	c = a * b;
	//d = a + b;
	cout << c;
	c.transform();
	cout << c;
}
