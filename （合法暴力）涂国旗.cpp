#include <iostream>  
#include <algorithm>  
using namespace std;
string a[55];
int w[55], b[55], r[55];
int main()
{
    int m, n;
    cin >> n >> m;
    int i, j, k;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        for (j = 0; j < m; j++) {
            if (a[i][j] != 'W') w[i]++;
            if (a[i][j] != 'B') b[i]++;
            if (a[i][j] != 'R') r[i]++;
        }
    }
    int sum, min = 9999;
    for (i = 1; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                if (k < i) sum += w[k];
                else if (k < j) sum += b[k];
                else sum += r[k];
            }
            if (sum < min) min = sum;
        }
    }
    cout << min;
}




