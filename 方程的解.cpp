#include <iostream> 
using namespace std; 
int main()
{
	int a,b,c;
	for(a=0;a<=31;a++)
		for(b=a+1;b<=31;b++)
			for(c=b+1;c<=31;c++)
			{
				if(a*a+b*b+c*c==1000)
				cout<<a <<b <<c<<endl;
			}
}
