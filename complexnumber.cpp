#include<iostream>
/*
class Complex {
  int m_real;
  int m_imag;

public:
  Complex() : m_real(0), m_imag(0) {}
  Complex(int real, int imag) : m_real(real), m_imag(imag) {}
  Complex(int real) : m_real(real), m_imag(0) {}
  Complex(const Complex& other) : m_real(other.m_real), m_imag(other.m_imag) {}
  ~Complex() {}

  Complex operator+(const Complex& other) {
    int treal = m_real+ other.m_real;
    int timg = m_imag+other.m_imag;
    return Complex(treal,timg);
  }

Complex operator-(const Complex& other) {
    int treal = m_real- other.m_real;
    int timg = m_imag-other.m_imag;
    return Complex(treal,timg);
}

Complex operator*(const Complex& other) {
    int treal = m_real * other.m_real - m_imag * other.m_imag;
    int timg = m_imag * other.m_real + m_real * other.m_imag;
    return Complex(treal,timg);
  }
Complex& operator++() {
    ++m_real;
    ++m_imag;
    return *this;
  }

  Complex operator++(int) {
    Complex temp(*this);
    ++(*this);
    return temp;
  }

  bool operator==(const Complex& other) {
    std::cout << "Real = "<<m_real << " Other = " <<other.m_real;
    std::cout << "img = "<<m_imag << " Other = " <<other.m_imag;
    return (m_real == other.m_real && m_imag == other.m_imag);
  }

  void display() const {
    std::cout << m_real << "+" << m_imag << "i\n";
  }
  friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};
    std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.m_real << "+" << complex.m_imag << "i";
    return os;
  }

int main() {
  Complex a(2, 3);
   Complex b(4, 5);
   Complex c;

  c = a + b;
  std::cout << "a + b = " << c << std::endl;

  c = a - b;
  std::cout << "a - b = " << c << std::endl;
  
  c = a * b;
  std::cout << "a * b = " << c << std::endl;

   ++a;
  std::cout << "After ++a = " << a << std::endl;

  c = a++;
  std::cout << "C = a++ : " << c << std::endl;

    std::cout << "\na = " << a << std::endl;

  std::cout << "\nb = " << b << std::endl;

  if (a == b) {
    std::cout << "a is equal to b" << std::endl;
  } else {
    std::cout << "a is not equal to b" << std::endl;
  }

  return 0;
}
*/
class Complex {
  int m_real;
  int m_imag;
  public:
  Complex();
  Complex(int,int);
  Complex(int);
  Complex operator+(const Complex&);
  Complex operator-(const Complex&);
  Complex operator*(const Complex&);
  Complex& operator++();
  Complex operator++(int);
  bool operator==(const Complex&);
  void display() const;
  friend std::ostream& operator<<(std::ostream&, const Complex&);
};
Complex::Complex():m_real(0),m_imag(0){}
Complex::Complex(int real, int imag):m_real(real),m_imag(imag){}
Complex::Complex(int real):m_real(real),m_imag(0){}
Complex Complex::operator+(const Complex& ref){
  int REAL=m_real+ref.m_real;
  int IMAG=m_imag+ref.m_imag;
  return Complex(REAL,IMAG);
}
Complex Complex::operator-(const Complex& ref){
  int REAL=m_real-ref.m_real;
  int IMAG=m_imag-ref.m_imag;
  return Complex(REAL,IMAG);
}
Complex Complex::operator*(const Complex& ref){
  int REAL=(m_real+ref.m_real)*(m_imag+ref.m_imag);
  int IMAG = (m_imag * ref.m_real) + (m_real * ref.m_imag);
  return Complex(REAL,IMAG);
}
Complex& Complex::operator++(){
  ++m_real;
  ++m_imag;
  return *this;
}
Complex Complex::operator++(int){
  Complex temp=(*this);
  ++(*this);
  return temp;
}
bool Complex::operator==(const Complex& ref){
  return(m_real==ref.m_real && m_imag == ref.m_imag);
}
void Complex::display() const{
  std::cout<<"real part is" << m_real<<"\n";
  std::cout<<"imaginary part is" << m_imag<<"\n";
}
std::ostream& operator<<(std::ostream& os, const Complex& complex){
  os << complex.m_real << "+  i"<<complex.m_imag<<"\n";
  return os;
  }
int main() {
  Complex a(2, 3);
   Complex b(4, 5);
   Complex c;

  c = a + b;
  std::cout << "a + b = " << c << std::endl;

  c = a - b;
  std::cout << "a - b = " << c << std::endl;
  
  c = a * b;
  std::cout << "a * b = " << c << std::endl;

   ++a;
  std::cout << "After ++a = " << a << std::endl;

  c = a++;
  std::cout << "C = a++ : " << c << std::endl;

  std::cout << "\na = " << a << std::endl;

  std::cout << "\nb = " << b << std::endl;

  if (a == b) {
    std::cout << "a is equal to b" << std::endl;
  } else {
    std::cout << "a is not equal to b" << std::endl;
  }

  return 0;
}