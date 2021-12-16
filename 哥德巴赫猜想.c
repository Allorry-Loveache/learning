int prime(int p) {
    int i;
    if (p == 2) return 1;
    else if (p == 1||p%2==0) return 0;
    for (i = 3; i <= sqrt(p); i+=2) 
        if (p % i == 0) return 0;
    return 1;
}
void Goldbach(int n) {
    int i;
    for (i = 2; i < n; i++) 
        if (prime(i) && prime(n - i)) {   //两个质数同时向中间靠拢
            printf("%d=%d+%d", n, i, n - i);
            break;
        }
}
