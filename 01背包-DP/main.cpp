#include<iostream>

#define MAX_ITEM_NUM 100
#define MAX_SIZE 10000
#define MAX_VOLUME 10000
using namespace std;

template<class Type>
Type max(Type a, Type b)
{
	return a > b ? a : b;
}

template<class Type>
Type min(Type a, Type b)
{
	return a < b ? a : b;
}

//��ά����DP
int Knapsack1(int*& value, int*& weight, int size, int item_num)
//value��������Ʒ�ļ�ֵ����, value[0,1,...,item_num]
//weight��������Ʒ����������, weight[0,1,...,item_num]
//size�Ǳ�������
//item_num����Ʒ����
//dp[i][j]����������Ϊj��������������ƷΪ1,2,3,...,i-1,iʱ����Ʒ�ܼ�ֵ�����ֵ, 
//dp[0,1,...,item_num][0,1,...,size]
{
	//int (*dp)[MAX_SIZE] = new int[MAX_ITEM_NUM][MAX_SIZE];

	int** dp = new int* [MAX_ITEM_NUM];
	for (int i = 0; i < MAX_ITEM_NUM; i++)
		dp[i] = new int[MAX_SIZE] {0};

	for (int i = 0; i <= item_num; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (j < weight[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}

	int item_value = dp[item_num][size];
	for (int i = 0; i < MAX_ITEM_NUM; i++)
		delete[] dp[i];
	delete[] dp;
	return item_value;
}

//һά����DP
int Knapsack2(int*& value, int*& weight, int &size, int &item_num)
//value��������Ʒ�ļ�ֵ����, value[0,1,...,item_num]
//weight��������Ʒ����������, weight[0,1,...,item_num]
//size�Ǳ�������
//item_num����Ʒ����
//dp[j]����������Ϊjʱ����Ʒ�ܼ�ֵ�����ֵ, dp[0,1,...,size]
//�㷨���Ӷȣ�O(item_num * size)
{
	int* dp = new int[MAX_SIZE] {0};

	for (int i = 1; i <= item_num; i++)
	{
		for (int j = size; j >= weight[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	int item_value = dp[size];
	delete[] dp;
	return item_value;
}

template<class Type>//�������
Type Knapsack3(Type*& value, int*& weight, int*& volume, int size, int Total_V,	int item_num)
//value��������Ʒ�ļ�ֵ����, value[0,1,...,item_num]
//weight��������Ʒ����������, weight[0,1,...,item_num]
//volume��������Ʒ���������, volume[0,1,...,item_num]
//size�Ǳ�������
//Total_V�Ǳ����ݻ�
//item_num����Ʒ����
//dp[i][j]�������ݻ�Ϊi������Ϊjʱ����Ʒ�ܼ�ֵ�����ֵ, dp[0,1,...,Total_V][0,1,...,size]
//�㷨���Ӷȣ�O(item_num * size * Total_V)
{
	Type dp[MAX_VOLUME][MAX_SIZE];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= item_num; i++)
	{
		for (int j = size; j >= weight[i]; j--)
		{
			for (int k = Total_V; k >= volume[i]; k--)
			{
				dp[k][j] = max(dp[k][j], dp[k - volume[i]][j - weight[i]] + value[i]);
			}
		}
	}

	return dp[Total_V][size];
}



int main()
{
	int item_num = 0, size = 0;
	cin >> item_num >> size;

	int *value = new int[item_num + 1] {0};
	int *weight = new int[item_num + 1] {0};
	for (int i = 0; i < item_num; i++)
		cin >> value[i + 1];
	for (int i = 0; i < item_num; i++)
		cin >> weight[i + 1];

	cout << "��ά����DP���" << Knapsack1(value, weight, size, item_num) << endl;
	cout << "һά����DP���" << Knapsack2(value, weight, size, item_num) << endl;

	delete[] value;
	delete[] weight;
	return 0;
}
/*
4 5
3 2 4 2
2 1 3 2
*/

