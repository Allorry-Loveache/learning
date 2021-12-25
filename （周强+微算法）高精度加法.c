#include<stdio.h>
#include<string.h>
char s1[10100], s2[10100];
int a[10100], b[10100];
int len;

int main()
{
	int i;
	gets(s1);  int l1 = strlen(s1);
	gets(s2);  int l2 = strlen(s2);
	int l = l1 > l2 ? l1 : l2;
	for (i = 0; i < l1; i++)
		a[l1 - i - 1] = s1[i] - '0';  //倒序方便计算
	for (i = 0; i < l2; i++)
		b[l2 - i - 1] = s2[i] - '0';
	for (i = 0; i < l; i++) {
		a[i] = a[i] + b[i];     //考虑进位等问题
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if (a[l] != 0) l++;
	for (i = l - 1; i >= 0; i--)
		printf("%d", a[i]);
}
