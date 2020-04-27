#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//Ҳ����ʹ�ýṹ��
typedef pair<int, int> loc;
typedef pair<loc, int> P;
int M;
bool ground[304][304] = { false };		//����ʯ�����𻵵����еص㣬��ע��ȫ�ص�
bool temp[304][304] = { false };		//��ĳһ��ʱ�̱���ʯ���е����еص㣬��ʱ����£���ע��ʱ��ȫ�ĵص�
bool arrive[304][304] = { false };		//��ע�Ѵ�ص�
P meteor[50000];						//���е���ʯ����Ϣ
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

//���ڰ���sort��������
bool cmp(P a, P b)
{
	return a.second < b.second;
}

//ʹ��BFS�����̵Ĳ���
int BFS()
{
	int cur = 0;
	int ans = -1;
	//��ʼ�������������
	queue<P> que;
	que.push(P(loc(0, 0), 0));
	arrive[0][0] = true;

	while (que.size())
	{
		//�Ӷ�����ȡ��һ��λ��
		P p = que.front();
		que.pop();
		//�ж��Ƿ��ǰ�ȫ�ص�
		if (!ground[p.first.first][p.first.second])
		{
			ans = p.second;
			break;
		}

		//���ǰ�ȫ�ص㣬�������ʯ��Ϣ��������һ������
		//������ʱ��ȫ�ص㣬�¿��ǵ���ʯ��׹��ʱ��ȵ�ǰʱ�������1
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

		//�������������ߣ��������
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first.first + dx[i];
			int ny = p.first.second + dy[i];
			//��һ���ص���֮ǰûȥ������ʱ��ȫ�ĵص�ʱ������������
			if (!temp[nx][ny] && !arrive[nx][ny] && nx >= 0 && ny >= 0)
			{
				que.push(P(loc(nx, ny), p.second + 1));
				arrive[nx][ny] = true;
			}
		}
	}

	//������п��ˣ��򷵻�Ĭ�ϵĲ��ɴﵽ��ȫ�ص�
	return ans;
}

int main()
{
	cin >> M;
	int x, y, t;
	for (int i = 0; i < M; i++)
	{
		//��ȡ����
		cin >> x >> y >> t;
		meteor[i] = P(loc(x, y), t);
		//������ʯ��Ϣ�����°�ȫ�ص�
		ground[x][y] = true;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && ny >= 0)
				ground[nx][ny] = true;
		}
	}
	//����ʯ����׹��ʱ������
	sort(meteor, meteor + M, cmp);

	cout << BFS() << endl;
	return 0;
}

