/*
// #include <iostream>
// #include <string>

// class AccountBase {

//   std::string m_accNumber;
//   std::string m_accName;
//   double m_balance;

//   public:
//   AccountBase() : m_accNumber(""),m_accName(""),m_balance(0){}
//   AccountBase(std::string,std::string,double) : m_accNumber(accNumber), m_accName(accName), m_balance(balance) {}
//   AccountBase(std::string,std::string) : m_accNumber(accNumber),m_accName(accName),m_balance(0) {}
//   AccountBase(const AccountBase& other) :  m_accNumber(other.m_accNumber),m_accName(other.m_accName),m_balance(other.m_balance) {}
//   virtual void debit(double)=0;
//   virtual void credit(double)=0;
//   virtual void display() const = 0;
//   double getBalance() const{
//     return m_balance;
//   }
// };

// class SavingsAccount : public AccountBase {
//   public:
//   SavingsAccount() : AccountBase() {}
//   SavingsAccount(std::string,std::string,double) : AccountBase(accNumber, accName, balance) {}
//   SavingsAccount(std::string,std::string) :  AccountBase(accNumber, accName) {}
//   void debit(double amount){
//     if (amount<getBalance()){
//         double balance = getBalance() - amount;
//         std::cout << "Debited: " << amount << " from savings account " << std::endl;
//         std::cout << "New balance is: " << balance << std::endl;
//     } 
//     else {
//       std::cout << "Insufficient balance in savings account" << std::endl;
//     }
//   }
//   void credit(double amount){
//     double balance = getBalance() + amount;
//     std::cout << "Credited: " << amount << " to savings account " << std::endl;
//     std::cout << "New balance is: " << balance << std::endl;
//   }
//   void display() const{
//     std::cout << "Savings Account" << std::endl;
//     std::cout << "Account number: " << m_accNumber << std::endl;
//     std::cout << "Account name: " << m_accName << std::endl;
//     std::cout << "Balance: " << m_balance << std::endl;
//   }
// };
// class CreditAccount : public AccountBase {
//   public:
//   CreditAccount() : AccountBase() {}
//   CreditAccount(std::string,std::string,double) : AccountBase(accNumber, accName, balance) {}
//   CreditAccount(std::string,std::string) : AccountBase(accNumber, accName) {}
//   void debit(double amount){
//     if (amount<getBalance()){
//         double balance = getBalance() - amount;
//         std::cout << "Debited: " << amount << " from savings account " << std::endl;
//         std::cout << "New balance is: " << balance << std::endl;
//     } 
//     else {
//       std::cout << "Insufficient balance in savings account" << std::endl;
//     }
//   }
//   void credit(double amount){
//     double balance = getBalance() + amount;
//     std::cout << "Credited: " << amount << " to savings account " << std::endl;
//     std::cout << "New balance is: " << balance << std::endl;
//   }
//   void display() const{
//     std::cout << "Savings Account" << std::endl;
//     std::cout << "Account number: " << m_accNumber << std::endl;
//     std::cout << "Account name: " << m_accName << std::endl;
//     std::cout << "Balance: " << m_balance << std::endl;
//   }
// };

// int main(){
//     SavingsAccount savings("SA001", "John Doe", 5000.00);
//     CreditAccount credit("CA001", "Jane Smith", 2000.00);

//     savings.display();
//     // savings.debit(2000.00);
//     // savings.credit(1000.00);

//     credit.display();
//     // credit.debit(500.00);
//     // credit.credit(1000.00);

//     return 0;
// }

#include <iostream>
#include <string>

class AccountBase {
//   public:
//   std::string getAccNumber() const { return m_accNumber; }
//   std::string getAccName() const { return m_accName; }
//   double getBalance123() const { return m_balance; }
//   // ...
  
  private:
  std::string m_accNumber;
  std::string m_accName;
  double m_balance;

  public:
  std::string getAccNumber() const { return m_accNumber; }
  std::string getAccName() const { return m_accName; }
  double getBalance123() const { return m_balance; }


  public:
  AccountBase() : m_accNumber(""),m_accName(""),m_balance(0){}
  AccountBase(std::string accNumber, std::string accName, double balance) : m_accNumber(accNumber), m_accName(accName), m_balance(balance) {}
  AccountBase(std::string accNumber, std::string accName) : m_accNumber(accNumber),m_accName(accName),m_balance(0) {}
  AccountBase(const AccountBase& other) :  m_accNumber(other.m_accNumber),m_accName(other.m_accName),m_balance(other.m_balance) {}
  virtual void debit(double)=0;
  virtual void credit(double)=0;
  virtual void display() const = 0;
  double getBalance() const{
    return m_balance;
  }
};


class SavingsAccount : public AccountBase {
  public:
  SavingsAccount() : AccountBase() {}
  public:
  SavingsAccount(std::string accNumber, std::string accName, double balance) : AccountBase(accNumber, accName, balance) {}
  SavingsAccount(std::string accNumber, std::string accName) :  AccountBase(accNumber, accName) {}
  void debit(double amount){
    if (amount<getBalance()){
        double balance = getBalance() - amount;
        std::cout << "Debited: " << amount << " from savings account " << std::endl;
        std::cout << "New balance is: " << balance << std::endl;
    } 
    else {
      std::cout << "Insufficient balance in savings account" << std::endl;
    }
  }
  void credit(double amount){
    double balance = getBalance() + amount;
    std::cout << "Credited: " << amount << " to savings account " << std::endl;
    std::cout << "New balance is: " << balance << std::endl;
  }
 
  void display() const{
    std::cout << "Savings Account" << std::endl;
    std::cout << "Account number: " << getAccNumber() << std::endl;
    std::cout << "Account name: " << getAccName() << std::endl;
    std::cout << "Balance: " <<  getBalance() << std::endl;
  }
};
class CreditAccount : public AccountBase {
  public:
  CreditAccount() : AccountBase() {}
  CreditAccount(std::string accNumber, std::string accName, double balance) : AccountBase(accNumber, accName, balance) {}
  CreditAccount(std::string accNumber, std::string accName) : AccountBase(accNumber, accName) {}
  void debit(double amount){
    if (amount<getBalance()){
        double balance = getBalance() - amount;
        std::cout << "Debited: " << amount << " from credit account " << std::endl;
        std::cout << "New balance is: " << balance << std::endl;
    } 
    else {
      std::cout << "Insufficient balance in credit account" << std::endl;
    }
  }
  void credit(double amount){
    double balance = getBalance() + amount;
    std::cout << "Credited: " << amount << " to savings account " << std::endl;
    std::cout << "New balance is: " << balance << std::endl;
  }
  void display() const{
    std::cout << "Savings Account" << std::endl;
    std::cout << "Account number: " << getAccNumber() << std::endl;
    std::cout << "Account name: " << getAccName() << std::endl;
    std::cout << "Balance: " << getBalance() << std::endl;
  }
};

int main(){
//     AccountBase* acc1 = new SavingsAccount("10001", "John Doe", 5000);
//     AccountBase* acc2 = new CreditAccount("20001", "Jane Smith", 10000);

// std::cout << "Before transactions:" << std::endl;
// acc1->display();
// acc2->display();
// std::cout << std::endl;

// acc1->debit(2000);
// acc1->credit(1000);
// acc2->debit(5000);
// acc2->credit(3000);

// std::cout << "After transactions:" << std::endl;
// acc1->display();
// acc2->display();

// delete acc1;
// delete acc2;
SavingsAccount savings("KNOW12", "LEX", 5000.00);
CreditAccount credit("KNOW45", "MERC", 2000.00);

savings.display();
savings.debit(2000.00);
savings.credit(1000.00);
savings.display();

credit.display();
credit.debit(500.00);
credit.credit(1000.00);


return 0;
}

*/
#include<iostream>
#include<string>

class AccountBase {
  std::string m_accNumber;
  std::string m_accName;
  double m_balance;
  public:
  AccountBase();
  AccountBase(std::string,std::string,double);
  AccountBase(std::string,std::string);
  
  AccountBase(const AccountBase&);
  virtual void debit(double)=0;
  virtual void credit(double)=0;
  virtual void display() const = 0;
  double getBalance() const;
};
class SavingsAccount : public AccountBase {
  public:
  SavingsAccount();
  SavingsAccount(std::string,std::string,double);
  SavingsAccount(std::string,std::string);
  void debit(double);
  void credit(double);
  void display() const;
};
class CreditAccount : public AccountBase {
  public:
  CreditAccount();
  CreditAccount(std::string,std::string,double);
  CreditAccount(std::string,std::string);
  void debit(double);
  void credit(double);
  void display() const;
};
AccountBase::AccountBase():m_accNumber("A001"),m_accName("mitul"),m_balance(1000){}
AccountBase::AccountBase(std::string number,std::string name,double bal):m_accNumber(number),m_accName(name),m_balance(bal){}
AccountBase::AccountBase(std::string number,std::string name):m_accNumber(number),m_accName(name),m_balance(0){}
AccountBase::AccountBase(const AccountBase& ref):m_accNumber(ref.m_accNumber),m_accName(ref.m_accName),m_balance(ref.m_balance){}
void AccountBase::debit(double amt){
  if (m_balance>amt){
    m_balance-=amt;
    std::cout<<"remaining balance is: "<< m_balance<<"\n";
  }
  else{
    std::cout<<"insufficient balance"<<"\n";
  }
}
void AccountBase::credit(double amt){
  m_balance+=amt;
  std::cout<<"updated balance is "<<m_balance<<"\n";
}
void AccountBase::display() const{
  std::cout << "Account number: " << m_accNumber << std::endl;
  std::cout << "Account name: " << m_accName << std::endl;
  std::cout << "Balance: " << m_balance << std::endl;
}
double AccountBase::getBalance() const{
  return m_balance;
}
SavingsAccount::SavingsAccount():AccountBase(){}
SavingsAccount::SavingsAccount(std::string number,std::string name,double bal):AccountBase(number,name,bal){}
SavingsAccount::SavingsAccount(std::string number,std::string name):AccountBase(number,name){}
void SavingsAccount::debit(double amount){
  std::cout<<"in savings account"<<"\n";
  AccountBase::debit(amount);
}
void  SavingsAccount::credit(double amount){
  std::cout<<"in savings account"<<"\n";
  AccountBase::credit(amount);
}
void SavingsAccount::display() const {
  std::cout << "Savings Account" << std::endl;
  AccountBase::display();
}

CreditAccount::CreditAccount():AccountBase(){}
CreditAccount::CreditAccount(std::string number,std::string name,double bal):AccountBase(number,name,bal){}
CreditAccount::CreditAccount(std::string number,std::string name):AccountBase(number,name){}

void CreditAccount::debit(double amount){
  std::cout<<"in current account"<<"\n";
  AccountBase::debit(amount);
}
void CreditAccount::credit(double amount){
  std::cout<<"in savings account"<<"\n";
  AccountBase::credit(amount);
}
void CreditAccount::display() const {
  std::cout << "Savings Account" << std::endl;
  AccountBase::display();
}

int main(){
  AccountBase* acc1 = new SavingsAccount("10001", "John Doe", 5000);
  AccountBase* acc2 = new CreditAccount("20001", "Jane Smith", 10000);

std::cout << "Before transactions:" << std::endl;
acc1->display();
acc2->display();
std::cout << std::endl;

// acc1->debit(2000);
// acc1->credit(1000);
// acc2->debit(5000);
// acc2->credit(3000);

// std::cout << "After transactions:" << std::endl;
// acc1->display();
// acc2->display();

delete acc1;
delete acc2;
return 0;

}