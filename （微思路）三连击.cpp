#include<iostream>
using namespace std;
int a[10], b1, b2, b3, l, k1, k2, k3, ans;
int gcd(int a, int b)
{
    int r;
    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    cin >> k1 >> k2 >> k3;    //首先约分
    int good = gcd(k1, (k2, k3));
    k1 /= good, k2 /= good, k3 /= good;
    for (int b = 1; b <= 1000 / k3; ++b)
    {
        b1 = b * k1;//求出三个数
        b2 = b * k2;
        b3 = b * k3;
        if (b2 > 999 || b3 > 999)break;
        for (int c = 1; c <= 3; ++c)//将三个数进行分解，判断是否重复
        {
            a[b1 % 10]++;
            b1 /= 10;
        }
        for (int c = 1; c <= 3; ++c)
        {
            a[b2 % 10]++;
            b2 /= 10;
        }
        for (int c = 1; c <= 3; ++c)
        {
            a[b3 % 10]++;
            b3 /= 10;
        }
        for (int c = 1; c <= 9; ++c)if (a[c] != 1) { l = 1; break; }
        for (int c = 1; c <= 9; ++c)a[c] = 0;   //清空数组，准备下一次
        if (!l) { cout << b * k1 << " " << b * k2 << " " << b * k3 << endl; ans++; }//将解输出，并做标记
        else l = 0;
    }
    if (!ans)cout << "No!!!";//判断无解情况
    return 0;
}
