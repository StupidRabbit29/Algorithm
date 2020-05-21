#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, d;
typedef pair<float, float> island;

//注意一定要保证比较函数是严格弱序的
bool cmp(island a, island b)
{
	return a.first < b.first || a.first == b.first && a.second > b.second;
}

int main()
{
	int cases = 0;
	while (true)
	{
		cases++;
		cin >> n >> d;
		if (n == 0 && d == 0)
			break;
		
		// 如果雷达覆盖范围非正，直接认为无法覆盖
		if (d <= 0)
		{
			int x, y;
			for (int i = 0; i < n; i++) cin >> x >> y;
			cout << "Case " << cases << ": -1" << endl;
			continue;
		}

		// 读入岛屿坐标
		island* islands = new island[n];
		bool nosol = false;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if ((y < 0 || y > d) && !nosol)
			{
				cout << "Case " << cases << ": -1" << endl;
				nosol = true;
			}
			// 计算可以覆盖岛屿的区间
			islands[i].first = (x - sqrt((float)(d * d - y * y)));
			islands[i].second = (x + sqrt((float)(d * d - y * y)));
			// cout << islands[i].first << islands[i].second << endl;
		}
		if (nosol)
		{
			delete[] islands;
			continue;
		}	

		//对区间排序
		sort(islands, islands + n, cmp);

		int radar = 0;
		int cur = 0;
		while (cur <= n)
		{
			//遍历区间，记录下区间的右坐标，要求右坐标大于已经遍历过的所有左端点
			float right = islands[cur].second;
			while (cur <= n && islands[cur].first <= right)
			{
				if (islands[cur].second < right)
					right = islands[cur].second;
				cur++;
			}

			// 退出循环遍历的原因是一个区间的左端点大于了目前最小的右端点，说明找到了一个应当放置雷达的位置
			radar++;
		}
		cout << "Case " << cases << ": " << radar << endl;

		delete[] islands;
	}

	return 0;
}

