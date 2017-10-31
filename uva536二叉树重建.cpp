#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char>post;
string pre,mid;
void TL(int L1,int R1,int L2,int R2)
{
//当遍历到最后一个时L1=R1,L2=R2
//且L1的传值比R1大 
	if(R1<L1)
		return;
	post.push_back(pre[L1]);//将根按顺序存在数组里
	int q=L2;
	while(pre[L1]!=mid[q]) q++;//在中序中找到根
	int cnt=q-L2;//遍历的个数
	//首先遍历右子树
	TL(L1+cnt+1,R1,q+1,R2);
	TL(L1+1,L1+cnt,12,q-1); 
}
int main()
{
    while(cin >> pre >> mid)
    {
        post.clear();
        TL(0, pre.size()-1, 0, mid.size()-1);
        //倒序输出
        for(int i = post.size() - 1; i >= 0; i--)
        {
            cout << post[i];
        }
        cout << endl;
    }
    return 0;
}
