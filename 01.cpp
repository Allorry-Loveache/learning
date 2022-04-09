#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005];
inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
int main()
{
	int n;
	n = read();
	long long maxx = -1e10, c, t;
	c = read(); n--;
	while (n--) {
		t = read();
		maxx = max(maxx, t - c); //不断试探是否有新的最大值出现
		c = min(t, c);  //不断更新最低点
	}
	printf("%lld", maxx);
}
