#include<iostream>
#include<queue>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

const int INF = 100000000;
//使用pair表示状态时，用typedef更加方便
typedef pair<int, int> P;

char maze[MAX_N][MAX_M + 1];		//迷宫地图
int N, M;
int sx, sy;							//起点坐标
int gx, gy;							//终点坐标
int d[MAX_N][MAX_M];				//起点到各个位置的最短距离

//设置4个移动的方向
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

//求起点到终点的最短距离，若无法到达，则是INF
int bfs()
{
	queue<P> que;
	//初始化
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			d[i][j] = INF;
	//将起点加入队列
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	//不断循环直到队列长度为0
	while (que.size())
	{
		//取出队列开头的元素
		P p = que.front();
		que.pop();
		//如果已经到达终点，则结束
		if (p.first == gx && p.second == gy)
			break;
		//遍历4个方向，将可移动的方向加入队列
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			//判断是否可以朝这个方向移动，且是否移动过
			if (nx >= 0 && nx <= N && ny >= 0 && ny <= M && maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}

	return d[gx][gy];
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if (maze[i][j] == 'G')
			{
				gx = i;
				gy = j;
			}
		}	

	cout << bfs() << endl;
	return 0;
}

/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/
