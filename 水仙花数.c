#define _CRT_SECURE_NO_WARNINGS 1
int narcissistic(int number) {
    int temp = number, count = 0, i, j, a[10], sum, t;
    while (temp > 0) {
        a[count] = temp % 10;
        temp /= 10;          //统计数位，记录数字
        count++;
    }
    sum = 0;
    for (i = 0; i < count; i++) {
        t = 1;
        for (j = 0; j < count; j++)
            t *= a[i];          //乘方
        sum += t;
    }
    if (sum == number) return 1;
    else return 0;
}


void PrintN(int m, int n) {
    int i;
    for (i = m + 1; i < n; i++)
        if (narcissistic(i))
            printf("%d\n", i);
}
