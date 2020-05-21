#include<iostream>
#include<algorithm>

using namespace std;

int N, sum;
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int coefficient[10][10] = {
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 3, 3, 1, 0, 0, 0, 0, 0, 0 },
	{ 1, 4, 6, 4, 1, 0, 0, 0, 0, 0 },
	{ 1, 5, 10, 10, 5, 1, 0, 0, 0, 0},
	{ 1, 6, 15, 20, 15, 6, 1, 0, 0, 0 },
	{ 1, 7, 21, 35, 35, 21, 7, 1, 0, 0 },
	{ 1, 8, 28, 56, 70, 56, 28, 8, 1, 0 },
	{ 1, 9, 36, 84, 126, 126, 84, 36, 9, 1 },
};

int main()
{
	cin >> N >> sum;
	do {
		int tmp = 0;
		for (int i = 0; i < N; i++)
			tmp += a[i] * coefficient[N - 1][i];
		if (tmp == sum)
		{
			for (int j = 0; j < N; j++)
				cout << a[j] << " ";
			cout << endl;
			break;
		}
	} while (next_permutation(a, a + N));

	return 0;
}