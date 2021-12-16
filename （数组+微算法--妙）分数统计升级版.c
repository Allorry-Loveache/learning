

#include<stdio.h>
int a[1001],b[100001]; //a存储同一成绩的人数，
int main()             //b存储1-n每个人的成绩
{
	int n,i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[b[i]]++;
	}
	for (i = 1; i < 1001; i++) 
	//不断累加，来表示比成绩a[i+1]低的总人数
        a[i] += a[i - 1];   
	for (i = 1; i <= n; i++)
    //a[0]是0，不影响a[1]的统计
		if(a[b[i]]) printf("%d ", a[b[i]-1]);
	return 0;
}


