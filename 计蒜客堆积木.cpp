/*��ͷ���� nn ���ľ����ŷֱ�Ϊ 11 �� nn��һ��ʼ����ͷ�ѵ� ii ���ľ����λ�� ii����ͷ������ mm �β�����ÿ�β�������ͷ��λ�� bb �ϵĻ�ľ�����ƶ���λ�� aa ���档���� 11 λ�õĻ�ľ�� 11��22 λ�õĻ�ľ�� 22����ô��λ�� 22 �Ļ�ľ�ƶ���λ�� 11 ��λ�� 11 �ϵĻ�ľ���µ�������Ϊ 1, 21, 2��

�����ʽ

��һ������ 22 ������ n, m(1 \le n \le 10000, 0 \le m \le 10000)n, m(1��n��10000, 0��m��10000)��

������ mm �У�ÿ������ 22 ������ a, b(1 \le a, b \le n)a, b(1��a, b��n)�����aa��bb ����򱾴β���Ҫ�ƶ���

�����ʽ

��� nn �У��� ii �����λ�� ii ���µ��ϵĻ�ľ��ţ��������û�л�ľ���һ�п��С�

��������1

2 2
1 2
1 2
�������1

1 2

��������2

4 4
3 1
4 3
2 4
2 2
�������2


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
        v[i].push_back(i+1);//���б��
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
