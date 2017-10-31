#include<iostream>
using namespace std;
#define Qsize 50
int a[5][5];
//���Թ������x���y��
//int dx[4]={-1,1,0,0};//x�᷽���ϵı仯
//int dy[4]={0,0,-1,1};//y�᷽���ϵı仯
int dis[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//�����ĸ�����
struct Node{
	int x,y,pre;
}queue[Qsize];//����һ��50�����ӵ�����
int front=0;
int rear=0;//���ö�ͷ�Ͷ�β
int vis[5][5];//�������

void bfs(int beginx,int beginy,int endx,int endy){
	queue[0].x=beginx,queue[0].y=beginy,queue[0].pre=-1;
	rear=rear+1;
	vis[beginx][beginy]=1;
	while(front<rear){//������в�Ϊ�� 
		for(int i=0;i<4;i++){//����4���ɴ�ķ��� 
			int newx=queue[front].x+dis[i][0];
			int newy=queue[front].y+dis[i][1];
			if(newx<0||newx>5||newy<0||newy>5||a[newx][newy]==1||vis[newx][newy]==1)//�Ƿ����Թ��ڣ��Ƿ�ײǽ���Ƿ����߹�
			 continue;
			 //����
			 queue[rear].x=newx;
			 queue[rear].y=newy;
			 queue[rear].pre=front;
			 rear++;
			   vis[newx][newy]=1;//���߹���λ�������  
            if(newx==endx&&newy==endy){  
                return;  
            }
	}
	front++;//���� 
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
   //��ʼ���Թ�  
   for(int i=0;i<5;i++){  
       for(int j=0;j<5;j++){  
            cin>>a[i][j];  
       }        
   }  
   bfs(0,0,4,4);  
   print(queue[rear-1]);  
   return 0;  
}  

