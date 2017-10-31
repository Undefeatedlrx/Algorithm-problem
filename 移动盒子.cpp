///双向链表---节点
///如果数据结构上的某一个操作很耗时，有时可以用加标记的方式处理，而不需要真的去执行那个操作，
///但同时，该数据结构的所有其他操作都要考虑这个操作
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;
#define maxn 100005
int Right[100005], Left[100005];

void link(int L, int R)///辅助函数是两个节点相互连接
{
	Right[L] = R;
	Left[R] = L;
}

int main()
{
	int n, m;
	int op;
	while (scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= n; i++)
		{
			Left[i] = i - 1;
			Right[i] = (i + 1) % (n + 1);
		}
		Right[0] = 1;
		Left[0] = n;

		int inv = 0;
		int X, Y;
		while (m--)
		{
			cin >> op;
			if (op == 4)
				inv = 1;
			else
			{
				cin >> X >> Y;
				if (op == 3 && Right[Y] == X)  swap(X, Y);///交换后使得Y保证在X的右边，利于后面的统一交换操作
				if (op != 3 && inv)  op = 3 - op;
				if (op == 1 && Right[X] == Y)  continue;
				if (op == 2 && Right[Y] == X)  continue;

				int LX = Left[X], RX = Right[X], LY = Left[Y], RY = Right[Y];///这一步至关重要，倘若不使用这一步，在连接节点的过程中，原始值会发生改变，会导致之后系列的连接出错
				if (op == 1)
				{
					link(LX, RX);
					link(X, Y);
					link(LY, X);
				}
				else if (op == 2)
				{
					link(LX, RX);
					link(Y, X);
					link(X, RY);
				}
				else if (op == 3)
				{
					if (RX == Y)
					{
						link(LX, Y);
						link(Y, X);
						link(X, RY);
					}
					else
					{
						link(LX, Y);
						link(Y, RX);
						link(LY, X);
						link(X, RY);
					}
				}
			}
		}
		int t = 0;
		long long ans = 0;///防止数据溢出
		for (int i = 1; i <= n; i++)
		{
			t = Right[t];
			if (i % 2)
				ans += t;
		}
		if (inv&&n % 2 == 0) ans = (long long)n*(n + 1) / 2 - ans;
		cout << ans << endl;
	}

	return 0   ; 
}
