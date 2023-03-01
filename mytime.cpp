// #include<iostream>

// class MyTime {
//   int m_hours;
//   int m_minutes;
//   int m_seconds;

// public:
//   MyTime() : m_hours(0), m_minutes(0), m_seconds(0) {}
//   MyTime(int hours, int minutes, int seconds) : m_hours(hours), m_minutes(minutes), m_seconds(seconds) {}
//   // MyTime(int hours, int minutes) : MyTime(hours, minutes, 0) {}
//   MyTime(int hours,int minutes):m_hours(hours),m_minutes(minutes),m_seconds(0){}
//   MyTime(const MyTime& other) : m_hours(other.m_hours), m_minutes(other.m_minutes), m_seconds(other.m_seconds) {}
//   ~MyTime() {}

//   MyTime operator+(const MyTime& other) {
//     int total_seconds = m_hours * 3600 + m_minutes * 60 + m_seconds + other.m_hours * 3600 + other.m_minutes * 60 + other.m_seconds;
//     int hours = total_seconds / 3600;
//     int minutes = (total_seconds % 3600) / 60;
//     int seconds = total_seconds % 60;
//     return MyTime(hours, minutes, seconds);
//   }

//   MyTime operator-(const MyTime& other) {
//     int total_seconds1 = m_hours * 3600 + m_minutes * 60 + m_seconds;
//     int total_seconds2 = other.m_hours * 3600 + other.m_minutes * 60 + other.m_seconds;
//     int diff_seconds = total_seconds1 - total_seconds2;
//     if (diff_seconds < 0) {
//       diff_seconds += 86400;
//     }
//     int hours = diff_seconds / 3600;
//     int minutes = (diff_seconds % 3600) / 60;
//     int seconds = diff_seconds % 60;
//     return MyTime(hours, minutes, seconds);
//   }

//   MyTime operator+(int seconds) {
//     int total_seconds = m_hours * 3600 + m_minutes * 60 + m_seconds + seconds;
//     int hours = total_seconds / 3600;
//     int minutes = (total_seconds % 3600) / 60;
//     int remaining_seconds = total_seconds % 60;
//     return MyTime(hours, minutes, remaining_seconds);
//   }

//   MyTime operator-(int seconds) {
//     int total_seconds = m_hours * 3600 + m_minutes * 60 + m_seconds - seconds;
//     if (total_seconds < 0) {
//       total_seconds += 86400;
//     }
//     int hours = total_seconds / 3600;
//     int minutes = (total_seconds % 3600) / 60;
//     int remaining_seconds = total_seconds % 60;
//     return MyTime(hours, minutes, remaining_seconds);
//   }

//   MyTime& operator++() {
//     ++m_seconds;
//     if (m_seconds == 60) {
//       m_seconds = 0;
//       ++m_minutes;
//       if (m_minutes == 60) {
//         m_minutes = 0;
//         ++m_hours;
//         if (m_hours == 24) {
//           m_hours = 0;
//         }
//       }
//     }
//     return *this;
//   }

//   MyTime operator++(int) {
//     MyTime temp(*this);
//     ++(*this);
//     return temp;
//   }

//   MyTime& operator+=(const MyTime& other) {
//     *this = *this + other;
//     return *this;
//   }

//   bool operator==(const MyTime& t2) {
//         return (m_hours == t2.m_hours && m_minutes == t2.m_minutes && m_seconds == t2.m_seconds);
//     }

//     bool operator<(const MyTime& t2) {
//         if (m_hours < t2.m_hours) {
//             return true;
//         }
//         else if (m_hours == t2.m_hours) {
//             if (m_minutes < t2.m_minutes) {
//                 return true;
//             }
//             else if (m_minutes == t2.m_minutes) {
//                 if (m_seconds < t2.m_seconds) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool operator>(const MyTime& t2) {
//         if (m_hours > t2.m_hours) {
//             return true;
//         }
//         else if (m_hours == t2.m_hours) {
//             if (m_minutes > t2.m_minutes) {
//                 return true;
//             }
//             else if (m_minutes == t2.m_minutes) {
//                 if (m_seconds > t2.m_seconds) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     void display() const {
//         std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
//     }
//     friend std::ostream& operator<<(std::ostream& out, const MyTime& time);
// };   
// std::ostream& operator<<(std::ostream& out, const MyTime& time) {
//     out << time.m_hours << ":" << time.m_minutes << ":" << time.m_seconds;
//     return out;
// }

   
// int main() {
//   MyTime t1(15,20,0);
//   MyTime t2(20,55,0);
  
//   // Using operator+
//   MyTime sum = t1 + t2;
//   std::cout << "Sum of t1 and t2: " << sum << std::endl;

//   // Using operator-
//   MyTime diff = t1 - t2;
//   std::cout << "Difference of t1 and t2: " << diff << std::endl;

//   // Using operator+
//   MyTime new_time = t1 + 3600;
//   std::cout << "Adding 3600 seconds to t1: " << new_time << std::endl;

//   // Using operator-
//   MyTime new_time2 = t1 - 3600;
//   std::cout << "Subtracting 3600 seconds from t1: " << new_time2 << std::endl;

//   // Using operator++
//   std::cout << "t1 before increment: ";
//   t1.display();
//   t1++;
//   std::cout << "t1 after prefix increment: ";
//   t1.display();
//   MyTime temp = t1++;
//   std::cout << "t1 after postfix increment: ";
//   t1.display();
//   std::cout << "Value returned by postfix increment: " << temp << std::endl;

//   // Using operator+=
//   t1 += t2;
//   std::cout << "Adding t2 to t1 using operator+=: " << t1 << std::endl;

//   // Using operator==
//   MyTime t3(10, 30, 0);
//   MyTime t4(10, 30, 0);
//   if (t3 == t4) {
//     std::cout << "t3 and t4 are equal" << std::endl;
//   } else {
//     std::cout << "t3 and t4 are not equal" << std::endl;
//   }

//   // Using operator<
//   if (t2 < t1) {
//     std::cout << "t2 is less than t1" << std::endl;
//   } else {
//     std::cout << "t2 is not less than t1" << std::endl;
//   }

//   // Using operator>
//   if (t2 > t1) {
//     std::cout << "t2 is greater than t1" << std::endl;
//   } else {
//     std::cout << "t2 is not greater than t1" << std::endl;
//   }

//   return 0;
// }
#include<iostream>
class MyTime {
  int m_hours;
  int m_minutes;
  int m_seconds;
  public:
  MyTime();
  MyTime(int,int,int);
  MyTime(int,int);
  MyTime operator+(const MyTime&);
  MyTime operator-(const MyTime&);
  MyTime operator+(int);
  MyTime operator-(int);
  MyTime& operator++();
  MyTime operator++(int);
  MyTime& operator+=(const MyTime&);
  bool operator==(const MyTime&);
  bool operator<(const MyTime&);
  bool operator>(const MyTime&);
  void display() const;
  friend std::ostream& operator<<(std::ostream&, const MyTime&);
};

MyTime::MyTime():m_hours(0),m_minutes(0),m_seconds(0){}
MyTime::MyTime(int hours, int minutes, int seconds):m_hours(hours),m_minutes(minutes),m_seconds(seconds){}
MyTime::MyTime(int hours, int minutes):m_hours(hours),m_minutes(minutes),m_seconds(0){}
MyTime MyTime::operator+(const MyTime& ref){
  int totalseconds=(m_hours+ref.m_hours)*3600 + (m_minutes+ref.m_minutes)*60 + m_seconds+ref.m_seconds;
  int hours = totalseconds/3600;
  int minutes=(totalseconds % 3600)/60;
  int seconds=totalseconds % 60;
  return MyTime(hours,minutes,seconds);
}
MyTime MyTime::operator-(const MyTime& ref){
  int totalseconds1=m_hours*3600 + m_minutes*60+ m_seconds;
  int totalseconds2=ref.m_hours*3600 + ref.m_minutes*60+ ref.m_seconds;
  int diff=totalseconds1-totalseconds2;
  int diff2=totalseconds2-totalseconds1;
  if (diff>diff2){
    int hours = diff/3600;
    int minutes=(diff%3600) / 60;
    int seconds=diff%60;
    return MyTime(hours,minutes,seconds);
  }
  if (diff2>diff){
    int hours = diff2/3600;
    int minutes=(diff2%3600) / 60;
    int seconds=diff2%60;
    return MyTime(hours,minutes,seconds);
  }
}
MyTime MyTime::operator+(int second){
  int totalseconds=m_hours*3600 + m_minutes*60+ m_seconds+second;
  int hours=totalseconds/3600;
  int minutes=(totalseconds%3600) / 60;
  int seconds=totalseconds%60;
  return MyTime(hours,minutes,seconds);
}
MyTime MyTime::operator-(int second){
  int totalseconds=m_hours*3600 + m_minutes*60+ m_seconds - second;
  int hours=totalseconds/3600;
  int minutes=(totalseconds%3600) / 60;
  int seconds=totalseconds%60;
  return MyTime(hours,minutes,seconds);
}
MyTime& MyTime::operator++(){
  ++m_seconds;
  if (m_seconds>=60){
    ++m_minutes;
    m_seconds==0;
    if(m_minutes>=60){
      ++m_hours;
      m_minutes==0;
      if(m_hours>=24){
        m_hours==0;
      }
    }
  }
  return *this;
}
MyTime MyTime::operator++(int){
  MyTime temp=*this;
  ++(*this);
  return temp;
}
MyTime& MyTime::operator+=(const MyTime& ref){
  m_hours+=ref.m_hours;
  m_minutes+=ref.m_minutes;
  m_seconds+=ref.m_seconds;
  if (m_seconds>=60){
    m_minutes+=m_seconds/60;4
    m_seconds%=60;
  }
    if(m_minutes>=60){
      m_hours+=m_minutes/60;
      m_minutes%=60;
  }
  return *this;
}

bool MyTime::operator==(const MyTime& ref){
  if (m_hours == ref.m_hours && m_minutes==ref.m_minutes && m_seconds==ref.m_seconds){
    return true;
  }
}
bool MyTime::operator<(const MyTime& ref){
  if (m_hours<ref.m_hours){
    return true;
  }
    else if (m_hours==ref.m_hours && m_minutes < ref.m_minutes){
      return true;
    }
      else if (m_minutes==ref.m_minutes && m_seconds<ref.m_seconds){
        return true;
      }
  else{
    return false;
  }
}
bool MyTime::operator>(const MyTime& t2) {
    if (m_hours > t2.m_hours) {
            return true;
        }
        else if (m_hours == t2.m_hours) {
            if (m_minutes > t2.m_minutes) {
                return true;
            }
            else if (m_minutes == t2.m_minutes) {
                if (m_seconds > t2.m_seconds) {
                    return true;
                }
            }
        }
        else{
          return false;
        }
    }
void MyTime::display() const{
  std::cout<<m_hours<<":::"<<m_minutes<<":::"<<m_seconds<<"\n";
}

std::ostream& operator<<(std::ostream& os, const MyTime& mytime){
  os << mytime.m_hours << ":" << mytime.m_minutes << ":"<<mytime.m_seconds<<"\n";
  return os;
}
int main() {
  MyTime t1(15,20,0);
  MyTime t2(20,55,0);
  
  // Using operator+
  MyTime sum = t1 + t2;
  std::cout << "Sum of t1 and t2: " << sum << std::endl;

  // Using operator-
  MyTime diff = t1 - t2;
  std::cout << "Difference of t1 and t2: " << diff << std::endl;

  // Using operator+
  MyTime new_time = t1 + 3600;
  std::cout << "Adding 3600 seconds to t1: " << new_time << std::endl;

  // Using operator-
  MyTime new_time2 = t1 - 3600;
  std::cout << "Subtracting 3600 seconds from t1: " << new_time2 << std::endl;

  // Using operator++
  std::cout << "t1 before increment: ";
  t1.display();
  ++t1;
  std::cout << "t1 after prefix increment: ";
  t1.display();
  MyTime temp = t1++;
  std::cout << "t1 after postfix increment: ";
  t1.display();
  std::cout << "Value returned by postfix increment: " << temp << std::endl;

  // Using operator+=
  t1 += t2;
  std::cout << "Adding t2 to t1 using operator+=: " << t1 << std::endl;

  // Using operator==
  MyTime t3(10, 30, 0);
  MyTime t4(10, 30, 0);
  if (t3 == t4) {
    std::cout << "t3 and t4 are equal" << std::endl;
  } else {
    std::cout << "t3 and t4 are not equal" << std::endl;
  }

  // Using operator<
  if (t2 < t1) {
    std::cout << "t2 is less than t1" << std::endl;
  } else {
    std::cout << "t2 is not less than t1" << std::endl;
  }

  // Using operator>
  if (t2 > t1) {
    std::cout << "t2 is greater than t1" << std::endl;
  } else {
    std::cout << "t2 is not greater than t1" << std::endl;
  }

  return 0;
}