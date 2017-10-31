#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int n,m,k,t;
int map[25][25];
bool vis[25][25][25];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct Point
{
	int x,y;
	int step;
	int layer;
	Point(int x=1,int y=1,int step=0,int layer=0):x(x),y(y),step(step),layer(layer){} 
};
int ans(){
	queue<Point>Q;
	memset(vis,0,sizeof(vis));
	Point a(1,1,0,0);
	Point end_point(n,m);
	Q.push(a);
	vis[1][1][0]=true;
	while(!Q.empty()){
		Point now=Q.front();
		Q.pop();
		if(now.x==end_point.x&&now.y==end_point.y)
			return now.step;
			for(int i=0;i<4;i++){
				int x=dx[i]+now.x;
				int y=dy[i]+now.y;
				int layer=now.layer;
				if(map[x][y])
					layer++;//因为每次只会移动一步，而且遇到一面墙++
					 else
					 layer=0;
					if(layer<=k&&!vis[x][y][layer]&&x>=1&&y>=1&&x<=n&&y<=m)
					{
						vis[x][y][layer]=true;
						Q.push(Point(x,y,now.step+1,layer));
					}
					 
			} 
	}
	return -1;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;//输入行和列以及k值！
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>map[i][j];//输入地图
        cout<<ans()<<endl;
    }
    return 0;
}


