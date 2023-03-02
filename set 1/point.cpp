#include<iostream>
#include<cmath>
enum Quadrant {
  Q1,
  Q2,
  Q3,
  Q4
};

class Point {
  int m_x;
  int m_y;
  public:
  Point();
  Point(int,int);
  Point(const Point&);
  double distanceFromOrigin()  const;
  Quadrant quadrant() const;
  bool isOrigin() const;
  bool isOnXAxis() const;
  bool isOnYAxis() const;
  void display() const;
};
Point::Point():m_x(10),m_y(20){}
Point::Point(int x,int y):m_x(x),m_y(y){}
Point::Point(const Point& ref):m_x(ref.m_x),m_y(ref.m_y){}
double Point ::distanceFromOrigin() const 
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}
Quadrant Point::quadrant() const{
    if(m_x >0 && m_y >0)
        return Q1;
    else if (m_x <0 && m_y >0)
    {
        return Q2;
    }
    else if (m_x <0 && m_y <0)
    {
        return Q3;
    }
    else if(m_x >0 && m_y <0){
        return Q4;
    }
    else
    {
        return Q1;
    }
}
bool Point::isOrigin() const{
    return (m_x==0 && m_y==0);
}
bool Point::isOnXAxis() const{
    return (m_y==0);
}
bool Point::isOnYAxis() const{
    return (m_x==0);
}
void Point::display() const{
    std::cout << "x-axis:" << m_x << ",y-axis:" << m_y << std::endl; 
};
int main() {
    Point p1;
    p1.display();
    std::cout << "distance from origin: " << p1.distanceFromOrigin() << std::endl;
    std::cout << "lies in quadrant: " << p1.quadrant() << std::endl;
    std::cout << "point is on origin or not: " << p1.isOrigin() << std::endl;
    std::cout << "point is on x axis or not: " << p1.isOnXAxis() << std::endl;
    std::cout << "point is on y axis or not: " << p1.isOnYAxis() << std::endl;

    Point p2(0, 4);
    p2.display();
    std::cout << "distance from origin: " << p2.distanceFromOrigin() << std::endl;
    std::cout << "lies in quadrant: " << p2.quadrant() << std::endl;
    std::cout << "point is on origin or not: " << p2.isOrigin() << std::endl;
    std::cout << "point is on x axis or not: " << p2.isOnXAxis() << std::endl;
    std::cout << "point is on y axis or not: " << p2.isOnYAxis() << std::endl;
    Point p3(p2);
    p3.display();
    return 0;
}
