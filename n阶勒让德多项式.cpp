#include<iostream>
using namespace std;
int main()
{
  double p(double,double);
  double s,n,x;
  cout<<"请输入n与x的值：";
  cin>>n>>x;
  s=p(n,x);
  cout<<"则多项式的值为："<<s<<endl;
  return 0;
}
double p(double n,double x)
{
  double s;  // 函数名与变量名不能相同。
  if(n==0)
  {
    s=1;
  }
  else if(n==1)
  {
    s=x;
  }
  else
  {
    s=((2*n-1)*x-p((n-1),x)-(n-1)*p((n-2),x))/n;//递归。、
  }
  return s;
}
