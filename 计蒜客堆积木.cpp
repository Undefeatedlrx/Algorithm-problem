/*蒜头君有 nn 块积木，编号分别为 11 到 nn。一开始，蒜头把第 ii 块积木放在位置 ii。蒜头君进行 mm 次操作，每次操作，蒜头把位置 bb 上的积木整体移动到位置 aa 上面。比如 11 位置的积木是 11，22 位置的积木是 22，那么把位置 22 的积木移动到位置 11 后，位置 11 上的积木从下到上依次为 1, 21, 2。

输入格式

第一行输入 22 个整数 n, m(1 \le n \le 10000, 0 \le m \le 10000)n, m(1≤n≤10000, 0≤m≤10000)。

接下来 mm 行，每行输入 22 个整数 a, b(1 \le a, b \le n)a, b(1≤a, b≤n)，如果aa，bb 相等则本次不需要移动。

输出格式

输出 nn 行，第 ii 行输出位置 ii 从下到上的积木编号，如果该行没有积木输出一行空行。

样例输入1

2 2
1 2
1 2
样例输出1

1 2

样例输入2

4 4
3 1
4 3
2 4
2 2
样例输出2


2 4 3 1
*/
#include <iostream>
#include "vector"
using namespace std;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > v(n);
    for (int i=0;i<n;i++){
        v[i].push_back(i+1);//进行编号
    }
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        if (a!=b){
            for (int i=0; i<v[b-1].size(); i++) {
                v[a-1].push_back(v[b-1][i]);
            }
            vector<int> x;
            v[b-1].swap(x);
        }

    }
    for (int i=0;i<n;i++) {
        for(int j=0;j<v[i].size();j++){
        if (j!=v[i].size()-1){
            printf("%d ",v[i][j]);
        }else {
            printf("%d",v[i][j]);
        }
        }
          printf("\n");
    }
}
