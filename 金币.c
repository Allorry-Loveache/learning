#define _CRT_SECURE_NO_WARNINGS 1
// 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5
# include <stdio.h>
int main()
{
    int i, j, k = 1, count = 0, n;
    scanf("%d", &n);
    for (i = 1;; i++)
        for (j = 1; j <= i; j++, k++)
            if (k <= n) count += i;
            else {
                printf("%d", count); return 0;
            }
}
