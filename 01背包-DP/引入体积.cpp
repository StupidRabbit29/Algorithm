#include"main.h"

template<class Type>
Type max(Type a, Type b);

template<class Type>
Type min(Type a, Type b);

template<class Type>
Type Knapsack3(Type value[], int weight[], int volume[], int size, int Total_V, int item_num, Type** dp)
	//value��������Ʒ�ļ�ֵ����, value[0,1,...,item_num]
	//weight��������Ʒ����������, weight[0,1,...,item_num]
	//volume��������Ʒ���������, volume[0,1,...,item_num]
	//size�Ǳ�������
	//Total_V�Ǳ����ݻ�
	//item_num����Ʒ����
	//dp[i][j]�������ݻ�Ϊi������Ϊjʱ����Ʒ�ܼ�ֵ�����ֵ, dp[0,1,...,Total_V][0,1,...,size]
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