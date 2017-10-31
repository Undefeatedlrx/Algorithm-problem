#include <iostream>

#include <cstdio>
#include <cstring>
using namespace std;
int zhi[1000][1000];
int dp[1000][1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a;
            cin>>a;
            zhi[i][j]=zhi[i-1][j]+a;
        }
         int sum=0;
         int maxi=-5005;
         int maxm=-5005;
         int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum=-1;
            for(int r=1;r<=m;r++)
            {
                int k=zhi[j][r]-zhi[i][r];
                if(sum>0)
                    sum+=k;
                else
                {
                    sum=k;
                    if(!flag&&maxi<sum) maxi=sum,flag=1;
                }
                if(sum>maxm)
                {
                    maxm=sum;
                    flag=1;
                }
            }
        }
    }
    if(!flag)
        maxm=maxi;
    printf("%d\n",maxm );
}
