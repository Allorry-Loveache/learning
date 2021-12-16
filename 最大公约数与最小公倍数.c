#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int m, n, d, temp;
    scanf("%d %d", &m, &n);
    int x = m, y = n;
    while (n > 0) {
        d = m % n;                       //辗转相除法，永远的经典
        m = n;
        n = d;
    }
    printf("%d %d", m, x * y / m);        //  x*y/m
}
