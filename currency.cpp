#include <iostream>

// class Currency{
//     int m_rupees;
//     int m_paise;

// public:
// Currency() : m_rupees(0), m_paise(0) {}
// Currency(int rupees, int paise) : m_rupees(rupees), m_paise(paise) {}
// Currency(int rupees) : m_rupees(rupees), m_paise(0) {}

// Currency operator+(const Currency& other) {
//     int rupees = m_rupees + other.m_rupees;
//     int paise = m_paise + other.m_paise;
//     rupees += paise / 100;
//     paise = paise % 100;
//     return Currency(rupees, paise);
// }

// Currency operator-(const Currency& other) {
//     int rupees = m_rupees - other.m_rupees;
//     int paise = m_paise - other.m_paise;
//     rupees -= paise / 100;
//     paise = paise % 100;
//     return Currency(rupees, paise);
// }

// Currency operator+(int value) {
//     return Currency(m_rupees + value, m_paise);
// }

// Currency operator-(int value) {
//     return Currency(m_rupees - value, m_paise);
// }

// Currency& operator++() {
//     m_rupees++;
//     return *this;
// }

// Currency operator++(int) {
//     Currency temp = *this;
//     m_rupees++;
//     return temp;
// }

// bool operator==(const Currency& other) {
//     return (m_rupees == other.m_rupees) && (m_paise == other.m_paise);
// }

// bool operator<(const Currency& other) {
//     if (m_rupees < other.m_rupees) {
//         return true;
//     } else if (m_rupees == other.m_rupees && m_paise < other.m_paise) {
//         return true;
//     } else {
//         return false;
//     }
// }

// bool operator>(const Currency& other) {
//     if (m_rupees > other.m_rupees) {
//         return true;
//     } else if (m_rupees == other.m_rupees && m_paise > other.m_paise) {
//         return true;
//     } else {
//         return false;
//     }
// }

// void display() const {
//     std::cout << m_rupees << " rupees and " << m_paise << " paise" << std::endl;
// }
// friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
// };

// std::ostream& operator<<(std::ostream& os, const Currency& currency) {
//     os << currency.m_rupees << " rupees and " << currency.m_paise << " paise";
//     return os;
// }

// int main() {
//     Currency c1(10, 50);  // 10 rupees and 50 paise
//     Currency c9(10, 10);
//     Currency c2(5);       // 5 rupees and 0 paise

//     std::cout << "c1 = " << c1 << std::endl;  // Output: "c1 = 10 rupees and 50 paise"
//     std::cout << "c2 = " << c2 << std::endl;  // Output: "c2 = 5 rupees and 0 paise"

//     Currency c3 = c1 + c2;
//     std::cout << "c3 = " << c3 << std::endl;  // Output: "c3 = 15 rupees and 50 paise"

//     Currency c10 = c1 + c9;
//     std::cout << "c10 = " << c10<< std::endl;  // Output: "c3 = 15 rupees and 50 paise"

//     Currency c4 = c1 - c2;
//     std::cout << "c4 = " << c4 << std::endl;  // Output: "c4 = 5 rupees and 50 paise"

//     Currency c5 = c1 + 3;
//     std::cout << "c5 = " << c5 << std::endl;  // Output: "c5 = 13 rupees and 50 paise"

//     Currency c6 = c2 - 2;
//     std::cout << "c6 = " << c6 << std::endl;  // Output: "c6 = 3 rupees and 0 paise"

//     if (c1 == c2) {
//         std::cout << "c1 is equal to c2" << std::endl;
//     } else {
//         std::cout << "c1 is not equal to c2" << std::endl;
//     }

//     if (c1 > c2) {
//         std::cout << "c1 is greater than c2" << std::endl;
//     } else {
//         std::cout << "c1 is not greater than c2" << std::endl;
//     }

//     if (c1 < c2) {
//         std::cout << "c1 is less than c2" << std::endl;
//     } else {
//         std::cout << "c1 is not less than c2" << std::endl;
//     }

//     ++c1;
//     std::cout << "c1 = " << c1 << std::endl;  

//     Currency c7 = c2++;
//     std::cout << "c2 = " << c2 << std::endl;  
//     std::cout << "c7 = " << c7 << std::endl;  

//     return 0;
// }
// complete below code and define all constructor and funcitons outside the class
class Currency {

int m_rupees;
int m_paise;
public:
Currency();
Currency(int,int);
Currency(int);
Currency operator+(const Currency&);
Currency operator-(const Currency&);
Currency operator+(int);
Currency operator-(int);
Currency& operator++();
Currency operator++(int);
bool operator==(const Currency&);
bool operator<(const Currency&);
bool operator>(const Currency&);
void dispay() const;
friend std::ostream& operator<<(std::ostream&, const Currency&);
};

Currency::Currency():m_rupees(0),m_paise(0){}
Currency::Currency(int rupees, int paise):m_rupees(rupees),m_paise(paise){}
Currency::Currency(int rupees):m_rupees(rupees),m_paise(0){}
Currency Currency::operator+(const Currency& other){
    int rupees=m_rupees+other.m_rupees;
    int paise=m_paise+other.m_paise;
    rupees+=paise/100;
    paise=paise%100;
    return Currency(rupees,paise);
}
Currency Currency::operator-(const Currency& other){
    int rupees=m_rupees-other.m_rupees;
    int paise=m_paise-other.m_paise;
    rupees-=paise/100;
    paise=paise%100;
    return Currency(rupees,paise);
}
Currency Currency::operator+(int v){
    int res=m_rupees+v;
    return Currency(res,m_paise);
}
Currency Currency::operator-(int v){
    int res=m_rupees-v;
    return Currency(res,m_paise);
}
Currency& Currency::operator++(){
    ++m_paise;
     if(m_paise>=100){
        m_rupees+=m_paise/100;
        m_paise=m_paise%100;
    }
        return *this;
}
Currency Currency::operator++(int){
    Currency temp=*this;
    (*this)++;
    return temp;
}
bool Currency::operator==(const Currency& other){
    if(m_rupees==other.m_rupees && m_paise==other.m_paise){
        return true;
    }
}
bool Currency::operator<(const Currency& other){
    if(m_rupees<other.m_rupees){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Currency& currency) {
  os << "Rupees " << currency.m_rupees << " and Paise " << currency.m_paise;
  return os;
}