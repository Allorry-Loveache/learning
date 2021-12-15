#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
    double   x1, y1, x2, y2, x3, y3;
    double l;
    double s;
    double p;
    double a, b, c;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    b = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    c = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    if (a - b >= c || a + b <= c)
        printf("Impossible");
    else
    {
        l = a + b + c;
        p = l / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("L = %.2lf, A = %.2lf", l, s);
    }
    return 0;
}
