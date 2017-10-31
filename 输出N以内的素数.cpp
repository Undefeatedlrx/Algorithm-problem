#include <iostream>

#include <cmath>
using namespace std;
bool prime(int x)
{
     int y;
     for(y=2;y<=sqrt(x);y++)
         if (x%y==0)
            return false;
     return true;
}
int main ()
{
    int n,i;
    cin>>n;

    if(n>=2)
        cout<<"2 ";
    for(i=3;i<=n;i++)
        if (prime(i))
            cout<<i<<" ";

    return 0;
}
