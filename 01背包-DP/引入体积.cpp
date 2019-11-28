#include"main.h"

template<class Type>
Type max(Type a, Type b);

template<class Type>
Type min(Type a, Type b);

template<class Type>
Type Knapsack3(Type value[], int weight[], int volume[], int size, int Total_V, int item_num, Type** dp)
	//value是所有物品的价值集合, value[0,1,...,item_num]
	//weight是所有物品的重量集合, weight[0,1,...,item_num]
	//volume是所有物品的体积集合, volume[0,1,...,item_num]
	//size是背包容量
	//Total_V是背包容积
	//item_num是物品个数
	//dp[i][j]代表背包容积为i，容量为j时，物品总价值的最大值, dp[0,1,...,Total_V][0,1,...,size]
{
	memset(dp, 0, sizeof(Type));

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