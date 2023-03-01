#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;


// class Fraction {
//     int m_numerator;
//     int m_denominator;

// public:
//     Fraction() : m_numerator(0), m_denominator(1) {}
//     Fraction(int num, int den) : m_numerator(num), m_denominator(den) {}
//     Fraction(int num) : m_numerator(num), m_denominator(1) {}

//     Fraction operator+(const Fraction& f2) {
//         int num = (m_numerator * f2.m_denominator) + (f2.m_numerator * m_denominator);
//         int den = m_denominator * f2.m_denominator;
//         return Fraction(num, den);
//     }

//     Fraction operator-(const Fraction& f2) {
//         int num = (m_numerator * f2.m_denominator) - (f2.m_numerator * m_denominator);
//         int den = m_denominator * f2.m_denominator;
//         return Fraction(num, den);
//     }

//     Fraction operator*(const Fraction& f2) {
//         int num = m_numerator * f2.m_numerator;
//         int den = m_denominator * f2.m_denominator;
//         return Fraction(num, den);
//     }

//     Fraction operator+(int value) {
//         return Fraction(m_numerator + (value * m_denominator), m_denominator);
//     }

//     Fraction operator-(int value) {
//         return Fraction(m_numerator - (value * m_denominator), m_denominator);
//     }

//     bool operator==(const Fraction& f2) {
//         return (m_numerator == f2.m_numerator && m_denominator == f2.m_denominator);
//     }

//     bool operator<(const Fraction& f2) {
//         return (m_numerator * f2.m_denominator < f2.m_numerator * m_denominator);
//     }

//     bool operator>(const Fraction& f2) {
//         return (m_numerator * f2.m_denominator > f2.m_numerator * m_denominator);
//     }

//     Fraction simplify() {
//         int gcd1 = abs(gcd(m_numerator, m_denominator));
//         return Fraction(m_numerator / gcd1, m_denominator / gcd1);
//     }

//     bool isSimplest() const {
//         return (abs(gcd(m_numerator, m_denominator)) == 1);
//     }

//     void display() const {
//         cout << m_numerator << "/" << m_denominator << endl;
//     }
//     friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
// };
//     std::ostream& operator<<(std::ostream& out, const Fraction& f) {
//     out << f.m_numerator << "/" << f.m_denominator;
//     return out;
// }
// int main() {
//     Fraction f1(5,6);
//     Fraction f2(7,8);

//     cout << "f1: " << f1 << endl;
//     cout << "f2: " << f2 << endl;

//     Fraction f3 = f1 + f2;
//     cout << "f1 + f2 = " << f3 << endl;

//     Fraction f4 = f1 - f2;
//     cout << "f1 - f2 = " << f4 << endl;

//     Fraction f5 = f1 * f2;
//     cout << "f1 * f2 = " << f5 << endl;

//     Fraction f6 = f1 + 1;
//     cout << "f1 + 1 = " << f6 << endl;

//     Fraction f7 = f1 - 1;
//     cout << "f1 - 1 = " << f7 << endl;

//     bool equal = (f1 == f2);
//     cout << "f1 == f2 is " << equal << endl;

//     bool lessThan = (f1 < f2);
//     cout << "f1 < f2 is " << lessThan << endl;

//     bool greaterThan = (f1 > f2);
//     cout << "f1 > f2 is " << greaterThan << endl;

//     Fraction f8 = f1.simplify();
//     cout << "Simplified fraction of f1: " << f8 << endl;

//     bool isSimplest = f1.isSimplest();
//     cout << "Is f1 simplest fraction? " << isSimplest << endl;

//     return 0;
// }
class Fraction {
  int m_numerator;
  int m_denominator;
  public:
  Fraction();
  Fraction(int,int);
  Fraction(int);
  Fraction operator+(const Fraction&);
  Fraction operator-(const Fraction&);
  Fraction operator*(const Fraction&);
  Fraction operator+(int);
  Fraction operator-(int);
  bool operator==(const Fraction&);
  bool operator<(const Fraction&);
  bool operator>(const Fraction&);
  Fraction simplify();
  bool isSimplest() const;
  void dispay() const;
  friend std::ostream& operator<<(const std::ostream&, const Fraction&);
};

Fraction::Fraction():m_numerator(1),m_denominator(1) {}
Fraction::Fraction(int num, int den):m_numerator(num),m_denominator(den){}
Fraction::Fraction(int num):m_numerator(num),m_denominator(1){}
Fraction Fraction::operator+(const Fraction& f){
    int num=(m_numerator*f.m_denominator)+(f.m_numerator*m_denominator);
    int den=m_denominator*f.m_denominator;
    return Fraction(num,den);
}
Fraction Fraction::operator-(const Fraction& f){
    int num=(m_numerator*f.m_denominator)-(f.m_numerator*m_denominator);
    int den=m_denominator*f.m_denominator;
    return Fraction(num,den);
}
Fraction Fraction::operator*(const Fraction& f){
    int num=(m_numerator*f.m_numerator);
    int den=m_denominator*f.m_denominator;
    return Fraction(num,den);
}
Fraction Fraction::operator+(int v){
    int res=m_numerator+(v*m_denominator);
    return (res,m_denominator);
}
bool Fraction::operator<(const Fraction& other){
    if ((m_numerator*other.m_denominator) < (m_denominator*other.m_numerator)){
        return true;
    }
}