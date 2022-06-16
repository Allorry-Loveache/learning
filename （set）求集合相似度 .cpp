#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, get;
	set<int> s[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> get;
			s[i].insert(get);
		}
	}
	int k, x, y, count = 0;
	set<int>::iterator it;
	cin >> k;
	while (k--) {  //遍历其中一个set集合，与另一个集合用find找匹配
		cin >> x >> y;
		for (it = s[x - 1].begin(); it != s[x - 1].end(); it++) {
			if (s[y - 1].find(*it) != s[y - 1].end()) count++;
		}
		printf("%.2f%%\n", count * 100.0 / (s[x - 1].size() + s[y - 1].size() - count));
		count = 0;
	}
}