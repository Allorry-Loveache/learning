#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>                   
int prime(int n) {                       //判断素数
	if (n == 1)
		return 0;
	if (n % 2 == 0)
		return 0;
	else {
		int i;
		for (i = 3; i * i <= n; i += 2) {
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}
int hw(int n) {
	int sum = 0;                    //判断回文数
	int k = n;
	while (n != 0) {
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	if (sum == k)
		return 1;
	else
		return 0;
}
int main() {
	int i, n, sum = 0, m;
	scanf("%d %d", &n, &m);
	for (i = n; i <= m; i++) {
		if (i == 9989900)           //一亿内最大的回文数
			break;
		if (hw(i) && prime(i))
			printf("%d\n", i);
	}
	return 0;
}