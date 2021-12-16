
void ArrayShift(int *a, int n, int m) {
    m = m % n; int b[MAXN];
    int i;
    for (i = 0; i < n; i++)
        b[(i + m) % n] = a[i];  //位移公式
    for (i = 0; i < n; i++)
        a[i] = b[i];   
}
