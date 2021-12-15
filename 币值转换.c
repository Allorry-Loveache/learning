#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> //快改姓吧，别跟导员姓了！
int a[9];     //你为啥用指针？你觉得你很NB？
void s(int t, int* a, char* x, char* y) {
	switch (t) {  //十百千万的读法
	case 9:*x = 'Y'; break;
	case 8:case 4:*x = 'Q'; break;
	case 7:case 3:*x = 'B'; break;
	case 6:case 2:*x = 'S'; break;
	case 5:*x = 'W'; break;
	default:*x = NULL; break;
	}
	switch (a[t - 1]) {  //数字读法
	case 0:*y = 'a'; break;
	case 1:*y = 'b'; break;
	case 2:*y = 'c'; break;
	case 3:*y = 'd'; break;
	case 4:*y = 'e'; break;
	case 5:*y = 'f'; break;
	case 6:*y = 'g'; break;
	case 7:*y = 'h'; break;
	case 8:*y = 'i'; break;
	case 9:*y = 'j'; break;
	default:break;
	}
}
int main()
{
	int n, i;   int flag = 1;
	scanf("%d", &n);
	for (i = 0; n > 0; i++) {  //经典倒序存数字
		a[i] = n % 10;
		n /= 10;
	}
	int t = i;     //t代替i去递减，i本身作为数字总位数
	char x = NULL, y = NULL;
	while (t) {  //倒着循环t次           
		s(t, a, &x, &y);   //用指针提取需要的东西 
		/*排除1000读成一千零零零*/
		if ((t == 1 || t == 5) && y == 'a' ||
			t >= 2 && a[t - 1] == 0 && a[t - 2] == 0);  //这时啥都不干 
		else  printf("%c", y);
		/*讨论万位,如1亿不读一亿万*/
		if (t == 5)
			if (i >= 9 && !a[i - 2] && !a[i - 3] && !a[i - 4] && !a[i - 5]);
			else printf("%c", x);
		/*然后，如果数字不是0，就读出来*/
		else if (y != 'a') printf("%c", x);
		t--;
	}
}
