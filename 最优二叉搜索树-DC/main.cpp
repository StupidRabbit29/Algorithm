#include<iostream>
using namespace std;

int num = 0;

void OBST1(float a[], float b[], float** m, int** s, float** w);
void CreateTree(int** s, int i, int j);
void PrintMsg(float** w);
void PrintTreeRoot(int** s);

int main()
{
	cin >> num;
	float* a = new float[num+1];
	float* b = new float[num+1];
	float** m = new float* [num + 2];
	float** w = new float* [num + 2];
	int** s = new int* [num + 1];
	for (int i = 0; i <= num; i++)
	{
		m[i] = new float[num + 1]{ 0 };
		w[i] = new float[num + 1]{ 0 };
		s[i] = new int[num + 1]{ 0 };
	}
	m[num + 1] = new float[num + 1]{ 0 };
	w[num + 1] = new float[num + 1]{ 0 };

	for (int i = 0; i <= num; i++)
		cin >> a[i];
	for (int i = 1; i <= num; i++)
		cin >> b[i];

	OBST1(a, b, m, s, w);
	cout << "w:" << endl;
	PrintMsg(w);
	cout << "m:" << endl;
	PrintMsg(m);
	cout << "s:" << endl;
	PrintTreeRoot(s);
	CreateTree(s, 1, num);

	system("pause");
	return 0;
}

//�������Ž�
void CreateTree(int** s, int i, int j)
{
	if (i == j)
		return;
	else
	{
		int k = s[i][j];
		if (i != k && k != j)
			cout << "Tree[" << i << ", " << j << "]: " << "Tree[" << i << ", " << k - 1 << "]-->" << k << "<--Tree[" << k + 1 << ", " << j << "]" << endl;
		else if(i==k&&k!=j)
			cout << "Tree[" << i << ", " << j << "]: " << k << "<--Tree[" << k + 1 << ", " << j << "]" << endl;
		else if(i!=k&&k==j)
			cout << "Tree[" << i << ", " << j << "]: " << "Tree[" << i << ", " << k - 1 << "]-->" << k << endl;

		if (i != k)
			CreateTree(s, i, k - 1);
		if (k != j)
			CreateTree(s, k + 1, j);
	}
}

//��ӡS������Ϣ
void PrintTreeRoot(int** s)
{
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= num; j++)
			cout << s[i][j] << " ";

		cout << endl;
	}
	cout << endl;
}

//��ӡS������Ϣ
void PrintMsg(float** w)
{
	for (int i = 0; i <= num + 1; i++)
	{
		for (int j = 0; j <= num; j++)
			cout << w[i][j] << "\t";

		cout << endl;
	}
	cout << endl;
}

//��̬�滮�㷨������Ŷ���������
void OBST1(float a[], float b[], float** m, int** s, float** w)
{
	//��ʼ��w�����m�����в���Ԫ��
	for (int i = 0; i <= num; i++)
	{
		w[i + 1][i] = a[i];
		m[i + 1][i] = 0.0;
	}

	for (int r = 0; r < num; r++)
	{
		for (int i = 1; i <= num - r; i++)
		{
			int j = i + r;

			//�൱��ȡk=i������������Ҷ�ӽڵ㣬���������ڲ��ڵ�ȫ��������������
			w[i][j] = w[i][j - 1] + a[j] + b[j];
			m[i][j] = m[i + 1][j];
			s[i][j] = i;

			//����k
			for (int k = i + 1; k <= j; k++)
			{
				float t = m[i][k - 1] + m[k + 1][j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
			m[i][j] += w[i][j];
		}
	}
}