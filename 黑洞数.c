#include<stdio.h>
int main()
{
	int n = 0, t = 0, a = 0, b = 0, c = 0, j, max = 0, min = 0;
	scanf("%d", &n);
	while (n != 495 || t == 0) {       //判断t==0  控制输入495时 进入一次循环
		a = n / 100; b = (n % 100) / 10; c = n % 10;//提取 个 十 百 数位
		if (a < b) { j = a; a = b; b = j; } 
		if (a < c) { j = a; a = c; c = j; }
		if (b < c) { j = b; b = c; c = j; }   //排序
		max = a * 100 + b * 10 + c;
		min = c * 100 + b * 10 + a;       
		n = max - min;
		printf("%d: %d - %d = %d\n", ++t, max, min, n);
	}
	return 0;
}
//无论你如何组合，你终将属于我，因为我是你唯一的495
