void CountOff(int n, int m, int out[])
{
    int a[MAXN] = { 0 }, count = 1, index = 1,i;
    while(n+1-count)
    for (i = 0; i < n; i++) 
        if (a[i] != 1) 
            if (index % m == 0) {
                out[i] = count++;
                a[i] = 1;
                index = 1;
            }
            else index++;
}
