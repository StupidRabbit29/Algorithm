#include<iostream>
#include<string>

using namespace std;
int main()
{
	int num;
	char temp[2001] = { '\0' };
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> temp[i];
	string S(temp);
	char T[2001] = { '\0' };

	int i = 0;
	while (S.length() > 1)
	{
		//�õ�S���ַ�������
		string Sinver = string(S.rbegin(), S.rend());
		/*����
		string Sinver;
		Sinver.assign(S.rbegin(), S.rend());
		*/
		
		//����S��S��Ĵ�С���ж�ȡ�ĸ��ַ�
		if (S < Sinver)
		{
			T[i] = *(S.begin());
			S = string(S.begin() + 1, S.end());
		}
		else
		{
			T[i] = *(S.end() - 1);
			S = string(S.begin(), S.end() - 1);
		}
		i++;
	}
	T[i] = *(S.begin());

	for (int i = 0; T[i]; i++)
	{
		cout << T[i];
		if (i % 80 == 79 && T[i+1])
			cout << endl;
	}
		
	return 0;
}