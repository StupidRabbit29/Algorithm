#include<iostream>
#include<algorithm>

using namespace std;

//��������palantir����
int palantir_num(int& range, int& num, int*& troop)
{
	//��troop����
	sort(troop, troop + num);
	int place = 0, palantir = 0;
	//ѡ�����palantir��λ�ã�place����ǰ��Ҫ���ǵ�����˵�troop
	while (place < num)
	{
		//����palantir���ڴ˴�
		int set = place;
		//�������ο��Ǹ����ҵ�λ�ã������ܷ񸲸�place��
		while (set < num && troop[place] + range >= troop[set]) set++;
		//�ҵ��˲��ܸ��ǵĵط������Ѿ������߽磬��ȡǰһ��λ�÷���palantir
		set--;
		place = set;
		//ʹ���·��õ�palantir��range����place�������ƣ�ֱ���޷����ǻ򵽴�߽�
		while (place < num && troop[set] + range >= troop[place]) place++;
		//palantir������1
		palantir++;
	}

	return palantir;
}

int main()
{
	int range, num;
	cin >> range >> num;

	//��ȡ����
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