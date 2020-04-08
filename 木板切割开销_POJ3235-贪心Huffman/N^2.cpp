#include<iostream>

using namespace std;
int main()
{
	int num;
	cin >> num;
	int* fence = new int[num];
	for (int i = 0; i < num; i++)
		cin >> fence[i];
	//ľ�峤����ͺܳ�������int��Χ
	long long cost = 0;

	while (num > 1)
	{
		int min1 = 0, min2 = 1;
		if (fence[min1] > fence[min2]) swap(min1, min2);

		//�ҵ���С������ľ��
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

		//ƴ�ӣ�����۸�
		int cut_cost = fence[min1] + fence[min2];
		cost += cut_cost;

		//�滻ľ�峤��
		if (min1 == num - 1) swap(min1, min2);
		fence[min1] = cut_cost;
		fence[min2] = fence[num - 1];
		//����������Χ
		num--;
	}

	cout << cost;
	return 0;
}
