
#include<stdio.h>
int prime(int n) {
	int i;
	if (n <=1 ) return 0;  //排除1 0 负数
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (i = 3; i * i <= n; i += 2)
		if (n % i == 0) return 0;
	return 1;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = ++n;; i++) {
		if (prime(i) && prime(i + 2)) {
			printf("%d %d", i, i + 2); break;
		}
	}
}
