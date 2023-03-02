// #include<iostream>
// using namespace std;
// #include <math.h>


// enum Quardrant
// {
//     Q1=1,
//     Q2=2,
//     Q3=3,
//     Q4=4
//     };

// template<typename T>
// class Point{
//     T m_x;
//     T m_y;
//     public:
    
//     Point();
//     Point(T, T);
//     void distanceFromOrigin();
//     Quardrant quardant();
//     void display();
// };

// template <typename T>
//    Point<T>::Point() : m_x(0), m_y(0)
//    {
//    }


// template <typename T>
//    Point<T>::Point(T x, T y) : m_x(x), m_y(y)
//    {
//    }

//    template <typename T>
//    void Point<T>::distanceFromOrigin()
//    {
//      T distance = sqrt(m_x * m_x + m_y * m_y);
//        cout << "Distance from origin: " << distance << endl;
//    }

//    template <typename T>
//    Quardrant Point<T>::quardant()
//    {   
//     if (m_x > 0 && m_y > 0) {
//       return Q1;
//     }
//     else if (m_x < 0 && m_y > 0) {
//       return Q2;
//     }
//     else if (m_x < 0 && m_y < 0) {
//       return Q3;
//     }
//     else if (m_x > 0 && m_y < 0) {
//       return Q4;
//     }
//     else
//     {
//       // Point is on one of the axes
//       return Q1;
//     }

//    }

//    template <typename T>
//    void Point<T>::display()
//    {

//     cout << "(" << m_x << ", " << m_y << ")" << endl;
//    }


// int main()
    
// {


//   Point<int> p1(3, 4);
//   cout << "Point 1: ";
//   p1.display();
//   cout << "Quadrant: " << p1.quardant() << endl;
//   p1.distanceFromOrigin();
  
//   Point<double> p2(1.5, -2.5);
//   cout << "Point 2: ";
//   p2.display();
//   cout << "Quadrant: " << p2.quardant() << endl;
//   p2.distanceFromOrigin();
  
//   return 0;
// }
#include<iostream>
#include<cmath>
enum Quadrant {
  Q1,
  Q2,
  Q3,
  Q4,
};
template<typename T>
class Point {
  T m_x;
  T m_y;
  public:
  Point();
  Point(T,T);
  void distanceFromOrigin();
  Quadrant quadrant();
  void display();
};

template<typename T>
Point<T> :: Point():m_x(0),m_y(0){}

template<typename T>
Point<T> :: Point(T x, T y):m_x(x),m_y(y){}

template<typename T>
void Point<T>::distanceFromOrigin(){
  T distance = sqrt(m_x * m_x + m_y * m_y);
  std::cout<<"distance from origin is: " << distance << "\n";
}

template<typename T>
Quadrant Point<T>::quadrant(){
  if(m_x>0 && m_y>0){
    return Q1;
  }
  else if(m_x<0 && m_y>0){
    return Q2;
  }
  else if(m_x<0 && m_y<0){
    return Q3;
  }
  else if(m_x>0 && m_y<0){
    return Q4;
  }
  else{
    return Q1;
  }
}
template <typename T>
void Point<T>::display(){
  std::cout << "(" << m_x << "," << m_y <<")" << "\n";
}
int main()
{
  Point<int> p1(3, 4);
  std::cout << "Point 1: ";
  p1.display();
  std::cout << "Quadrant: " << p1.quadrant() << "\n";
  p1.distanceFromOrigin();
  
  Point<double> p2(1.5, -2.5);
  std::cout << "Point 2: ";
  p2.display();
  std::cout << "Quadrant: " << p2.quadrant() << "\n";
  p2.distanceFromOrigin();
  
  return 0;
}