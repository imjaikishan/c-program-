// #include <iostream>

// class Distance {
//   int m_feets;
//   int m_inches;
// public:
//   Distance() : m_feets(0), m_inches(0) {}
//   Distance(int feet, int inches) : m_feets(feet), m_inches(inches) {}
//   Distance(int totalInches) : m_feets(totalInches / 12), m_inches(totalInches % 12) {}
  
//   Distance operator+(const Distance& other) {
//     int totalInches = (m_feets + other.m_feets) * 12 + m_inches + other.m_inches;
//     return Distance(totalInches);
//   }
  
//   Distance operator-(const Distance& other) {
//     int totalInches = (m_feets - other.m_feets) * 12 + m_inches - other.m_inches;
//     return Distance(totalInches);
//   }
  
//   Distance operator+(int inches) {
//     int totalInches = m_feets * 12 + m_inches + inches;
//     return Distance(totalInches);
//   }
  
//   Distance operator-(int inches) {
//     int totalInches = m_feets * 12 + m_inches - inches;
//     return Distance(totalInches);
//   }
  
//   Distance& operator++() {
//     m_inches++;
//     if (m_inches >= 12) {
//       m_feets++;
//       m_inches -= 12;
//     }
//     return *this;
//   }
  
//   Distance operator++(int) {
//     Distance temp(m_feets, m_inches);
//     ++(*this);
//     return temp;
//   }
  
//   bool operator==(const Distance& other) {
//     return (m_feets == other.m_feets && m_inches == other.m_inches);
//   }
  
//   bool operator<(const Distance& other) {
//     int totalInches1 = m_feets * 12 + m_inches;
//     int totalInches2 = other.m_feets * 12 + other.m_inches;
//     return totalInches1 < totalInches2;
//   }
  
//   bool operator>(const Distance& other) {
//     int totalInches1 = m_feets * 12 + m_inches;
//     int totalInches2 = other.m_feets * 12 + other.m_inches;
//     return totalInches1 > totalInches2;
//   }
  
//   void dispay() const {
//     std::cout << m_feets << " feet " << m_inches << " inches";
//   }
  
//   friend std::ostream& operator<<(std::ostream& out, const Distance& d);
//   }; 
//   std::ostream& operator<<(std::ostream& out, const Distance& d){
//     out << d.m_feets << " feet " << d.m_inches << " inches";
//     return out;
//   }


// int main() {
//   Distance d1(4,10);
//   Distance d2(3,20);
  
//   Distance d3 = d1 + d2;
//   std::cout << "d1 + d2 = " << d3 << std::endl;
  
//   Distance d4 = d1 - d2;
//   std::cout << "d1 - d2 = " << d4 << std::endl;
  
//   Distance d5 = d1 + 10;
//   std::cout << "d1 + 10 = " << d5 << std::endl;
  
//   Distance d6 = d1 - 10;
//   std::cout << "d1 - 10 = " << d6 << std::endl;
  
//   std::cout << "d1 before increment: " << d1 << std::endl;
//   d1++;
//   std::cout << "d1 after increment: " << d1 << std::endl;
  
//   std::cout << "Is d1 equal to d2? " << (d1 == d2 ? "yes" : "no") << std::endl;
//   std::cout << "Is d1 greater than d2? " << (d1 > d2 ? "yes" : "no") << std::endl;
//   std::cout << "Is d1 less than d2? " << (d1 < d2 ? "yes" : "no") << std::endl;
  
//   return 0;
// }
#include<iostream>
class Distance {
  int m_feets;
  int m_inches;
  public:
  Distance();
  Distance(int,int);
  Distance(int);
  Distance operator+(const Distance&);
  Distance operator-(const Distance&);
  Distance operator+(int);
  Distance operator-(int);
  Distance& operator++();
  Distance operator++(int);
  bool operator==(const Distance&);
  bool operator<(const Distance&);
  bool operator>(const Distance&);
  void display() const;
  friend std::ostream& operator<<(std::ostream&, const Distance&);
};

Distance::Distance():m_feets(0),m_inches(0){}
Distance::Distance(int feet, int inch):m_feets(feet),m_inches(inch){}
Distance::Distance(int totalinch):m_feets(totalinch/12),m_inches(totalinch%12){}
Distance Distance::operator+(const Distance& ref){
  int totalinch=(m_feets+ref.m_feets)*12+(m_inches+ref.m_inches);
  return Distance(totalinch);
}
Distance Distance::operator-(const Distance& ref){
  int totalinch=(m_feets-ref.m_feets)*12-(m_inches-ref.m_inches);
  return Distance(totalinch);
}

Distance Distance::operator+(int inch){
  int total=m_feets*12+m_inches+ inch;
  return Distance(total); 
}

Distance Distance::operator-(int inch){
  int total=m_feets*12+m_inches- inch;
  return Distance(total);
}
Distance& Distance::operator++(){
  ++m_inches;
  if(m_inches>=12){
    ++m_feets;
    m_inches-=12;
  }
  return *this;
}
Distance Distance::operator++(int){
  // Distance temp=*this;
  // ++(*this);
  // return temp;
  Distance temp(*this);
  ++(*this);
  return temp;
}

bool Distance::operator==(const Distance& other){
  if ((m_feets=other.m_feets) && (m_inches==other.m_inches)){
    return true;
  }
}
bool Distance::operator<(const Distance& other){
  int t1=m_feets*12+m_inches;
  int t2=other.m_feets*12+other.m_inches;
  if (t1<t2){
    return true;
  }
}

bool Distance::operator>(const Distance& other){
  int t1=m_feets*12+m_inches;
  int t2=other.m_feets*12+other.m_inches;
  if (t1>t2){
    return true;
  }
}
std::ostream& operator<<(std::ostream& os, const Distance& distance) {
  os << "feets " << distance.m_feets << " and inches " << distance.m_inches;
  return os;
}

int main() {
  Distance d1(4,10);
  Distance d2(3,20);
  
  Distance d3 = d1 + d2;
  std::cout << "d1 + d2 = " << d3 << std::endl;
  
  Distance d4 = d1 - d2;
  std::cout << "d1 - d2 = " << d4 << std::endl;
  
  Distance d5 = d1 + 10;
  std::cout << "d1 + 10 = " << d5 << std::endl;
  
  Distance d6 = d1 - 10;
  std::cout << "d1 - 10 = " << d6 << std::endl;
  
  std::cout << "d1 before increment: " << d1 << std::endl;
  d1++;
  std::cout << "d1 after increment: " << d1 << std::endl;
  
  std::cout << "Is d1 equal to d2? " << (d1==d2 ? " YES" : "no") << std::endl;
  std::cout << "Is d1 greater than d2? " << (d1 > d2 ? "yes" : "no") << std::endl;
  std::cout << "Is d1 less than d2? " << (d1 < d2 ? "yes" : "no") << std::endl;
  
  return 0;
}