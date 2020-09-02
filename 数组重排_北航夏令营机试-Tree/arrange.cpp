// ����һ�����飬��ǰ������С�����ּ��ÿո���
// ������������һ�����飬ʹ������һ����ȫ�������İ������������Ӷ������ĸ���ʼ��һ��һ��洢�������У�
// �����ȫ������������������ԭ��������Ĵ�С��������
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct tree {
	int a;
	struct tree* l;
	struct tree* r;
} Tree;

int N;
int arr[102];
int power2[7] = { 0, 1, 3, 7, 15, 31, 63 };
int nextline[7] = { 1, 2, 4, 8, 16, 32, 64 };
Tree* T;

// ȷ���������ȵ����鹹����ȫ��������Ӧ�����ĸ�λ�õ����ֵ���
int split(int len)
{
	int base = 0;
	for (int i = 0; i < 6; i++)
		if (len - 1 >= power2[i] * 2 && len - 1 < power2[i + 1] * 2)
		{
			base = power2[i];
			break;
		}
	int rightnum = 0;
	if (len - 1 - base * 2 > base + 1)
		rightnum = len - 1 - base * 2 - 1;
	else
		rightnum = base;

	//cout << "split:" << len - rightnum;
	return len - rightnum;
}

// ������ȫ������
void buildTree(Tree*& t, int left, int right)
{
	t = new Tree;
	int root = left + split(right - left + 1) - 1;
	//cout << "   " << arr[root] << endl;
	t->a = arr[root];
	if (root != left)
		buildTree(t->l, left, root - 1);
	else
		t->l = NULL;
	if (root != right)
		buildTree(t->r, root + 1, right);
	else
		t->r = NULL;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// �ȶ�ԭ��������
	sort(arr, arr + N);
	// ������ȫ������
	buildTree(T, 0, N - 1);

	// ����ȫ�������������
	queue<Tree*> Q;
	Q.push(T);
	while (!Q.empty())
	{
		Tree* t = Q.front();
		Q.pop();
		cout << t->a << " ";
		if (t->l != NULL)
			Q.push(t->l);
		if (t->r != NULL)
			Q.push(t->r);
	}

	return 0;
}