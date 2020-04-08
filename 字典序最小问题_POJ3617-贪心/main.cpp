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
		//得到S的字符串反序
		string Sinver = string(S.rbegin(), S.rend());
		/*或者
		string Sinver;
		Sinver.assign(S.rbegin(), S.rend());
		*/
		
		//根据S和S逆的大小，判断取哪个字符
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