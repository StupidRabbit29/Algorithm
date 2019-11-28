#include"main.h"

template<class Type>
Type max(Type a, Type b);

template<class Type>
Type min(Type a, Type b);

template<class Type>
Type Knapsack2(Type value[], int weight[], int size, int item_num, Type dp[])
	//value��������Ʒ�ļ�ֵ����, value[0,1,...,item_num]
	//weight��������Ʒ����������, weight[0,1,...,item_num]
	//size�Ǳ�������
	//item_num����Ʒ����
	//dp[j]����������Ϊjʱ����Ʒ�ܼ�ֵ�����ֵ, dp[0,1,...,size]
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