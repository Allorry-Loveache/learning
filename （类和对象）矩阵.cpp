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
	Matrix(Matrix& t) {
		row = t.row; col = t.col;
		a = new int* [row];
		for (int i = 0; i < row; i++) {
			a[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a[i][j] = t.a[i][j];
	}

	friend istream& operator>>(istream& in, Matrix it) {
		for (int i = 0; i < it.row; i++)
			for (int j = 0; j < it.col; j++)
				in >> it.a[i][j];
		return in;
	}
	friend ostream& operator<<(ostream& out, const Matrix it) {
		for (int i = 0; i < it.row; i++) {
			for (int j = 0; j < it.col; j++)
				out << it.a[i][j] << ' ';
			out << endl;
		}
		cout << "haoye" << endl;
		return out;
	}
	void transform() {
		int r1 = col, c1 = row;
		int b[30][30];
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				b[i][j] = a[i][j];
		for (int i = 1; i <= r1; i++)
			for (int j = 1; j <= c1; j++)
				a[i][j] = b[j][i];
		row = r1, col = c1;
	}
	int& operator() (int r, int c) {   //修改/提取元素，别用友元函数
		return a[r][c];
	}
	Matrix& operator=(Matrix& t) {
		Matrix tt(t);
		swap(tt);
		return *this;
	}
};
int main()
{
	Matrix ma(3, 3);
	ma(1, 1) = 35;
	Matrix haoye(4, 5);
	haoye = ma;
	cout << haoye;
}
