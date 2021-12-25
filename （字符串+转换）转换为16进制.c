

void f(long int x, char* p) {
    int d, i=0, flag = 0; char k[MAXN];  //k存储倒序的整数
    if (x == 0) *p = '0';             //参考10转16进制
    if (x < 0) {
        x *= -1; flag = 1;
    }                             
    while (x > 0) {
        d = x % 16; 
        x /= 16;
        if (d <= 9) k[i++] = '0' + d;
        else k[i++] = 'A' + (d - 10);
    }  k[i] = '\0';                      //千万别忘了添断点
    for (i = strlen(k)-1; i >= 0; i--)
        *p++ = k[i];
    if (flag) printf("-");
}
