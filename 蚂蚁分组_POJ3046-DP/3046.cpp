#include<iostream>
#include<algorithm>

using namespace std;

int ant_num = 0;
int family_num = 0;
int ant_family[1000];
int lowbound, upbound;
int dp[1001][100001];

int main()
{
	cin >> family_num >> ant_num >> lowbound >> upbound;
	for (int i = 0, tmp = 0; i < ant_num; i++)
	{
		cin >> tmp;
		ant_family[tmp - 1]++;
	}

	for (int i = 0; i <= family_num; i++)
		dp[i][0] = 1;

	for (int i = 0; i < family_num; i++)
	{
		for (int j = 1; j <= ant_num; j++)
		{
			if (j - 1 - ant_family[i] >= 0)
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - ant_family[i]] + 1000000) % 1000000;
			else
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % 1000000;
		}
	}

	int ans = 0;
	for (int i = lowbound; i <= upbound; i++)
		ans += dp[family_num][i];

	ans %= 1000000;
	cout << ans % 1000000;

	return 0;
}