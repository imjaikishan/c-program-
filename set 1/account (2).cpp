#include<iostream>
#include<cstring>
class Account {
  std::string m_accNumber;
  std::string m_accName;
  double m_balance;
  public:
  Account();
  Account(std::string,std::string,double);
  Account(std::string,std::string);
  Account(const Account&);
  void debit(double);
  void credit(double);
  double getBalance() const;
  void display() const;
};
Account::Account():m_accNumber("1"),m_accName("V"),m_balance(0){}
Account::Account(std::string aNum,std::string aName,double bal):m_accNumber(aNum),m_accName(aName),m_balance(bal){}
Account::Account(std::string aNum,std::string aName):m_accNumber(aNum),m_accName(aName),m_balance(0){}
Account::Account(const Account& ref):m_accNumber(ref.m_accNumber),m_accName(ref.m_accName),m_balance(ref.m_balance){}
void Account::debit(double a)
{
    m_balance-=a;
}
void Account::credit(double a)
{
    m_balance+=a;
}
double Account::getBalance() const{
    return m_balance;
}
void Account::display() const{
    std::cout<< "Account Number:" << m_accNumber << std::endl;
    std::cout << "Account Name:" << m_accName << std::endl;
    std::cout << "Balance:" << m_balance << std::endl;
}
int main()
{
    Account a1;
    std::cout<< "Initial Account details are: "<< std::endl;
    a1.display();
    a1.credit(900);
    a1.debit(20);

    std::cout << "Updated account details are:" << std::endl;
    a1.display();
    return 0;
}
