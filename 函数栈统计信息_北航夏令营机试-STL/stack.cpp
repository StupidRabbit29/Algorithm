// 输入一系列对栈的操作，1操作代表入栈，后跟一个函数名，0操作代表出栈，例如：
/*
1 main
1 mysqrt
1 mysin
0
0
1 mysqrt
1 mycos
0
1 mysin
0
0
1 max
1 mysin
0
0
0
*/
// 要求统计调用深度最深的被调用函数和对应调用序列，如果同一个函数多次以同一调用顺序出现，只打印1次，但是不同的最深调用顺序都要打印。
// 此外还要打印对应函数的扇入数（被同一函数重复调用只统计1次）和被调用数
// 输出
/*
mysin main-mysqrt-mysin 2 3
mycos main-mysqrt-mycos 1 1
mysin main-max-mysin 2 3
*/

#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>

using namespace std;

// 函数的统计信息
typedef struct func {
	string name;
	set<string> call;
	int call_num;
} Func;
vector<Func> F;

// 输出答案的一行
typedef struct ans {
	string name;
	vector<string> before;
} Ans;

string input[201][2];

int main()
{
	// 读入输入操作序列，存储，并统计最深深度
	int depth = 0;
	int line = 0;
	int stacksize = 0;
	while (true)
	{
		int num;
		string funcname = "";
		cin >> num;
		if (num == 1)
			cin >> funcname;
		input[line][0] = num == 0 ? "0" : "1";
		input[line][1] = funcname;

		if (num == 0)
			stacksize--;
		else
			stacksize++;
		if (stacksize > depth)
			depth = stacksize;
		line++;

		if (stacksize == 0)
			break;
	}

	// 重新模拟一遍栈操作
	stack<string> S;
	vector<string> Sbackup;
	vector<Ans> A;
	line = 0;
	while (true)
	{
		int num;
		string funcname;
		num = input[line][0] == "0" ? 0 : 1;
		if (num == 0)
		{
			S.pop();
			Sbackup.pop_back();
		}
		else
		{
			// 修改函数的扇入信息和被调用次数，如果是新函数，则添加新节点
			funcname = input[line][1];
			bool find = false;
			for (vector<Func>::iterator it = F.begin(); it != F.end(); it++)
			{
				if ((*it).name == funcname)
				{
					find = true;
					(*it).call_num++;
					(*it).call.insert(S.top());
					break;
				}
			}
			if (!find)
			{
				Func a;
				a.name = funcname;
				a.call_num = 1;
				if (!S.empty())
					a.call.insert(S.top());
				F.push_back(a);
			}
			S.push(funcname);
			Sbackup.push_back(funcname);
		}
		line++;

		// 如果当前函数是最深层的，则可能需要输出
		if (S.size() == depth)
		{
			// 查找之前是否有过同样的被调用函数和调用路径
			bool find = false;
			for (vector<Ans>::iterator it = A.begin(); it != A.end(); it++)
			{
				if ((*it).name == funcname && (*it).before == Sbackup)
				{
					find = true;
					break;
				}
			}
			// 如果没找到，则添加新的一行答案
			if (!find)
			{
				Ans a;
				a.name = funcname;
				a.before = Sbackup;
				A.push_back(a);
				//cout << "push ans" << endl;
			}
		}

		if (S.empty())
			break;
	}

	// 输出答案
	for (vector<Ans>::iterator it = A.begin(); it != A.end(); it++)
	{
		string funcname = (*it).name;
		cout << funcname << " ";

		// 输出调用路径
		bool first = true;
		for (vector<string>::iterator sit = (*it).before.begin(); sit != (*it).before.end(); sit++)
		{
			if (first)
			{
				cout << *sit;
				first = false;
			}
			else
				cout << "-" << *sit;
		}

		// 在所有函数中找到对应函数，输出统计信息。
		for (vector<Func>::iterator it = F.begin(); it != F.end(); it++)
		{
			if ((*it).name == funcname)
			{
				cout << " " << (*it).call.size();
				cout << " " << (*it).call_num;
				break;
			}
		}

		cout << endl;
	}
	return 0;
}