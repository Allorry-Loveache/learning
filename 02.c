#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int i, j, n, a[10][10], col[10];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {     //�������ͬʱ�ҳ�ÿһ�е����ֵ
        int t = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][t] <= a[i][j])  t = j;
        }
        col[i] = t;           //���ֵ����������
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (a[i][col[i]] > a[j][col[i]])
                break;       //�ж������ֵ�Ƿ��������ֵ
        if (j == n) {
            printf("%d %d", i, col[i]);
            return 0;
        }
    }
    printf("NONE");
    return 0;
}