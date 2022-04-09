// #include<iostream>
// #include<cstdio>
// using namespace std;
// const int maxn = 10000 + 10;
// int n, m, a[maxn], flag, flagx;
// bool b[maxn];
// void dfs(int step)
// {
//     if (flagx == 1)
//         return;
//     if (step > n)
//     {
//         flag++;
//         if (flag == m + 1)//现在到了我们要加上的那个数的全排列的时候，我们就直接地输出，然后标记flagx，一直return，结束程序
//         {
//             for (int j = 1; j <= n; j++)
//                 printf("%d ", a[j]);
//             printf("\n");
//             flagx = 1;
//         }
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (flag == 0)i = a[step];//当还在外星人给出的排列这个阶段的时候，我们就直指外星人给出的序列中的数    
//         if (b[i] == 0)
//         {
//             b[i] = 1;
//             a[step] = i;
//             dfs(step + 1);
//             b[i] = 0;
//         }
//     }
// }
// int main()
// {
//     scanf("%d %d", &n, &m);
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &a[i]);
//     dfs(1);
//     return 0;
// }


#include <iostream>  
#include <algorithm>  
using namespace std;
inline int read()
{
    int re = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { re = re * 10 + (ch - '0'); ch = getchar(); }
    return re * f;
}
int main()
{
    int num[10005];
    int n, m, f = 0;
    n = read(); m = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    do {
        if (f == m) {
            for (int i = 1; i <= n; i++) printf("%d ", num[i]);
            break;
        }
        f++;
    } while (next_permutation(num + 1, num + n + 1));
    return 0;
}
