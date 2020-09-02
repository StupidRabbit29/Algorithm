// ����һϵ�ж�ջ�Ĳ�����1����������ջ�����һ����������0���������ջ�����磺
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
// Ҫ��ͳ�Ƶ����������ı����ú����Ͷ�Ӧ�������У����ͬһ�����������ͬһ����˳����֣�ֻ��ӡ1�Σ����ǲ�ͬ���������˳��Ҫ��ӡ��
// ���⻹Ҫ��ӡ��Ӧ����������������ͬһ�����ظ�����ֻͳ��1�Σ��ͱ�������
// ���
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

// ������ͳ����Ϣ
typedef struct func {
	string name;
	set<string> call;
	int call_num;
} Func;
vector<Func> F;

// ����𰸵�һ��
typedef struct ans {
	string name;
	vector<string> before;
} Ans;

string input[201][2];

int main()
{
	// ��������������У��洢����ͳ���������
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

	// ����ģ��һ��ջ����
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
			// �޸ĺ�����������Ϣ�ͱ����ô�����������º�����������½ڵ�
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

		// �����ǰ�����������ģ��������Ҫ���
		if (S.size() == depth)
		{
			// ����֮ǰ�Ƿ��й�ͬ���ı����ú����͵���·��
			bool find = false;
			for (vector<Ans>::iterator it = A.begin(); it != A.end(); it++)
			{
				if ((*it).name == funcname && (*it).before == Sbackup)
				{
					find = true;
					break;
				}
			}
			// ���û�ҵ���������µ�һ�д�
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

	// �����
	for (vector<Ans>::iterator it = A.begin(); it != A.end(); it++)
	{
		string funcname = (*it).name;
		cout << funcname << " ";

		// �������·��
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

		// �����к������ҵ���Ӧ���������ͳ����Ϣ��
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