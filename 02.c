#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int a[401][401];           //三目运算符做法
//int n, sum;
//int main()
//{
//	int flag = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	    for (int j = 1; j <= n; j++)
//		scanf("%d", &a[i][j]);
//	for (int i = 1; i <= n; i++)
//	    for (int j = 1; j <= n; j++){
//		int u = i == 1 ? n : i - 1;
//		int d = i == n ? 1 : i + 1;
//		int l = j == 1 ? n : j - 1;
//		int r = j == n ? 1 : j + 1;
//		sum += a[i][j];
//		if (a[i][j] > a[u][j] + a[d][j] + a[i][l] + a[i][r]){
//		    printf("%d %d\n", i - 1, j - 1);
//		    flag = 1;
//		}
//	    }
//	if (!flag) printf("None! %d\n", sum);
//	return 0;
//}


#include <stdio.h>   //矩阵平移思想
int a[401][401];
int n, sum;
int main()
{
	int flag = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			sum += a[i][j];
			if (a[i][j] > a[(i + n - 2) % n + 1][j] + a[(i + n + 1) % n][j] +
				a[i][(j + n + 1) % n] + a[i][(j + n - 2) % n + 1])
			{
				printf("%d %d\n", i - 1, j - 1);
				flag = 1;
			}
		}
	if (!flag) printf("None! %d\n", sum);
	return 0;
}
