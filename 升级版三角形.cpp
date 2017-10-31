#include <iostream>
#include <string>
using namespace std;
int main() {
	char in;
	cin >> in;
	if (in <= '9'&&in >= '0')//处理数字型？
	{
		int n = in-'0';
		for (int i = 1; i <= n; i++)
		{
			string space(n - i, ' ');
			cout << space;
			int j;
			for (j = 1; j <= i; j++)
				cout << j;
			for (j -=2; j >= 1; j--)
				cout << j;
			cout << '\n';
		}
	}
	else
	{
		int n = in - 'A' + 1;
		for (int i = 1; i <= n; i++)
		{
			string space(n - i, ' ');
			cout << space;
			int j;
			char c;
			for (j = 1; j <= i; j++)
			{
				c = 'A' + j - 1;
				cout << c;
			}
			for (j -= 2; j >= 1; j--)
			{
				c = 'A' + j - 1;
				cout << c;
			}
			cout << '\n';
		}
	}
	return 0;
}
