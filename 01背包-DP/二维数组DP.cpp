#include"main.h"

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

template<class Type>
Type Knapsack1(Type value[], int weight[], int size, int item_num, Type** dp)
	//value是所有物品的价值集合, value[0,1,...,item_num]
	//weight是所有物品的重量集合, weight[0,1,...,item_num]
	//size是背包容量
	//item_num是物品个数
	//dp[i][j]代表背包容量为j，且允许放入的物品为1,2,3,...,i-1,i时，物品总价值的最大值, dp[0,1,...,item_num][0,1,...,size]
{
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
	
	return dp[item_num][size];
}