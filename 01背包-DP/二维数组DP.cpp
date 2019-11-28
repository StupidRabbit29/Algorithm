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
	//value��������Ʒ�ļ�ֵ����, value[0,1,...,item_num]
	//weight��������Ʒ����������, weight[0,1,...,item_num]
	//size�Ǳ�������
	//item_num����Ʒ����
	//dp[i][j]����������Ϊj��������������ƷΪ1,2,3,...,i-1,iʱ����Ʒ�ܼ�ֵ�����ֵ, dp[0,1,...,item_num][0,1,...,size]
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