#include<iostream>

using namespace std;
int main()
{
	int num;
	cin >> num;
	int* fence = new int[num];
	for (int i = 0; i < num; i++)
		cin >> fence[i];
	//木板长度求和很长，超过int范围
	long long cost = 0;

	while (num > 1)
	{
		int min1 = 0, min2 = 1;
		if (fence[min1] > fence[min2]) swap(min1, min2);

		//找到最小的两块木板
		for (int i = 2; i < num; i++)
		{
			if (fence[i] < fence[min1])
			{
				min2 = min1;
				min1 = i;
			}
			else if (fence[i] < fence[min2])
				min2 = i;
		}

		//拼接，计算价格
		int cut_cost = fence[min1] + fence[min2];
		cost += cut_cost;

		//替换木板长度
		if (min1 == num - 1) swap(min1, min2);
		fence[min1] = cut_cost;
		fence[min2] = fence[num - 1];
		//缩短搜索范围
		num--;
	}

	cout << cost;
	return 0;
}
