#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
char a[2005], b[2005];
int a1[2005], b1[2005], c1[4000];
int main()
{
	int i, j;
	scanf("%s %s", a, b);
	int l1 = strlen(a), l2 = strlen(b);
	for (i = 0; i < l1; i++) a1[l1 - 1 - i] = a[i] - '0';
	for (i = 0; i < l2; i++) b1[l2 - 1 - i] = b[i] - '0';
	for (i = 0; i < l2; i++) {   //b
		for (j = 0; j < l1; j++) {  //a
			c1[j + i] += a1[j] * b1[i];
			if (c1[j + i] >= 10) {
				int t = c1[i + j] / 10;
				c1[j + i + 1] += t;
				c1[i + j] %= 10;
			}
		}
	}
	int len = l1 + l2;
	while (c1[len] == 0) len--;
	if (len < 0) putchar('0');
	for (i = len; i >= 0; i--) printf("%d", c1[i]);
}
