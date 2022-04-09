
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <algorithm>  
#include<cmath>
using namespace std;
struct nums {
	int x;
	int y;
}a[200005];
bool cmp(nums a, nums b) {
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
double dis(double a, double b, double c, double d) {
	return sqrt(abs(c - a) * abs(c - a) + abs(d - b) * abs(d - b));
}
int main()
{
	int n, i;
	double t, ans = 999999999;
	cin >> n;
	for (i = 0; i < n; i++)  scanf("%d %d", &a[i].x, &a[i].y);
	sort(a, a + n, cmp);
	for (int i = 2; i <= n; i++)ans = min(ans, dis(a[i].x, a[i].y, a[i - 1].x, a[i - 1].y));
	for (int i = 3; i <= n; i++)ans = min(ans, dis(a[i].x, a[i].y, a[i - 2].x, a[i - 2].y));
	for (int i = 4; i <= n; i++)ans = min(ans, dis(a[i].x, a[i].y, a[i - 3].x, a[i - 3].y));
	printf("%.4f", ans);
}
