#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int W, H;
char room[20][21];
int sx, sy;
bool arrive[20][20];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int BFS();
int DFS();

int main()
{
	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				cin >> room[i][j];
				if (room[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		 
		//int ans = BFS();
		int ans = DFS();
		cout << ans << endl;
	}
	
	return 0;
}

