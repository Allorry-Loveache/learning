#include<stdio.h>
int b[100];
int main()
{                                   //汤姆的赚钱之旅
	int i, count = 0;  char input; 
	for (i = 0; i < 100; i++)  b[i] = 1; //杰瑞默认每天都出来，数组初始化为1
	for(i=0;;i++) {
		input=getchar();
		if (input == '$') break;
		if (b[i]) {     //核心是看杰瑞是否出来，而且明确知道第一天必出
			if (input=='T') {  //哟，小老弟，来尝尝啊？
				count += 7;    //赔了一个奶酪，赚了一个杰瑞，折合7块
				if (b[i + 1] != 2) b[i + 1] = 0; //不是极度兴奋的话，就进入伤心期
				if (b[i + 2] != 2) b[i + 2] = 0;
				putchar('D');
			}
			else if (input == 'C') { //纯放奶酪，汤姆放长线钓大鱼
				count -= 3;          //真香，-3￥
				b[i + 1] = b[i + 2] = 2;  //吃到了，好兴奋呢~，下次还来
				putchar('!');
			}
			else if (input == 'X') {   //啥都没有，杰瑞白跑一趟，不开心呢~
				putchar('U');
				if (b[i + 1] != 2) b[i + 1] = 0;//不在兴奋期就不开心期
			}
		}
		else putchar('-'); //我心爱的杰瑞，你为什么躲着我？
	}
	puts("");
	printf("%d", count);
}
