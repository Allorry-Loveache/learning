#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int a[10];
	int i, j, k, count = 0;
	while (cin >> a[count]) {
		count++;
	}
	for (int z = 0; z < count; z++) {
		int n = a[z];
		vector< vector<int> >vv;
		for (i = 1; i <= n; i++) {
			vv.push_back(vector<int>(i, 1));
		}
		for (i = 2; i <= n - 1; i++) {
			for (j = 0; j <= i - 1 - 1; j++) {
				vv[i][j + 1] = vv[i - 1][j] + vv[i - 1][j + 1];
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n - i - 1; j++) {
				cout << "  ";
			}
			for (k = 0; k <= i; k++) {
				//printf("%-4d", vv[i][k]);
				cout << setw(4) << left << vv[i][k];
			}
			puts("");
		}
		puts("");
	}
}

