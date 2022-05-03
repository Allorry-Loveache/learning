#include <stdio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#define 刘浩然 250
enum input {
	EXIT,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
};
int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
int divide(int a, int b) {
	return a / b;
}
void menu() {
	printf("\n******************************\n");
	printf("*** 0. 退出 * 1. 加法 ********\n");
	printf("*** 2. 减法 * 3. 乘法 ********\n");
	printf("*** 4. 除法 ******************\n");
	printf("****** 输其他的给爷爬 ********\n\n");
}
void unit(int (*p)(int, int)) {
	while (1) {
		menu();
		printf("input your choice\n");
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("ok,get out here\n"); break;
		}
		else if (n < 0 || n >= 5) {
			printf("godie\n");
			continue;
		}
		printf("input your numbers\n");
		int a, b;
		scanf("%d %d", &a, &b);
		int answer = 0;
		switch (n) {
		case EXIT:break;
		case ADD:
			p = add; answer = p(a, b); break;
		case SUBTRACT:
			p = subtract; answer = p(a, b); break;
		case MULTIPLY:
			p = multiply; answer = p(a, b); break;
		case DIVIDE:
			p = divide; answer = p(a, b); break;
		}
		printf("%d\n", answer);
	}
}
int main()
{
	int (*p)(int, int) = NULL;
	unit(p);
	return 0;
}
