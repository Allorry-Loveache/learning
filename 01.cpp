


#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
//int w[35], v[35];  //weight and value
//int dp[35][205];   //局部最佳方案，储存最大value
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
//	for (int i = 1; i <= n; i++) {   //纵坐标为物体序号
//		for (int j = 1; j <= m; j++) {  //横坐标为背包容量
//			if (w[i] > j) dp[i][j] = dp[i - 1][j]; //放不下
//			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//			/*   放的下，要就要看该不该放。   j - w[i] 表示放进去后的剩余容量,
//			而这个剩余容量的最佳方案已经存在dp中了。 */
//			//dp[i-1][j]表示放入新物体之前的最佳方案。
//            //比如，质量1 3的俩，是不是比质量4的价值更大？
//		}
//	}
//	//输出dp看变化
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << dp[n][m]; //最终答案
//}



//滚动数组形式
int w[35], v[35], dp[205];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++) {  // 物体序号
		for (int j = m; j > 0; j--) {  //背包容量
			//为了防止把前边的数据覆盖掉，要从后往前推
			if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m];
}




完全背包与之区别：每个种类的物体都是无限个

////完全背包--朴素算法
//int w[35], v[35], dp[205];
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
//	for (int i = 1; i <= n; i++)   // 物体序号
//		for (int j = m; j > 0; j--)   //背包容量
//			for (int k = 0; k <= j / w[i]; k++)
//				//不仅考虑加不加新物体，还考虑上加多少个
//				dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
//
//	cout << dp[m];
//}


//优化形式
int w[35], v[35], dp[205];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++)   // 物体序号
		for (int j = w[i]; j <= m; j++)  //顺序，直接从能装下时开始找
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	/*dp[j - w[i]]是装入新物体后的剩余容量，对应已经存在的最佳方案，
	与不放入新物体作比较*/
	cout << dp[m];
}