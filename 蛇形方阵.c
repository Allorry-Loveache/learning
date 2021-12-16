#include<stdio.h>
int a[10][10];
int main()
{
	int n, i=1, j=0,k=1;
	scanf("%d",&n);
	while (k <= n * n) {
		while (j < n&&!a[i][j+1])  a[i][++j] = k++; 
		while (i < n&&!a[i+1][j])  a[++i][j] = k++; 
		while (j > 1&&!a[i][j-1])  a[i][--j] = k++; 
		while (i > 1&&!a[i-1][j])  a[--i][j] = k++;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%3d", a[i][j]);
		puts(" ");
	}
}
