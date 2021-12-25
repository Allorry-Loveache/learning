
#include <stdio.h>
#include<string.h>
#define MAXN 101
char s[MAXN], in[MAXN];
int main()
{
	int n;
	scanf("%d\n%s", &n, s);
	for (int i = 1; i <= n; i++) {
		int opt;
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%s", in);
			strcat(s, in);   //直接接上，输出
			printf("%s\n", s);
		}
		else if (opt == 2) {
			int a, b;
			scanf("%d %d", &a, &b);
			s[a + b] = '\0';  //设置断点a+b位置
			strcpy(in, &s[a]);//从a开始复制到断点停止
			strcpy(s, in);    //把替代品复制回正品
			printf("%s\n", s);
		}
		else if (opt == 3) {
			int a;
			scanf("%d %s", &a, in);//接收片段
			strcat(in, &s[a]);//把a往后的元素接到片段后边
			s[a] = '\0';      //设置断点，为strcat提供起始点
			strcat(s, in);    //接回来
			printf("%s\n", s);
		}
		else if(opt == 4){
			scanf("%s", in);
			char* ans = strstr(s, in);   //ans指向in第一次在s出现的位置
			if (ans != NULL) {
				printf("%d\n",(ans - s));//减法算出距离
			}                            //指针减法是（相隔字节数/权重）
			else {
				printf("%d\n", -1);
			}
		}
	}
	return 0;
}
