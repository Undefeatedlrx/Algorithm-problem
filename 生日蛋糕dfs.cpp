#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int N,M;
int minArea =1 << 30;//最优表面积
int area=0;//正在搭建中的蛋糕表面积
void dfs(int v,int n,int r,int h)
{
	if(n==0)
			if(v) return;
			else{
				minArea=min(minArea,area);
				return;
			}
			if(v<=0)
				return;
			for(int rr=r;rr>=n;--rr)
			{
				if(n==M)
						area=rr*rr;
				for(int hh=h;h>=n;--hh){
					area+=2*rr*hh;
					dfs(v-rr*rr*hh,n-1,rr-1,hh-1);
					area-=2*rr*hh;
				}
			}
}
int main()
{
	dfs(N,M,maxR,maxH);
	if(minArea==1<<30)
			cout<<0<<endl;
	else	
			cout<<minArea<<endl;
}
