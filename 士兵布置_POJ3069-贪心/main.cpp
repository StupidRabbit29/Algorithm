#include<iostream>
#include<algorithm>

using namespace std;

//计算所需palantir数量
int palantir_num(int& range, int& num, int*& troop)
{
	//对troop排序
	sort(troop, troop + num);
	int place = 0, palantir = 0;
	//选择放置palantir的位置，place代表当前需要考虑的最左端的troop
	while (place < num)
	{
		//假设palantir放在此处
		int set = place;
		//向右依次考虑更靠右的位置，检验能否覆盖place处
		while (set < num && troop[place] + range >= troop[set]) set++;
		//找到了不能覆盖的地方，或已经超出边界，则取前一个位置放置palantir
		set--;
		place = set;
		//使用新放置的palantir的range，将place向右推移，直到无法覆盖或到达边界
		while (place < num && troop[set] + range >= troop[place]) place++;
		//palantir数量加1
		palantir++;
	}

	return palantir;
}

int main()
{
	int range, num;
	cin >> range >> num;

	//获取输入
	while (range != -1 && num != -1)
	{
		int* troop = new int[num];
		for (int i = 0; i < num; i++)
			cin >> troop[i];

		int palantir = palantir_num(range, num, troop);
		cout << palantir << endl;

		cin >> range >> num;
	}

	return 0;
}