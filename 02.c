#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int m, n, d, temp;
    scanf("%d %d", &m, &n);
    int x = m, y = n;
    while (n > 0) {
        d = m % n;                       //շת���������Զ�ľ���
        m = n;
        n = d;
    }
    printf("%d %d", m, x * y / m);        //  x*y/m
}
