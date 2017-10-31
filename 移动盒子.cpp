///˫������---�ڵ�
///������ݽṹ�ϵ�ĳһ�������ܺ�ʱ����ʱ�����üӱ�ǵķ�ʽ����������Ҫ���ȥִ���Ǹ�������
///��ͬʱ�������ݽṹ����������������Ҫ�����������
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;
#define maxn 100005
int Right[100005], Left[100005];

void link(int L, int R)///���������������ڵ��໥����
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
				if (op == 3 && Right[Y] == X)  swap(X, Y);///������ʹ��Y��֤��X���ұߣ����ں����ͳһ��������
				if (op != 3 && inv)  op = 3 - op;
				if (op == 1 && Right[X] == Y)  continue;
				if (op == 2 && Right[Y] == X)  continue;

				int LX = Left[X], RX = Right[X], LY = Left[Y], RY = Right[Y];///��һ��������Ҫ��������ʹ����һ���������ӽڵ�Ĺ����У�ԭʼֵ�ᷢ���ı䣬�ᵼ��֮��ϵ�е����ӳ���
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
		long long ans = 0;///��ֹ�������
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
