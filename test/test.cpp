#include <iostream>
#include<string>
//#include<algorithm>

using namespace std;
int main()
{
	string str1 = "1234567890";
	cout << "str1  " << str1 << endl;
	string str2("1234567890");
	cout << "str2  " << str2 << endl;
	cout << "str2 reverse  " << string(str2.rbegin(), str2.rend()) << endl;
	string str3(str2.rbegin(), str2.rend());
	cout << "str3  " << str3 << endl;
	string str4;
	str4 = string(str2.rbegin(), str2.rend());
	cout << "str4  " << str4 << endl;
	str4.assign(str2.rbegin(), str2.rend());
	cout << "str4  " << str4 << endl;
	reverse(str2.begin(), str2.end());
	cout << "str2  " << str2 << endl;

	return 0;
}