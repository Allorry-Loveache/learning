如果给你N个数，让你相加呢？

//版本1，一劳永逸，一次全部加起来
#include<iostream>
using namespace std;
string str[50];
int a[50][200];
int main()
{
	int n,i,j,len,maxx=0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str[i];
		len = str[i].size();
		maxx = max(maxx, len);
		for (j = 0; j < len; j++) a[i][len-1-j] = str[i][j] - '0';
	}
	for (j = 0; j < maxx; j++) 
		for (i = 1; i < n; i++) 
			a[0][j] += a[i][j];
	for (j = 0; j < maxx; j++) {
		if (a[0][j] >= 10) {
			a[0][j + 1] += a[0][j] / 10;
			a[0][j] %= 10;
			if (a[0][maxx] > 0) maxx++;
		}
	}
	for (j = maxx - 1; j >= 0; j--) cout << a[0][j];
}




//版本2，逐个击破，适用于与动态规划结合
#include<iostream>
using namespace std;
string str;
int a[200], b[200];
int main()
{
	int n, len1, len2, i;
	cin >> n;
	cin >> str;
	len1 = str.size();
	for (i = 0; i < len1; i++) a[len1 - 1 - i] = str[i] - '0';
	n--;

	while (n--) {
		cin >> str;
		len2 = str.size();
		len1 = max(len1, len2);
		for (i = 0; i < len2; i++) b[len2 - 1 - i] = str[i] - '0';

		for (i = 0; i < len1; i++) a[i] += b[i];
		for (i = 0; i < len1; i++) {
			if (a[i] >= 10) {
				a[i + 1] += a[i] / 10;
				a[i] %= 10;
				if (a[len1] > 0) len1++;
			}
		}
	}
	for (i = len1 - 1; i >=0; i--) cout << a[i];
}