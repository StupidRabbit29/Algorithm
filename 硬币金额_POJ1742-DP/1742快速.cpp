#include<iostream>

using namespace std;

int n, m;
int coin[102];
int coinnum[102];
int dp[100002];
int used[100002];

int main()
{
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> coin[i];
		for (int i = 0; i < n; i++)
			cin >> coinnum[i];

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			memset(used, 0, sizeof(used));
			for (int j = coin[i]; j <= m; j++)
			{
				if (!dp[j] && dp[j - coin[i]] && used[j - coin[i]] < coinnum[i])
				{
					dp[j] = 1;
					used[j] = used[j - coin[i]] + 1;
					ans += 1;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}