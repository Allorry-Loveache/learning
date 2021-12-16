#include<stdio.h>
int main()
{
    int n,m, i,j,a[30],b[30],c[30],t=1,k=0;
    scanf("%d", &m);
    for (i = 0; i < m; i++)  scanf("%d", &a[i]);
    scanf("%d", &n);
    for (j = 0; j < n; j++)  scanf("%d", &b[j]);
    for (i = 0; i < m; i++) {           //a[i]开始与b[i]逐个对比
	t = 1;                          //筛选出，用c[k]记录
	for (j = 0; j < n; j++)         //t起flag的作用，用来判断（方法之一）
	    if (a[i] == b[j]) {
		t = 0; break;
	    }
	if (t) 
	    c[k++] = a[i];
    }
    for (j = 0; j < n; j++) {          //b[i]与a[i]逐个对比
	t = 1;
	for (i = 0; i < m; i++)
	    if (b[j] == a[i]) {
		t = 0; break;
	    }
	if (t) 
	    c[k++] = b[j];
    }
    printf("%d", c[0]);     //先打出第一个，防止行末空格
    for(i=1;i<k;i++){
	for(j=0;j<i;j++)
	    if(c[i]==c[j])    
		break;
	if(j==i)
	    printf(" %d",c[i]);
    }

}

// 变式：按给出数字顺序输出
//     两个数组里全都不重复的元素

//#include <stdio.h>
//int a[30], b[30], c[110];
//int main()
//{
//    int n, m, i, j, k = 0;
//    scanf("%d", &m);
//    for (i = 0; i < m; i++) {
//        scanf("%d", &a[i]); 
//        c[a[i]]++;
//    }
//    scanf("%d", &n);
//    for (j = 0; j < n; j++) {
//        scanf("%d", &b[j]);
//        c[b[j]]++;
//    }
//    for (i = 0; i < m; i++) 
//        if (c[a[i]] == 1) printf("%d ", a[i]);
//    for (j = 0; j < n; j++)
//        if (c[b[j]] == 1) printf("%d ", b[j]);
//}
