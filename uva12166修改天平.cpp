#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<long long,int>a;
int sum;
string line;
void dfs(int d,int s,int l)
{
    if(line[s]=='[')
    {
        int p=0;
        for(int i=s+1;i!=l;++i)
        {
            if(line[i]=='[')
                ++p;
            if(line[i]==']')
                --p;
            if(p==0&&line[i]==',')
            {
                dfs(d+1,s+1,i-1);
                dfs(d+1,i+1,l-1);
            }
        }
    }
    else
    {
        long long w=0;
        for(int i=s;i<=l;++i)
            w=w*10+line[i]-'0';
        ++sum,++a[w<<d];
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>line;
        a.clear();
        sum=0;
        dfs(0,0,line.size()-1);
        int maxn=0;
        map<long long,int>::iterator it;
        for(it=a.begin();it!=a.end();it++)
            maxn=max(maxn,it->second);
        cout<<sum-maxn<<endl;
    }
}
