#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//也可以使用结构体
typedef pair<int, int> loc;
typedef pair<loc, int> P;
int M;
bool ground[304][304] = { false };		//被陨石击中损坏的所有地点，标注安全地点
bool temp[304][304] = { false };		//在某一个时刻被陨石击中的所有地点，随时间更新，标注暂时安全的地点
bool arrive[304][304] = { false };		//标注已达地点
P meteor[50000];						//所有的陨石的信息
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

//用于帮助sort函数排序
bool cmp(P a, P b)
{
	return a.second < b.second;
}

//使用BFS求出最短的步数
int BFS()
{
	int cur = 0;
	int ans = -1;
	//初始化把起点加入队列
	queue<P> que;
	que.push(P(loc(0, 0), 0));
	arrive[0][0] = true;

	while (que.size())
	{
		//从队列中取出一个位置
		P p = que.front();
		que.pop();
		//判断是否是安全地点
		if (!ground[p.first.first][p.first.second])
		{
			ans = p.second;
			break;
		}

		//不是安全地点，则更新陨石信息，用于下一步动作
		//更新暂时安全地点，新考虑的陨石的坠落时间比当前时刻至多大1
		while (p.second >= meteor[cur].second - 1)
		{
			temp[meteor[cur].first.first][meteor[cur].first.second] = true;
			for (int j = 0; j < 4; j++)
			{
				int nx = meteor[cur].first.first + dx[j];
				int ny = meteor[cur].first.second + dy[j];
				if (nx >= 0 && ny >= 0)
					temp[nx][ny] = true;
			}
			cur++;
		}

		//尝试向四周行走，加入队列
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first.first + dx[i];
			int ny = p.first.second + dy[i];
			//当一个地点是之前没去过且暂时安全的地点时，将其加入队列
			if (!temp[nx][ny] && !arrive[nx][ny] && nx >= 0 && ny >= 0)
			{
				que.push(P(loc(nx, ny), p.second + 1));
				arrive[nx][ny] = true;
			}
		}
	}

	//如果队列空了，则返回默认的不可达到安全地点
	return ans;
}

int main()
{
	cin >> M;
	int x, y, t;
	for (int i = 0; i < M; i++)
	{
		//读取输入
		cin >> x >> y >> t;
		meteor[i] = P(loc(x, y), t);
		//根据陨石信息，更新安全地点
		ground[x][y] = true;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && ny >= 0)
				ground[nx][ny] = true;
		}
	}
	//对陨石按照坠落时间排序
	sort(meteor, meteor + M, cmp);

	cout << BFS() << endl;
	return 0;
}

