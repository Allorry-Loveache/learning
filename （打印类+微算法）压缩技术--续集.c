#include <stdio.h>
#include<string.h>
char a[40500],b[205];
int main()
{
	int i, j, count = 0; char t = '0'; //设置‘0’
	gets(b);
	int l = strlen(b);   //必须先输入一个串，了解长度
	strcat(a, b);
	for (i = 2; i <= l; i++) {
		scanf("%s", b);
		strcat(a, b);   //全部穿在一个字符串数组里
	}
	printf("%d ", l);   //先输出长度
	for (i = 0; i <= l*l; i++) {
		if (a[i] == t) count++;  //if else 控制交替
		else {
			t = a[i];
			printf("%d ", count);
			count = 1;
		}
	}
}
