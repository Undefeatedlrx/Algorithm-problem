#include<iostream>
using namespace std;
int main()
{
  double p(double,double);
  double s,n,x;
  cout<<"������n��x��ֵ��";
  cin>>n>>x;
  s=p(n,x);
  cout<<"�����ʽ��ֵΪ��"<<s<<endl;
  return 0;
}
double p(double n,double x)
{
  double s;  // �������������������ͬ��
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
    s=((2*n-1)*x-p((n-1),x)-(n-1)*p((n-2),x))/n;//�ݹ顣��
  }
  return s;
}
