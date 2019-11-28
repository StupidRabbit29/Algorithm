#include"main.h"

template<class Type>
int binary(int i, int k, Type array[], Type dp[])
	//用二分法找到 dp[j-1]<=array[i]<=dp[j]
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
	//array存储数组
	//num为数组的长度
	//dp[j], 1<=j<=k，表示array[1,2,3,...,i]中所有长度为j的单调递增子序列中，结尾元素的最小值
{
	dp[1] = array[1];
	
	for (int i = 2, k = 1; i <= num; i++)
		//k代表array[1,2,3,...,i]中最长单调递增子序列的长度
	{
		if (array[i] > dp[k])
			dp[++k] = array[i];
		else
			//用二分法找到 dp[j-1]<=array[i]<=dp[j]，令dp[j] = array[i]
			dp[binary(i, k)] = array[i];
	}

	return k;
}

//打印最长递增子序列
template<class Type>
void PrintInc(Type array[], int num)
{
	
}

//算法复杂度：O(nlogn)