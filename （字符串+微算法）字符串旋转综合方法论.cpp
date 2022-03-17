（I）
//思路一： 设左旋字数为n，每次把第一个字符放到最后，其余字符
//往前挪动，重复n次
//注： 指针在涉及循环时慎用++ --，指针早就不知道指哪里去了，
//还循环你个大头鬼啊

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void rotate(char* p, int n) {
	while (n--) {
		char t = *p;
		int l = strlen(p);
		for (int i = 0; i < l - 1; i++)
			*(p + i) = *(p + 1 + i);
		*(p + l - 1) = t;
	}
}
int main()
{
	char a[20] = "abcdefg";
	int n;
	scanf("%d", &n);
	rotate(a, n);
	puts(a);
}


//思路二： 逆序思想。设 abcdefg,左旋2个，先分开：
//ab  cdefg  ，  这两部分同时逆转
//ba  gfedc  ，  再整体合起来一起逆转即可。

#include <stdio.h>
#include <string.h>
void reverse(char* left, char* right) {
	while (left < right) {
		char t;
		t = *left; *left = *right; *right = t;
		left++; right--;
	}
}
int main()
{
	char a[20] = "abcdefg";
	int n;
	int l = strlen(a);
	scanf("%d", &n);
	reverse(a, a + n - 1);
	reverse(a + n, a + l - 1);
	reverse(a, a + l - 1);
	puts(a);
}


（II）给你两个字符串，不停左旋第一个，看看第一个和第二个有希望变的一样吗？

//思路一： 踏踏实实一次一次左旋

#include <stdio.h>
#include <string.h>
void rotate(char* p) {
	char t = *p;
	int l = strlen(p);
	for (int i = 0; i < l - 1; i++)
		*(p + i) = *(p + 1 + i);
	*(p + l - 1) = t;

}
int main()
{
	char a[20] = "abcdefg", b[20] = "abcdefg";
	int l = strlen(a);
	while (l--) {
		rotate(a);
		if (strcmp(a, b) == 0) {
			printf("bingo");
			return 0;
		}
	}
	printf("no");
	return 0;
}


//思路二： abcdefgabcdefg    发现美妙之处了吗？
//此方法请保证 a b 两个字符串的有效长度一样

#include <stdio.h>
#include <string.h>
int main()
{
	char a[20] = "abcdefg", b[20] = "efgabcd";
	strncat(a, a, strlen(a));
	if (strstr(a, b) == NULL) printf("no");
	else printf("bingo");
	return 0;
}


