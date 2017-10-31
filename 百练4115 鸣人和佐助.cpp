#include<iostream>
#include<queue>
#include<cstring>
#define MAXN 250
using namespace std;
int M,N,T;
char G[MAXN][MAXN];
int W[MAXN][MAXN];//走到[i][j]需要的剩下的最大查克拉
typedef struct node
{
		int r,c,w,t;
		node(int rr,int cc,int ww,int tt) :r(rr),c(cc),w(ww),t(tt){}//?
}node;
queue<node> q;
int ans=1<<30;
int mr,mc;
int dir1[4]={0,1,0,-1};
int dir2[4]={1,0,-1,0};

void bfs()
{
	q.push(node(mr,mc,T,0));
	W[mr][mc]=T;
	while(!q.empty())
	{
		node t=q.front();
		if(G[t.r][t.c]=='+')
		{
				ans=t.t;return;
		}
		for(int i=0;i<4;i++)
		{
				int a = t.r+dir1[i];
				int b=t.c+dir2[i];
				if(a>=0&&b>=0&&a<M&&b<N&&t.w>W[a][b])//当前查克拉大于之前的记录
				 // 如果此时的所剩查克拉数还少于上一次所剩，那么肯定不是最优解，剪枝。
				 {
				 		if(G[a][b]=='#'&&t.w>0)//有敌人且有查克拉
						{
								q.push(node(a,b,t.w-1,t.t+1));
								W[a][b]=t.w-1;//更新查克拉量 
						 } 
						else if(G[a][b]=='*'||G[a][b]=='+')
						{
							q.push(node(a,b,t.w,t.t+1));
							W[a][b]=t.w;
						 } 
				 }
				  
		}
		q.pop();
		
	}
}
int main()
{
	cin >> M >> N >> T;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == '@')
			{
				mr = i; mc = j;
			}
		}
	memset(W, -1, sizeof(W));
	bfs();
	if (ans != 1 << 30)
		cout << ans;
	else
		cout << -1;
	system("pause");
	return 0;
}











