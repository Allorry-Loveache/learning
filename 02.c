#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int n, i, j, t;
    scanf("%d", &n);
    int a[100];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++)            //ºËÐÄÅÅÐò
        for (j = 0; j < n - i - 1; j++)
            if (a[j] < a[j + 1]) {
                t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
    printf("%d", a[0]);
    for (i = 1; i < n; i++)
        printf(" %d", a[i]);
}
