#include<stdio.h>
int a[20001],c[20001],b[101];
int main()
{
	int i, j, n,count=0,t=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &b[i]);  //b存储输入值
		c[b[i]] = 1;    //c判断输入值存在与否
		if (t < b[i]) t = b[i];  //存储最大的输入值
	}
	for (i = 1; i < n; i++) 
		for (j = 1 + i; j <= n; j++) 
			a[b[i] + b[j]]=1;  //a判断所有的两个数相加之和
	for (i = 1; i <= t; i++)
		if (a[i] && c[i]) count++; //相加之和与输入值都存在，表示相等
	printf("%d", count);
}
//注： a 与 c 的存储方式相同，数字作为“元素”，出现与否作为“值”
