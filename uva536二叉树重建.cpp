#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char>post;
string pre,mid;
void TL(int L1,int R1,int L2,int R2)
{
//�����������һ��ʱL1=R1,L2=R2
//��L1�Ĵ�ֵ��R1�� 
	if(R1<L1)
		return;
	post.push_back(pre[L1]);//������˳�����������
	int q=L2;
	while(pre[L1]!=mid[q]) q++;//���������ҵ���
	int cnt=q-L2;//�����ĸ���
	//���ȱ���������
	TL(L1+cnt+1,R1,q+1,R2);
	TL(L1+1,L1+cnt,12,q-1); 
}
int main()
{
    while(cin >> pre >> mid)
    {
        post.clear();
        TL(0, pre.size()-1, 0, mid.size()-1);
        //�������
        for(int i = post.size() - 1; i >= 0; i--)
        {
            cout << post[i];
        }
        cout << endl;
    }
    return 0;
}
