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

//二维数组DP
int Knapsack1(int*& value, int*& weight, int size, int item_num)
//value是所有物品的价值集合, value[0,1,...,item_num]
//weight是所有物品的重量集合, weight[0,1,...,item_num]
//size是背包容量
//item_num是物品个数
//dp[i][j]代表背包容量为j，且允许放入的物品为1,2,3,...,i-1,i时，物品总价值的最大值, 
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

//一维数组DP
int Knapsack2(int*& value, int*& weight, int &size, int &item_num)
//value是所有物品的价值集合, value[0,1,...,item_num]
//weight是所有物品的重量集合, weight[0,1,...,item_num]
//size是背包容量
//item_num是物品个数
//dp[j]代表背包容量为j时，物品总价值的最大值, dp[0,1,...,size]
//算法复杂度：O(item_num * size)
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

template<class Type>//引入体积
Type Knapsack3(Type*& value, int*& weight, int*& volume, int size, int Total_V,	int item_num)
//value是所有物品的价值集合, value[0,1,...,item_num]
//weight是所有物品的重量集合, weight[0,1,...,item_num]
//volume是所有物品的体积集合, volume[0,1,...,item_num]
//size是背包容量
//Total_V是背包容积
//item_num是物品个数
//dp[i][j]代表背包容积为i，容量为j时，物品总价值的最大值, dp[0,1,...,Total_V][0,1,...,size]
//算法复杂度：O(item_num * size * Total_V)
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

	cout << "二维数组DP结果" << Knapsack1(value, weight, size, item_num) << endl;
	cout << "一维数组DP结果" << Knapsack2(value, weight, size, item_num) << endl;

	delete[] value;
	delete[] weight;
	return 0;
}
/*
4 5
3 2 4 2
2 1 3 2
*/

