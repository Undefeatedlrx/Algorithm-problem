#include <iostream>
#include <cmath>
using namespace std;
inline int isreserve(int a)
{
	int tmp = a; int len = 0, reserve = 0;
	while (a)
	{
		a /= 10;
		len++;
	}
	a = tmp;
	for (; len>0; len--)
	{
		int div = pow(10, len - 1);
		reserve +=(a%10)* div;
		a /= 10;
	}
	return tmp == reserve;
}
inline int sum(int a)//各位数字剥离求和
{
	int sum=0;
	while (a)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}
int main()
{
	int n,count=0;
	cin >> n;
	for (int i = 10000; i <= 999999; i++)
	{
		if (isreserve(i) && sum(i) == n)
		{
			cout << i << endl;
			count++;
		}
	}
	if (!count)
		cout << -1 << endl;
	

	return 0;
}
