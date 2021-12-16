#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define m 10000
int a[m + 1];
int main() {       //先存储范围内所有完数
	a[1] = 0;
	for (int i = 2; i <= 10000; i++) {
		int sum = 1;
		for (int j = 2; j * j <= i; j++)
			if (!(i % j)) {
				sum += j;
				if (i != j * j) sum += i / j;
			}
		if (sum == i) a[i] = 1;
	}
	int n;
	while (scanf("%d", &n) != EOF) { //文件尾
		int flag = 1;
		printf("%d:", n);
		for (int i = 1; i <= n; i++)
			if (a[i]) {
				printf(" %d", i);
				flag = 0;
			}
		if (flag) printf(" NULL");
		puts("");
	}
}
