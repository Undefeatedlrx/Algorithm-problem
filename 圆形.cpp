#include<iostream>
#include<cmath>
using namespace std;
class point
{
public:
	float x;//�������
	float y;//��������
	friend float dis(point x1, point y1)//������뺯�� �ǳ�Ա������Ԫ
	{
		return sqrt((x1.x - y1.x)*(x1.x - y1.x) + (x1.y - y1.y)*(x1.y - y1.y));
	}
	void set(int x1,int y1)
	{
		x=x1;
		y=y1;
	}
	point() {
		cout << "����point���캯��" << endl;
	}//���캯��
	~point() {
		cout << "����point��������" << endl;
	}//��������
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
		cout << "����square���캯��" << endl;
	}
	~circle() {
		cout << "����square��������" << endl;
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
	cout << "����Բ1��Բ�����꣺" << endl;
	cin >> o1.x >> o1.y;
	cout << "����Բ2��Բ�����꣺" << endl;
	cin >> o2.x >> o2.y;
	cout<<"��Բ�뾶"<<endl;
	cin>>r1>>r2;
	c1.set(r1);
	c2.set(r2);
	o1.set(o1.x,o2.y);
	o2.set(o2.x,o2.y);
	if (c1.sum(c2) == dis(o1, o2))
		cout << "����" << endl;
	else if (c1.sum(c2) < dis(o1, o2))
		cout << "����" << endl;
	else
		cout << "�ཻ" << endl;
	return 0;
}
