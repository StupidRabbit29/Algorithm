#include<iostream>
#include<queue>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

const int INF = 100000000;
//ʹ��pair��ʾ״̬ʱ����typedef���ӷ���
typedef pair<int, int> P;

char maze[MAX_N][MAX_M + 1];		//�Թ���ͼ
int N, M;
int sx, sy;							//�������
int gx, gy;							//�յ�����
int d[MAX_N][MAX_M];				//��㵽����λ�õ���̾���

//����4���ƶ��ķ���
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

//����㵽�յ����̾��룬���޷��������INF
int bfs()
{
	queue<P> que;
	//��ʼ��
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			d[i][j] = INF;
	//�����������
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	//����ѭ��ֱ�����г���Ϊ0
	while (que.size())
	{
		//ȡ�����п�ͷ��Ԫ��
		P p = que.front();
		que.pop();
		//����Ѿ������յ㣬�����
		if (p.first == gx && p.second == gy)
			break;
		//����4�����򣬽����ƶ��ķ���������
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			//�ж��Ƿ���Գ���������ƶ������Ƿ��ƶ���
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
