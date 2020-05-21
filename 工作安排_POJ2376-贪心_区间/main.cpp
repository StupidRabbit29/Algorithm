#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
typedef pair<int, int> P;

// 对工人的工作时间排序，开始时间升序，开始时间相同则按照结束时间降序。
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

	// 对工人的工作时间排序
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

	// 按照工人的工作时间排序后，遍历
	while (next <= N)
	{
		// 向前遍历工人，在保证开始工作时间早于当前已安排时间的情况下，希望工人的结束工作时间尽可能晚
		int maxend = worker[next].second;
		while (next <= N && worker[next].first <= arrange)
		{
			if (worker[next].second > maxend)
				maxend = worker[next].second;
			next++;
		}

		// 工人的结束时间完成对工作的覆盖
		if (maxend >= T)
		{
			cout << num << endl;
			break;
		}
		else
		{
			// 又没覆盖,又没有遍历完工人，如果这时安排了当前最大结束时间的工人后，
			// 下一个工人的开始时间还是不能拼接上，说明失败，否则，可以继续安排
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
				// 工人已经安排完了，时间没覆盖成功
			{
				cout << -1 << endl;
				break;
			}
		}
	}

	delete[] worker;
	return 0;
}
