#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;

        int n = costs.size();
        int a[n][3];
        a[0][0] = costs[0][0];
        a[0][1] = costs[0][1];
        a[0][2] = costs[0][2];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                int minn = 1000000;
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    minn = min(costs[i][j] + a[i - 1][k], minn);
                }
                a[i][j] = minn;
            }
        }
        int ans = (a[n - 1][0] < a[n - 1][1]) ? (a[n - 1][0] < a[n - 1][2]) ? a[n - 1][0] : a[n - 1][2]
            : (a[n - 1][1] < a[n - 1][2]) ? a[n - 1][1] : a[n - 1][2];
        return ans;
    }
};
