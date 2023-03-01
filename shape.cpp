// #include <iostream>
// #include <cmath>
// using namespace std;

// class IShape
// {
// public:
//     virtual double area() = 0;
//     virtual double circumference() = 0;
// };

// class Polygon : public IShape
// {
// protected:
//     int m_sides;

// public:
//     Polygon(int n) : m_sides(n) {}
// };

// class Circle : public IShape
// {
// private:
//     const static double PI;
//     double m_radius;

// public:
//     Circle(int r) : m_radius(r) {}
//     double area() override
//     {
//         return PI * m_radius * m_radius;
//     }
//     double circumference() override
//     {
//         return 2 * PI * m_radius;
//     }
// };

// const double Circle::PI = 22.0 / 7.0;

// class Rectangle : public Polygon
// {
// private:
//     int m_length;
//     int m_breadth;

// public:
//     Rectangle(int l, int b) : Polygon(4), m_length(l), m_breadth(b) {}
//     double area() override
//     {
//         return m_length * m_breadth;
//     }
//     double circumference() override
//     {
//         return 2 * (m_length + m_breadth);
//     }
// };

// class Triangle : public Polygon
// {
// private:
//     int m_a;
//     int m_b;
//     int m_c;

// public:
//     Triangle(int x, int y, int z) : Polygon(3), m_a(x), m_b(y), m_c(z) {}
//     double area() override
//     {
//         double s = (m_a + m_b + m_c) / 2.0;
//         return sqrt(s * (s - m_a) * (s - m_b) * (s - m_c));
//     }
//     double circumference() override
//     {
//         return m_a + m_b + m_c;
//     }
// };

// int main()
// {
//     IShape *shapes[] = {new Circle(3), new Rectangle(4, 5), new Triangle(3, 4, 5)};
//     for (int i = 0; i < 3; i++)
//     {
//         cout << "Shape " << i + 1 << " area: " << shapes[i]->area() << endl;
//         cout << "Shape " << i + 1 << " circumference: " << shapes[i]->circumference() << endl;
//     }
//     return 0;
// }
#include<iostream>
#include<cmath>
class IShape {
  public:
  virtual double area()=0;
  virtual double circumference()=0;
};
class Polygon:public IShape {
  int m_sides;
  public:
  Polygon(int n);   //no.of sides
};
class Circle : public IShape {
  double m_radius;

public:
  const double PI = 22.0/7.0;
  Circle(int r);
  double area();
  double circumference();
};
class Rectangle : public Polygon {
  int  m_length;
  int  m_breadth;

public:
  Rectangle(int l,int b);
  double area();
  double circumference();
};
class Triangle : public Polygon {
  int  m_a;
  int  m_b;
  int  m_c;

public:
  Triangle(int x,int y,int z);
  double area() ;
  double circumference();
};

Polygon::Polygon(int n):m_sides(n){}
Circle::Circle(int r):m_radius(r){}
double Circle::area(){
    return (PI*m_radius*m_radius);
}
double Circle::circumference(){
    return (2*PI*m_radius);
}
Rectangle::Rectangle(int l, int b):Polygon(2),m_length(l),m_breadth(b){}
double Rectangle::area(){
    return (m_length*m_breadth);
}
double Rectangle::circumference(){
    return (2*(m_length+m_breadth));
}
Triangle::Triangle(int x, int y, int z):Polygon(3),m_a(x),m_b(y),m_c(z){}
double Triangle::area(){
    double s=(m_a+m_b+m_c)/2;
    double res=sqrt(s*(s-m_a)*(s-m_b)*(s-m_c));
    return res;
}
double Triangle::circumference(){
    return (m_a+m_b+m_c);
    }

int main(){
    Circle c1(10);
    std::cout<<"Area of circle is: "<<c1.area()<<"\n";
    std::cout<<"Circumference of circle is: "<<c1.circumference()<<"\n";

    Rectangle r1(10,20);
    std::cout<<"Area of Rectangle is: "<<r1.area()<<"\n";
    std::cout<<"Circumference of Rectangle is: "<<r1.circumference()<<"\n";

    Triangle t1(3,4,5);
    std::cout<<"Area of Triangle is: "<<t1.area()<<"\n";
    std::cout<<"Circumference of Triangle is: "<<t1.circumference()<<"\n";

}