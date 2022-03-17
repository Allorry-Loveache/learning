#include<iostream>
using namespace std;
int b[205];
int a[205];
int x, _end, n;
int m = 999;
void dfs(int x, int step) {
	if (x == _end) { if (m > step) m = step;   return; }
	if (step > m) return;
	int count = 2;
	b[x] = 1;
	while (count--) {
		int tx;
		if (count) tx = x + a[x];
		else tx = x - a[x];
		if (tx > n || tx < 1 || b[tx] == 1) continue;
		dfs(tx, step + 1);
	}
	b[x] = 0;
}
int main()
{
	int  i;
	cin >> n >> x >> _end;
	for (i = 1; i <= n; i++)  cin >> a[i];
	dfs(x, 0);
	if (m == 999) printf("-1");
	else printf("%d", m);
}
