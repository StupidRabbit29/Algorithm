#include"main.h"

template<class Type>
int binary(int i, int k, Type array[], Type dp[])
	//�ö��ַ��ҵ� dp[j-1]<=array[i]<=dp[j]
{
	if (array[i] < dp[1])
		return 1;
	else
	{
		for (int low = 1, high = k; high != low + 1)
		{
			mid = (low + high) / 2;
			if (dp[mid] > array[i])
				high = mid;
			else
				low = mid;
		}

		return low;
	}
}

template<class Type>
int FindInc(Type array[], int num, Type dp[])
	//array�洢����
	//numΪ����ĳ���
	//dp[j], 1<=j<=k����ʾarray[1,2,3,...,i]�����г���Ϊj�ĵ��������������У���βԪ�ص���Сֵ
{
	dp[1] = array[1];
	
	for (int i = 2, k = 1; i <= num; i++)
		//k����array[1,2,3,...,i]����������������еĳ���
	{
		if (array[i] > dp[k])
			dp[++k] = array[i];
		else
			//�ö��ַ��ҵ� dp[j-1]<=array[i]<=dp[j]����dp[j] = array[i]
			dp[binary(i, k)] = array[i];
	}

	return k;
}

//��ӡ�����������
template<class Type>
void PrintInc(Type array[], int num)
{
	
}

//�㷨���Ӷȣ�O(nlogn)