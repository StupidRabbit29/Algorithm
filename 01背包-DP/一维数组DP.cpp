#include"main.h"

template<class Type>
Type max(Type a, Type b);

template<class Type>
Type min(Type a, Type b);

template<class Type>
Type Knapsack2(Type value[], int weight[], int size, int item_num, Type dp[])
	//value是所有物品的价值集合, value[0,1,...,item_num]
	//weight是所有物品的重量集合, weight[0,1,...,item_num]
	//size是背包容量
	//item_num是物品个数
	//dp[j]代表背包容量为j时，物品总价值的最大值, dp[0,1,...,size]
{
	memset(dp, 0, sizeof(Type));

	for (int i = 1; i <= item_num; i++)
	{
		for (int j = size; j >= weight[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	return dp[size];
}