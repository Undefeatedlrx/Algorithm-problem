#include<iostream>
#include<cmath>
using namespace std;
class point
{
public:
	float x;//点横坐标
	float y;//点纵坐标
	friend float dis(point x1, point y1)//计算距离函数 非成员函数友元
	{
		return sqrt((x1.x - y1.x)*(x1.x - y1.x) + (x1.y - y1.y)*(x1.y - y1.y));
	}
	void set(int x1,int y1)
	{
		x=x1;
		y=y1;
	}
	point() {
		cout << "调用point构造函数" << endl;
	}//构造函数
	~point() {
		cout << "调用point析构函数" << endl;
	}//析构函数
};
class circle
{
private:
	point o;
	float r;
public:
	void set(point o1, float r1)
	{
		o = o1;
		r = r1;
	}
	circle() {
		cout << "调用square构造函数" << endl;
	}
	~circle() {
		cout << "调用square析构函数" << endl;
	}
	float sum(circle c)
	{
		return r+c.r;
	}
	void set(double r1)
	{
		r=r1;
		
	}


}; 
int main() {
	double r1,r2;
	circle c1, c2;
	point o1, o2;
	cout << "输入圆1的圆心坐标：" << endl;
	cin >> o1.x >> o1.y;
	cout << "输入圆2的圆心坐标：" << endl;
	cin >> o2.x >> o2.y;
	cout<<"两圆半径"<<endl;
	cin>>r1>>r2;
	c1.set(r1);
	c2.set(r2);
	o1.set(o1.x,o2.y);
	o2.set(o2.x,o2.y);
	if (c1.sum(c2) == dis(o1, o2))
		cout << "相切" << endl;
	else if (c1.sum(c2) < dis(o1, o2))
		cout << "相离" << endl;
	else
		cout << "相交" << endl;
	return 0;
}
