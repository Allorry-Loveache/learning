#include <stdio.h>
int a[100],b[10][10];
int main()
{
    int n, i, j, x = 0, y = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n-1; i++) {
        for (j = i; j < n-1; j++) {
            b[i][j] = a[i] - a[1+j];
            if (b[i][j] < 0) b[i][j] *= -1;
        }
    }
    for (i = 0; i < n; i++)
        for (j = i; j < n-1; j++)
            if (b[x][y] > b[i][j]) {
                    x = i; y = j;
            }
    printf("%d", b[x][y]);
    
}
