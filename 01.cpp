#include<iostream>
using namespace std;
int n, m;
int a[10];
void dfs(int f, int s) {
	if (f == m + 1) {
		for (int i = 1; i <= m; i++)
			printf("%3d", a[i]);
		putchar('\n');
		return;
	}
	for (int i = s; i <= n; i++) {
		a[f] = i;
		dfs(f + 1, i + 1);
	}
}
int main()
{
	cin >> n >> m;
	dfs(1, 1);
	return 0;
}