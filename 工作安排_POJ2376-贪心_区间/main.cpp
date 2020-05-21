#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
typedef pair<int, int> P;

// �Թ��˵Ĺ���ʱ�����򣬿�ʼʱ�����򣬿�ʼʱ����ͬ���ս���ʱ�併��
bool cmp(P a, P b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main()
{
	cin >> N >> T;
	P* worker = new P[N];

	for (int i = 0; i < N; i++)
		scanf_s("%d %d", &worker[i].first, &worker[i].second);

	// �Թ��˵Ĺ���ʱ������
	sort(worker, worker + N, cmp);

	int arrange = 1;
	int next = 0;
	int num = 1;

	if (worker[0].first > 1)
	{
		cout << -1 << endl;
		delete[] worker;
		return 0;
	}

	// ���չ��˵Ĺ���ʱ������󣬱���
	while (next <= N)
	{
		// ��ǰ�������ˣ��ڱ�֤��ʼ����ʱ�����ڵ�ǰ�Ѱ���ʱ�������£�ϣ�����˵Ľ�������ʱ�価������
		int maxend = worker[next].second;
		while (next <= N && worker[next].first <= arrange)
		{
			if (worker[next].second > maxend)
				maxend = worker[next].second;
			next++;
		}

		// ���˵Ľ���ʱ����ɶԹ����ĸ���
		if (maxend >= T)
		{
			cout << num << endl;
			break;
		}
		else
		{
			// ��û����,��û�б����깤�ˣ������ʱ�����˵�ǰ������ʱ��Ĺ��˺�
			// ��һ�����˵Ŀ�ʼʱ�仹�ǲ���ƴ���ϣ�˵��ʧ�ܣ����򣬿��Լ�������
			if (next <= N)
			{
				if (worker[next].first > maxend + 1)
				{
					cout << -1 << endl;
					break;
				}
				num++;
				arrange = maxend + 1;
			}
			else
				// �����Ѿ��������ˣ�ʱ��û���ǳɹ�
			{
				cout << -1 << endl;
				break;
			}
		}
	}

	delete[] worker;
	return 0;
}
