#include<iostream>

using namespace std;

//������������ķ�ʽ������һ��ˮ����Χ�����еص㣬��ˮ�ӱ�Ϊ�յ�
void dfs(char field[][101], int i, int j, int N, int M)
{
	//��ˮ�ӱ�Ϊ�յ�
	field[i][j] = '.';

	//����8������
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
	//��������ˮ�ӣ��е�ˮ�ӻ���DFS���������ںϲ�����Ҫ����дΪ�յ�
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if(field[i][j] == 'W')
			{
				//ʹ��DFS����һ��ˮ�ӣ�����������ˮ��
				dfs(field, i, j, N, M);
				lake++;
			}

	cout << lake << endl;

	return 0;
}