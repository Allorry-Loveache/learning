
#include <stdio.h>
char a[100];
int main()
{
	int i;
	gets(a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= '0' && a[i] <= '9' || a[i] == '.') {  
			if (a[i + 1] >= '0' && a[i + 1] <= '9' || a[i+1]=='.') putchar(a[i]);
			else printf("%c\n", a[i]);   //不满足条件，不是一个数字，输出完自己 就直接换行
		}
		else if (a[i] == '-' || a[i] == '+') {  //特判带符号的数字-1，他们出现在（）里，以及开头
			if (a[i - 1] == '(' || i == 0) putchar(a[i]);
			else printf("%c\n", a[i]);
		}
		else printf("%c\n", a[i]);
	}
}
