#include <iostream>
#include <cstdlib>
#include<cmath>
using namespace std;
class Point {
  private:
    float x,y;
  public:
    Point(float _x=0,float _y=0):x(_x),y(_y) {};
    Point(Point &p):x(p.x),y(p.y) {};
    ~Point() {};
    float disX(const Point &b) {
        return b.x-x;
    };
    float disY(const Point &b) {
        return b.y-y;
    }
    float dis(const Point &b) {
        return sqrt((b.x -x)*(b.x -x)+(b.y-y)*(b.y-y));
    }
};

class Rectangle {
  private:
    Point a,b;
  public:
    Rectangle(Point _a,Point _b):a(_a),b(_b) {};
    Rectangle(float ax=0,float ay=0,float bx=1,float by=1):a(ax,ay),b(bx,by) {}
    Rectangle(Rectangle &r):a(r.a),b(r.b) {};
    ~Rectangle() {
    };
    float area() {
        return abs(a.disX(b)*a.disY(b));
    };
};

int main() {
	
    cout<<"请输入矩形的左上角和右下角坐标"<<endl;
    float ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    Point a(ax,ay), b(bx, by);    
    Rectangle myRectangle(ax,ay,bx,by);
    cout<<"该矩形的面积为"<<myRectangle.area()<<endl;
    cout<<"两点间的距离为"<<a.dis(b)<<endl;
    system("pause");
    return 0;
}
