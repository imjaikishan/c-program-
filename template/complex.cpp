#include<iostream>

using namespace std;


// template<typename T> class Complex
// {
//     T m_real;
//     T m_imag;

//     public:

//     Complex();
//     Complex(T real, T imag);
//     //T gety() const;
//     //T getx() const;
//     void display() const;

// };

// template< typename T> 
// Complex<T> :: Complex(T real, T imag) : m_real(real), m_imag(imag){}

// template<typename T> 
// void Complex<T> :: display() const{

//        cout << m_real;
//     if (m_imag >= 0) {
//         cout << "+";
//     }
//         cout << m_imag << "i" << endl;
// }

// template <typename T>
// Complex<T>::Complex() : m_real(0), m_imag(0)
// {
// }


// int main()
// {


// Complex<int> s1(20,30);

// s1.display();

// }
#include<iostream>
using namespace std;
template<typename T>
class Complex {
  T m_real;
  T m_image;
  public:
  Complex();
  Complex(T,T);
  void display();
};

template<typename T>
Complex<T>::Complex():m_real(0),m_image(0){}

template <typename T>
Complex<T>::Complex(T real, T imag):m_real(real),m_image(imag){}

template <typename T>
void Complex<T>::display(){
    cout << m_real << "+ i" << m_image;    
}
int main()
{
Complex<int> s1(20,30);
s1.display();
return 0;
}
