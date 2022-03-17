#include<stdio.h>
int main()
{
	char a[200];
	int n;
	scanf("%d %s", &n, a);
	int i = 0, sum = 0;
	for (i = 0; i < n - 1; i++) {
		if (a[i] == 'V' && a[i + 1] == 'K') {
			a[i] = '1';
			a[i + 1] = '0';
			sum++;
		}
	}
	for (i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			sum++;
			break;
		}
	}
	printf("%d", sum);
}
