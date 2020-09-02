// 输入一个数组，提前声明大小，数字间用空格间隔
// 将该数组变成另一个数组，使得它是一棵完全二叉树的按行输出结果（从二叉树的根开始，一层一层存储到数组中）
// 这棵完全二叉树的中序遍历结果原输入数组的从小到大排序
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

// 确定给定长度的数组构成完全二叉树，应当让哪个位置的数字当根
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

// 构建完全二叉树
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

	// 先对原数组排序
	sort(arr, arr + N);
	// 构建完全二叉树
	buildTree(T, 0, N - 1);

	// 将完全二叉树层序输出
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