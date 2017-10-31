//poj3278 ץס��ͷţ
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N,K;
const int MAXN=100000;
int visited[MAXN+10];//���ر��,true��ʾi�Ѿ���չ��
struct step{
	int x;
	int steps;
	step(int xx,int s):x(xx),steps(s){};
};
queue<step>q;//����open��
int main()
{
	cin>>N>>K;
	memset(visited,0,sizeof(visited));
	q.push(step(N,0));
	visited[N]=1;
	while(!q.empty()){
		step s=q.front();
		if(s.x==K){//�ҵ�Ŀ��
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
