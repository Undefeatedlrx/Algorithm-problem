#include <iostream>
using namespace std;
int main() 
{
	for(int i=1;i<10;i++)
	{
		for(int j=i;j<10;j++)
		{
			cout<<i<<'*'<<j<<'='<<i*j<<'\t';
		}
		cout<<'\n';
		for(int k=i;k>0;k--)
			cout<<'\t';
	}
}
