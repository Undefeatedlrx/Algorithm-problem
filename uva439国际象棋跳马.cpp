#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>

using namespace std;
typedef struct qnode
{
	int x,y,d;
	qnode(int a,int b,int c){x=a;y=b;d=c;}
	qnode(){}
}queue;
queue Q[90];

int maps[9][9];
int d[8][2]={{2,1},{2,-1},{-1,2},{1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};

int bfs(int x,int y,int xx,int yy)
{
	if(x==xx&&y==yy) return 0;
	memset(maps,0,sizeof(maps));
	int move=0,save=1;
	Q[0]=queue(x,y,0);
	while(move<save){
		queue now=Q[move ++];
		for(int k=0;k<8;++k){
			x=now.x+d[k][0];
			y=now.y+d[k][1];
			if(!maps[x][y] && x > 0 && x < 9 && y > 0 && y < 9){
				if(x==xx&&y==yy)
					return now.d+1;
				Q[save++]=queue(x,y,now.d+1);
				maps[x][y]=1;
			}
		}
	}
	return -1;
}

int main()
{
	char ch1,ch2;  
    int  x1,x2,y1,y2;  
    while ( cin >> ch1 >> y1 >> ch2 >> y2 ) {  
        x1 = (int)(ch1-'a'+1);  
        x2 = (int)(ch2-'a'+1);  
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,y1,ch2,y2,bfs( x1 , y1, x2, y2 ));  
    }  
}
 
