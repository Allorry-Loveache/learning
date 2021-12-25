
#include <stdio.h>
int main()
{
	int n, i, j, k, count = 0, t=0;
	scanf("%d", &n);
	for (i = 0; i <= n / 5; i++)
		for (j = 0; j <= n / 3; j++)
			for (k = 0; k <= n; k++)
				if (5 * i + 3 * j + k == n && i + j + 3 * k == n) {
					count++;
					t += i;
					break;
				}
	if (count)
		printf("%d %d", count, t);
	else printf("0 -1");
}
 
