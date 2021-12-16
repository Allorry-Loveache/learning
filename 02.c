#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int i, j, n, a[10][10], col[10];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {     //存入矩阵，同时找出每一行的最大值
        int t = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][t] <= a[i][j])  t = j;
        }
        col[i] = t;           //最大值存入新数组
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (a[i][col[i]] > a[j][col[i]])
                break;       //判断行最大值是否还是列最大值
        if (j == n) {
            printf("%d %d", i, col[i]);
            return 0;
        }
    }
    printf("NONE");
    return 0;
}