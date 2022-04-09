#include<iostream>
#include<algorithm>
using namespace std;
int n, sum = 0;
int a[105], b[105], c[105], d[105];  //行，列，主对角线，副对角线
//适量加偏移量
void dfs(int f) {  // f == row
	if (f == n + 1) {
		sum++;
		if (sum <= 3) {
			for (int i = 1; i < f; i++)
				cout << a[i] << ' ';
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= n; i++) {  // i == col
		if (b[i] || c[f + i] || d[f - i + n]) continue;//被占领了
		a[f] = i;
		b[i] = 1, c[i + f] = 1, d[f - i + n] = 1;
		dfs(f + 1);
		b[i] = 0, c[i + f] = 0, d[f - i + n] = 0;
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << sum;
	return 0;
}
