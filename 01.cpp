


#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
//int w[35], v[35];  //weight and value
//int dp[35][205];   //�ֲ���ѷ������������value
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
//	for (int i = 1; i <= n; i++) {   //������Ϊ�������
//		for (int j = 1; j <= m; j++) {  //������Ϊ��������
//			if (w[i] > j) dp[i][j] = dp[i - 1][j]; //�Ų���
//			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//			/*   �ŵ��£�Ҫ��Ҫ���ò��÷š�   j - w[i] ��ʾ�Ž�ȥ���ʣ������,
//			�����ʣ����������ѷ����Ѿ�����dp���ˡ� */
//			//dp[i-1][j]��ʾ����������֮ǰ����ѷ�����
//            //���磬����1 3�������ǲ��Ǳ�����4�ļ�ֵ����
//		}
//	}
//	//���dp���仯
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << dp[n][m]; //���մ�
//}



//����������ʽ
int w[35], v[35], dp[205];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++) {  // �������
		for (int j = m; j > 0; j--) {  //��������
			//Ϊ�˷�ֹ��ǰ�ߵ����ݸ��ǵ���Ҫ�Ӻ���ǰ��
			if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m];
}




��ȫ������֮����ÿ����������嶼�����޸�

////��ȫ����--�����㷨
//int w[35], v[35], dp[205];
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
//	for (int i = 1; i <= n; i++)   // �������
//		for (int j = m; j > 0; j--)   //��������
//			for (int k = 0; k <= j / w[i]; k++)
//				//�������ǼӲ��������壬�������ϼӶ��ٸ�
//				dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
//
//	cout << dp[m];
//}


//�Ż���ʽ
int w[35], v[35], dp[205];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++)   // �������
		for (int j = w[i]; j <= m; j++)  //˳��ֱ�Ӵ���װ��ʱ��ʼ��
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	/*dp[j - w[i]]��װ����������ʣ����������Ӧ�Ѿ����ڵ���ѷ�����
	�벻�������������Ƚ�*/
	cout << dp[m];
}