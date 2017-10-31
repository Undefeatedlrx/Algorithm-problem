#include<iostream>
#include<cstring>
using namespace std;
char sz1[1000];
char sz2[1000];
int maxlen[1000][1000];
int main() {
	while (cin >> sz1 >> sz2) {
		int length1 = strlen(sz1);
		int length2 = strlen(sz2);
		int nTmp;
		for (int i = 0; i <= length1; i++)
			maxlen[i][0] = 0;
		for (int j = 0; j <= length2; j++)
			maxlen[0][j] = 0;

		for (int i = 1; i <= length1; i++) {
			for (int j = 1; j <= length2; j++) {
				if (sz1[i - 1] == sz2[j - 1])
					maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
				else
					maxlen[i][j] = max(maxlen[i][j - 1], maxlen[i - 1][j]);
			}
		}
		cout << maxlen[length1][length2] << endl;
	}
	return 0;
}
