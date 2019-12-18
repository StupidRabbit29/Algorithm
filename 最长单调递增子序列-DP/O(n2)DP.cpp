#include"main.h"

template<class Type>
int FindInc(Type array[], int num, int dp[], int pre[])
	//array存储数组
	//num为数组的长度
	//

{
	memset(dp, 0, sizeof(dp));
	memset(pre, 0, sizeof(pre));

	dp[1] = 1;
	pre[1] = 0;
	for (int i = 2; i <= num; i++)
	{
		int max = 1;
		int index = 0;
		for (int j = 1; j < i; j++)
		{
			if (array[i] > array[j] && dp[j] + 1 > max)
			{
				max = dp[j] + 1;
				index = j;
			}
		}

		dp[i] = max;
		pre[i] = index;
	}

	int max = 1;
	int end = 1;
	for (int i = 2; i <= num; i++)
		if (dp[i] > max)
		{
			max = dp[i];
			end = i;
		}

	return end;
}

//打印最长递增子序列
template<class Type>
void PrintInc(Type array[], int pre[], int end)
{
	stack<Type>my_stack;
	for (int i = end; i > 0; i = pre[end])
	{
		my_stack.push(array[i]);
	}

	while (!my_stack.empty())
	{
		cout << my_stack.top() << endl;
		my_stack.pop();
	}
}

//算法复杂度：O(n^2)