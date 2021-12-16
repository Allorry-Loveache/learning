#define _CRT_SECURE_NO_WARNINGS 1
int factorsum(int number) {  //ÇóÒ»¸öÊýµÄÒò×ÓºÍ
	int sum = 1;
	if (number == 1) return 0;
	for (int i = 2; i <= number / i; i++)
		if (number % i == 0) {
			sum += i;
			if (i != number / i)
				sum += number / i;
		}
	return sum;
}
void PrintPN(int m, int n) {
	int flag = 0, i, j;
	for (i = m; i <= n; i++) {
		if (i == factorsum(i)) {
			flag = 1;
			printf("%d = 1", i);
			for (j = 2; j <= i / 2; j++)
				if (i % j == 0)
					printf(" + %d", j);
			printf("\n");
		}
	}
	if (!flag) printf("No perfect number");
}
