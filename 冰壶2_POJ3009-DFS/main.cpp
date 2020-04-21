#include<iostream>

using namespace std;

int W, H;
int ground[20][20];
int sx, sy;
int gx, gy;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int DFS(int x, int y, int depth)
{
	//for (int i = 0; i < H; i++)
	//{
	//	for (int j = 0; j < W; j++)
	//		cout << ground[i][j];
	//	cout << endl;
	//}
		
	if (x == gx && y == gy)
		return 0;
	//
	if (depth > 10)
		return -1;

	int ans = 100;
	bool fail = true;
	//����4������
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		//ÿ�������ϱ�����һֱ�ߵ�ͷ
		while (nx >= 0 && nx < H && ny >= 0 && ny < W && ground[nx][ny] != 1 && ground[nx][ny] != 3)
		{
			nx += dx[i];
			ny += dy[i];
		}

		//���������ϰ���
		if (nx >= 0 && nx < H && ny >= 0 && ny < W && ground[nx][ny] == 1 && !(nx == x + dx[i] && ny == y + dy[i]))
		{
			//����ϰ���
			ground[nx][ny] = 0;
			//�Ӹ�λ�ü���DFS
			int temp = DFS(nx - dx[i], ny - dy[i], depth + 1);
			if (temp != -1)
				fail = false;
			if (temp != -1 && temp + 1 < ans)
				ans = temp + 1;
			//�ָ��ϰ���
			ground[nx][ny] = 1;
		}
		
		//�ִ��յ�
		if (nx >= 0 && nx < H && ny >= 0 && ny < W && ground[nx][ny] == 3)
		{
			fail = false;
			if (ans > 1)
				ans = 1;
		}
	}

	//����ڸ�λ���޷��ҵ���·���򷵻�-1�����򷵻���Ҫ�ߵ��յ�Ĳ���
	if (fail)
		return -1;
	else
		return ans;
}

int main()
{
	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		//��ȡ���룬�궨�����յ�
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				cin >> ground[i][j];
				if (ground[i][j] == 2)
				{
					sx = i;
					sy = j;
				}
				else if (ground[i][j] == 3)
				{
					gx = i;
					gy = j;
				}
			}

		int ans = DFS(sx, sy, 1);
		cout << ans << endl;
	}

	return 0;
}