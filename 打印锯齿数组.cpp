#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>*v=new vector<int>[n];
	for (int i = 0; i < m; i++)
	{
		int row, data;
		cin >> row >> data;
		v[row - 1].push_back(data);
	}
	for (int i = 0; i < n; i++)
	{
		vector<int>::iterator t;
		for (t = v[i].begin(); t != v[i].end(); t++)
		{
			cout << *t;
			if (t != v[i].end() - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
