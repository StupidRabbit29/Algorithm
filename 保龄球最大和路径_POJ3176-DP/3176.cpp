#include<iostream>

using namespace std;

int N = 0;
int bowling[350][350];
int dp[350][350];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> bowling[i][j];

	for (int i = 0; i < N; i++)
		dp[N - 1][i] = bowling[N - 1][i];

	if (N == 1)
	{
		cout << dp[0][0] << endl;
		return 0;
	}
	
	for (int i = N - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			dp[i][j] = bowling[i][j] + (dp[i + 1][j] > dp[i + 1][j + 1] ? dp[i + 1][j] : dp[i + 1][j + 1]);

	cout << dp[0][0] << endl;
	return 0;
}