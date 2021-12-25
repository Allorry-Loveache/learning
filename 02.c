#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n, m;
	scanf("%d %d", &m, &n);
	n--;
	int t = m;
	while (n--) t *= m;
	printf("%03d", t % 1000);
}
 