#include <iostream>
using namespace std;
int main()
{
	int n, X, *num = NULL, ans = 0;
	cin >> n >> X;
	num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < (1 << n); i++)
	{
		int s = 0;
		for (int j = 0; j < n; j++)
		{
			if (i&(1 << j))
				s += num[j];
		}
		if (s == X)
			ans++;
	}
	cout << ans << endl;
	
	return 0;
}
