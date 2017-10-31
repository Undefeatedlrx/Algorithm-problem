#include<iostream>
using namespace std;
#define Qsize 50
int a[5][5];
//把迷宫想象成x轴和y轴
//int dx[4]={-1,1,0,0};//x轴方向上的变化
//int dy[4]={0,0,-1,1};//y轴方向上的变化
int dis[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//定义四个方向
struct Node{
	int x,y,pre;
}queue[Qsize];//设置一个50个格子的子列
int front=0;
int rear=0;//设置队头和队尾
int vis[5][5];//标记数组

void bfs(int beginx,int beginy,int endx,int endy){
	queue[0].x=beginx,queue[0].y=beginy,queue[0].pre=-1;
	rear=rear+1;
	vis[beginx][beginy]=1;
	while(front<rear){//如果队列不为空 
		for(int i=0;i<4;i++){//搜索4个可达的方向 
			int newx=queue[front].x+dis[i][0];
			int newy=queue[front].y+dis[i][1];
			if(newx<0||newx>5||newy<0||newy>5||a[newx][newy]==1||vis[newx][newy]==1)//是否在迷宫内，是否撞墙，是否已走过
			 continue;
			 //进队
			 queue[rear].x=newx;
			 queue[rear].y=newy;
			 queue[rear].pre=front;
			 rear++;
			   vis[newx][newy]=1;//给走过的位置做标记  
            if(newx==endx&&newy==endy){  
                return;  
            }
	}
	front++;//出队 
}
}
void print(Node now){
	 if(now.pre==-1)  
        cout<<"("<<now.x<<", "<<now.y<<")"<<endl;  
    else{  
        print(queue[now.pre]);  
        cout<<"("<<now.x<<", "<<now.y<<")"<<endl;  
    }  
}
int main(){    
   //初始化迷宫  
   for(int i=0;i<5;i++){  
       for(int j=0;j<5;j++){  
            cin>>a[i][j];  
       }        
   }  
   bfs(0,0,4,4);  
   print(queue[rear-1]);  
   return 0;  
}  

