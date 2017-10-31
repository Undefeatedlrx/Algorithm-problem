//poj3278 抓住这头牛
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N,K;
const int MAXN=100000;
int visited[MAXN+10];//判重标记,true表示i已经拓展过
struct step{
	int x;
	int steps;
	step(int xx,int s):x(xx),steps(s){};
};
queue<step>q;//队列open表
int main()
{
	cin>>N>>K;
	memset(visited,0,sizeof(visited));
	q.push(step(N,0));
	visited[N]=1;
	while(!q.empty()){
		step s=q.front();
		if(s.x==K){//找到目标
			cout<<s.steps<<endl;
			return 0; 
		}
		else {
			if(s.x - 1 >= 0&& !visited[s.x-1]){
				q.push(step(s.x*2,s.steps+1));
				visited[s.x-1]=1;
				
			}
			else {
				if(s.x-1>=0&&!visited[s.x-1]){
					q.push(step(s.x-1,s.steps+1));
					visited[s.x-1]=1;
					
				}
				if(s.x+1<=MAXN&&!visited[s.x+1]){
					q.push(step(s.x+1,s.steps+1));
					visited[s.x+1]=1;
				}
			}
			
		}
	}
 } 
