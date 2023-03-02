#include<iostream>
class Box {
 int m_length;
 int m_breadth;
 int m_height;
 public:
 Box();
 Box(int,int,int);
 Box(int);
 Box(const Box&);
 int length() const;
 int breadth() const;
 int height() const;
 int volume() const;
 void dispay() const;
};
Box::Box():m_length(0),m_height(0),m_breadth(0){}
Box::Box(int l,int b,int h):m_length(l),m_breadth(b),m_height(h){}
Box::Box(int l):m_length(l),m_breadth(0),m_height(0){}
Box::Box(const Box& ref):m_length(ref.m_length),m_breadth(ref.m_breadth),m_height(ref.m_height){}
int Box::length() const{
    return m_length;
}
int Box::breadth() const{
    return m_breadth;
}
int Box::height() const{
    return m_height;
}
void Box::dispay() const{
    std::cout << "length:" << m_length << std::endl;
    std::cout << "breadth:" << m_breadth << std::endl;
    std::cout << "height:" << m_height << std::endl;
}
int Box::volume() const{
    return (m_length*m_breadth*m_height);
}
int main()
{
    std::cout<<"box 1:\n";
    Box b1;
    b1.dispay();
    b1.volume();
    std::cout<<"box 2:\n";
    Box b2(2,3,4);
    b2.dispay();
    std::cout<<"box 3:\n";
    Box b3(3);
    b3.dispay();
    return 0;
}