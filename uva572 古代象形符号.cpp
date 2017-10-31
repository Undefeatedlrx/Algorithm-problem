#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
const int maxn=200+10;
using namespace std;
int g[maxn][maxn];
int n,m,cnt;
int num[6];
char st[6]={'A','D','J','K','S','W'};
char str[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int s[16][4]=
{
    {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
    {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
    {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
    {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
};//十六进制对应的二进制
bool is_in(int x,int y)
{
    if(x>=0&&x<=n+1&&y>=0&&y<=m+1)
        return true;
    return false;
}
void dfs(int x,int y)
{
    if(!is_in(x,y)||g[x][y]!=0)
        return;
    g[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

void dfs2(int x,int y)
{
    if(!is_in(x,y)||g[x][y]==-1)
        return;
    if(!g[x][y])
    {
        dfs(x,y);
        cnt++;
        return;
    }
    g[x][y]=-1;
    dfs2(x+1,y);
    dfs2(x-1,y);
    dfs2(x,y-1);
    dfs2(x,y+1);
}

int main()
{
    int ca=1;
    while(scanf("%d%d",&n,&m) == 2&&n+m)
    {
        memset(g,0,sizeof(g));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            getchar();
            char ch;
            int len=1;
            for(int j=0;j<m;j++)
            {
                scanf("%c",&ch);
                for(int k=0;k<16;k++)
                    if(ch==str[k])
                    {
                        for(int l=0;l<4;l++)
                            g[i][len++]=s[k][l];
                        break;
                    }
            }
        }
        m*=4;
        dfs(0,0);//标记周围
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(g[i][j]==1)
                {
                    cnt=0;
                    dfs2(i,j);//遍历连通块
                    if(!cnt) num[5]++;
                    else if(cnt==1) num[0]++;
                    else if(cnt==2) num[3]++;
                    else if(cnt==3) num[2]++;
                    else if(cnt==4) num[4]++;
                    else num[1]++;
                }
        printf("Case %d: ",ca++);
        for(int i=0;i<6;i++)
            while(num[i]--)
                printf("%c",st[i]);
        puts("");
    }
    return 0;
}

