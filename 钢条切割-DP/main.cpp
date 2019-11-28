#include<iostream>
#include<cstdlib>

const int MAX_SIZE = 10;

using namespace std;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Value_Max(int n, int value[MAX_SIZE], int length[MAX_SIZE])
{
	if (n == 0)
		return 0;
	else
	{
		int max = 0;
		for (int i = 1; i <= n; i++)
			if (length[i - 1] != 0)
				max = Max(max, value[i - 1] + Value_Max(n - i, value, length));

		return max;
	}
}

int Memoized_Value_Max(int n, int value[MAX_SIZE], int length[MAX_SIZE], int R[MAX_SIZE])
{
	int q = 0;
	if (R[n] >= 0)
		return R[n];

	if (n == 0)
		q = 0;
	else
	{
		q = 0;
		for (int i = 1; i <= n; i++)
			if (length[i - 1] != 0)
				q = Max(q, value[i - 1] + Memoized_Value_Max(n - i, value, length, R));
	}

	R[n] = q;
	return q;
}

int main()
{
	int length[MAX_SIZE];
	int value[MAX_SIZE];
	int Len = 0;
	memset(length, 0, sizeof(length));
	memset(value, 0, sizeof(value));

	cout << "请输入钢条长度" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		cin >> length[i];
	cout << "请输入钢条价格" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		cin >> value[i];

	cout << "请输入待切割钢条长度" << endl;
	cin >> Len;

	/*********************************************************************************/
	/*使用未加优化的递归*/
	//cout << Value_Max(Len, value, length) << endl;
	/*********************************************************************************/

	/*********************************************************************************/
	/*使用top-down with memoization*/
	int* R = new int[MAX_SIZE];

	for (int i = 0; i < Len; i++)
		R[i] = -1;

	//cout << Memoized_Value_Max(Len, value, length, R) << endl;
	/*********************************************************************************/

	/*********************************************************************************/
	/*bottom-up method*/
	int* S = new int[MAX_SIZE] {0};

	for (int i = 1; i <= Len; i++)
	{
		int q = 0;

		for (int j = 1; j <= i; j++)
			if (length[j - 1] != 0)
				q = Max(q, value[j - 1] + S[i - j]);

		S[i] = q;
	}

	//cout << S[Len] << endl;
	/*********************************************************************************/

	for (int i = 1; i <= 10; i++)
		cout << Value_Max(i, value, length) << "   " << Memoized_Value_Max(i, value, length, R) << "   " << S[i] << endl;

	system("pause");
	return 0;
}

//1 2 3 4 5 6 7 8 9 10 1 5 8 9 10 17 17 20 24 30 10