#include<iostream>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1e9 + 7;
int len, a[5005], minn = 0xffff, maxx = 0;
signed main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> len;
		a[len]++;
		minn = min(minn, len);
		maxx = max(maxx, len);
	}
	int ans = 0;
	for (int i = minn + 1; i <= maxx; i++) {
		if (a[i] >= 2) {
			for (int j = minn; j <= i / 2; j++) {
				if (a[j] && a[i - j] && j * 2 != i)
					ans += a[i] * (a[i] - 1) / 2 * a[i - j] * a[j] % N;
				else if (a[j] && j * 2 == i)
					ans += a[i] * (a[i] - 1) / 2 * a[j] * (a[j] - 1) / 2 % N;
			}
			ans %= N;
		}
	}
	cout << ans;
}