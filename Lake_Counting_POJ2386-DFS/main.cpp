#include<iostream>

using namespace std;

//深度优先搜索的方式来遍历一个水坑周围的所有地点，将水坑变为空地
void dfs(char field[][101], int i, int j, int N, int M)
{
	//将水坑变为空地
	field[i][j] = '.';

	//遍历8个方向
	for (int dx = -1;dx<=1;dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			int nx = i + dx;
			int ny = j + dy;
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && field[nx][ny] == 'W')
				dfs(field, nx, ny, N, M);
		}
	return;
}

int main()
{
	int N, M;
	char field[101][101] = { '\0' };
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> field[i][j];

	int lake = 0;
	//遍历所有水坑，有点水坑会在DFS过程中由于合并的需要被改写为空地
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if(field[i][j] == 'W')
			{
				//使用DFS遍历一个水坑，及其相连的水坑
				dfs(field, i, j, N, M);
				lake++;
			}

	cout << lake << endl;

	return 0;
}