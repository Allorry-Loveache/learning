#include <stdio.h>
int  b[40500];
int main()
{
	int i, j, n,count=0,d,t=1,flag=1;
	scanf("%d", &n);
	while (count < n * n) {
		scanf("%d", &d);
		count += d;   
		if (!flag) {   //让count在前，t去追赶
			for(j=t;j<=count;j++)  
			    b[j] = 1;  //先标记，之后统一打印
			flag = 1;
		}    //flag用于切换状态，搭配if else使用
		else flag = 0;
		t += d;  //t追上count，开启下一轮追赶
	}
	for (i = 1; i <= n * n; i++) {
		printf("%d", b[i]);
		if (!(i % n)) puts("");  //空行
	}
}
