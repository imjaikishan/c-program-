// #include<iostream>
// //#include <string.h>
// using namespace std;
// #define MAXSIZE 50
// template<typename T>
// class Stack
// {
//   T arr[MAXSIZE];     //T* arr
//   T maxlen;
//   T top;
//   public:
//   Stack(T len):maxlen(len),top(-1)
//   {
//     //arr=new T [maxlen];
//   }
//   ~Stack()
//   {
//     //delete[] arr;
//   }
//   void push(T val)
//   {
//     //TODO:overflow
//     arr[++top]=val;    
//   }
//   T pop()
//   {
//     //TODO:underflow
//     T val=arr[top--];
//     return val;
//   }
//   bool isEmpty()
//   {
//     return top==-1;
//   }
//   bool isFull()
//   {
//     return top==maxlen-1;
//   }  
// };


// int main()
// {
 
    
//     Stack<int> s1(10);
//     Stack<double> s2(5);
 
    
//     s1.push(2);
//     s1.push(54);
//     s1.push(255);
 
    
 
   
//     cout << s1.pop() << " is removed from stack"
//          << endl;
 
   
//     cout << s1.pop() << " is removed from stack "
//          << endl;
 
    
 
//     return 0;
// }
#include <iostream>
#include <cstdlib>

constexpr int max_size=50;

template<typename T>
class MyStack {
  T m_arr[max_size];
  int m_top;
  int m_maxlen;
  public:
  MyStack();
  MyStack(int len);
  void push(T val);
  T pop();
  T peek() const;
  bool isEmpty() const;
  bool isFull() const;
};

template<typename T>
MyStack<T>::MyStack():m_arr(max_size),m_top(-1){}
template<typename T>
MyStack<T>::MyStack(int len):m_arr(max_size),m_top(-1),m_maxlen(len){}
template<typename T>
void MyStack::push(T val){
  
}