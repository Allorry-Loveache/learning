#include<iostream>
#include<algorithm>
using namespace std;
int nex[2][2] = { {1,0},{0,1} };
int m, n, k, sum=0;
string a[105];
void dfs(int x,int y,int f,int v) {//坐标xy，层数f，控制方向v
	if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == '#') return;
	if (f >= k) { sum++; return; }
	int tx = x + nex[v][0], ty = y + nex[v][1];
	dfs(tx, ty, f + 1, v);
}
int main()
{
	int  i, j;
	cin >> n >> m >> k;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			dfs(i, j, 1, 0);
			dfs(i, j, 1, 1);
		}
	}
	if (k == 1) sum /= 2; //鬼一样的特判
	cout << sum;
}
