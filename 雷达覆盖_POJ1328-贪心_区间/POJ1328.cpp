#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, d;
typedef pair<float, float> island;

//ע��һ��Ҫ��֤�ȽϺ������ϸ������
bool cmp(island a, island b)
{
	return a.first < b.first || a.first == b.first && a.second > b.second;
}

int main()
{
	int cases = 0;
	while (true)
	{
		cases++;
		cin >> n >> d;
		if (n == 0 && d == 0)
			break;
		
		// ����״︲�Ƿ�Χ������ֱ����Ϊ�޷�����
		if (d <= 0)
		{
			int x, y;
			for (int i = 0; i < n; i++) cin >> x >> y;
			cout << "Case " << cases << ": -1" << endl;
			continue;
		}

		// ���뵺������
		island* islands = new island[n];
		bool nosol = false;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if ((y < 0 || y > d) && !nosol)
			{
				cout << "Case " << cases << ": -1" << endl;
				nosol = true;
			}
			// ������Ը��ǵ��������
			islands[i].first = (x - sqrt((float)(d * d - y * y)));
			islands[i].second = (x + sqrt((float)(d * d - y * y)));
			// cout << islands[i].first << islands[i].second << endl;
		}
		if (nosol)
		{
			delete[] islands;
			continue;
		}	

		//����������
		sort(islands, islands + n, cmp);

		int radar = 0;
		int cur = 0;
		while (cur <= n)
		{
			//�������䣬��¼������������꣬Ҫ������������Ѿ���������������˵�
			float right = islands[cur].second;
			while (cur <= n && islands[cur].first <= right)
			{
				if (islands[cur].second < right)
					right = islands[cur].second;
				cur++;
			}

			// �˳�ѭ��������ԭ����һ���������˵������Ŀǰ��С���Ҷ˵㣬˵���ҵ���һ��Ӧ�������״��λ��
			radar++;
		}
		cout << "Case " << cases << ": " << radar << endl;

		delete[] islands;
	}

	return 0;
}

