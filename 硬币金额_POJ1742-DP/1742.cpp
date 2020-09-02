//#include<iostream>
//
//using namespace std;
//
//int n, m;
//int coin[100];
//int coinnum[100];
//int dp[100001][2];
//
//int main()
//{
//	while (true)
//	{
//		cin >> n >> m;
//		if (n == 0 && m == 0)
//			break;
//
//		for (int i = 0; i < n; i++)
//			cin >> coin[i];
//		for (int i = 0; i < n; i++)
//			cin >> coinnum[i];
//
//		for (int i = 1; i <= m; i++)
//			for (int j = 0; j <= 1; j++)
//				dp[i][j] = 0;
//
//		dp[0][0] = 1;
//		dp[0][1] = 1;
//
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				if (j < coin[i - 1])
//					dp[j][1] = dp[j][0];
//				else
//				{
//					for (int k = 0; k <= coinnum[i - 1] && j >= k * coin[i - 1]; k++)
//						dp[j][1] += dp[j - k * coin[i - 1]][0];
//				}
//			}
//			for (int j = 0; j <= m; j++)
//			{
//				dp[j][0] = dp[j][1];
//			}
//		}
//
//		int count = 0;
//		for (int i = 1; i <= m; i++)
//		{
//			if (dp[i][1] > 0)
//				count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}