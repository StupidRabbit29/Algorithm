#include<iostream>
#include<stack>

using namespace std;

extern int W, H;
extern char room[20][21];
extern int sx, sy;
extern bool arrive[20][20];
extern int dx[4], dy[4];

typedef pair<int, int> P;
int DFS()
{
	stack<P> sta;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			arrive[i][j] = false;
	arrive[sx][sy] = true;
	sta.push(P(sx, sy));
	int ans = 1;

	while (sta.size())
	{
		P p = sta.top();
		sta.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx >= 0 && nx < H && ny >= 0 && ny < W && room[nx][ny] != '#' && arrive[nx][ny] == false)
			{
				sta.push(P(nx, ny));
				arrive[nx][ny] = true;
				ans++;
			}
		}
	}

	return ans;
}