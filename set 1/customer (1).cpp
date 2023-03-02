#include<iostream>

enum AccountType {
  Prepaid,
  Postpaid
};

class Customer {
  std::string m_custId;
  std::string m_custName;
  std::string m_phone; 
  double m_balance;
  AccountType m_type;
  public:
  Customer();
  Customer(std::string,std::string,std::string,double);
  Customer(std::string,std::string,std::string);
  Customer(const Customer&);
  void credit(double);           //recharge or billPay
  void makeCall(double);
  double getBalance() const;
  void display() const;
};
Customer::Customer():m_custId("1"),m_custName("Vaishu"),m_phone("9876223"),m_balance(100), m_type(Prepaid){}
Customer::Customer(std::string id, std::string name, std::string phone)
    : m_custId(id), m_custName(name), m_phone(phone), m_balance(100), m_type(Prepaid){}
Customer::Customer(std::string id, std::string name, std::string phone, double balance)
    : m_custId(id), m_custName(name), m_phone(phone), m_balance(balance){}
Customer::Customer(const Customer& customer)
    : m_custId(customer.m_custId), m_custName(customer.m_custName), m_phone(customer.m_phone),
      m_balance(customer.m_balance),m_type(Prepaid){}

void Customer::credit(double num)
{
    m_balance +=num;
}
void Customer::makeCall(double duration)
{
    // double cost = duration * 0.5;
    // if (m_type == Postpaid) {
    //   if (m_balance >= cost) {
    //     m_balance -= cost;
    //     std::cout << "Call made, duration: " << duration << ", cost: " << cost << std::endl;
    //   }
    //   else {
    //     std::cout << "Insufficient balance, please recharge your account." << std::endl;
    //   }
    // }
    // else { // Prepaid account
    //   if (m_balance > 0) {
    //     m_balance -= cost;
    //     std::cout << "Call made, duration: " << duration << ", cost: " << cost << std::endl;
    //   }
    //   else {
    //     std::cout << "Insufficient balance, please recharge your account." << std::endl;
    //   }
    // }
    // double rate = (m_type == Prepaid) ? 1.0 : 0.5;
    // m_balance -= rate * duration;

     if(m_type==Prepaid){
    double rate=1.0*duration;
    m_balance-=rate;
  }
  else if(m_type==Postpaid){
    double rate=0.5*duration;
    m_balance-=rate;
  }
}
double Customer::getBalance() const {
  return m_balance;
}
void Customer::display() const {
    std::cout << "Customer ID: " << m_custId << std::endl;
    std::cout << "Customer Name: " << m_custName << std::endl;
    std::cout << "Customer Phone: " << m_phone << std::endl;
    std::cout << "Account Type: " << ((m_type == Prepaid) ? "Prepaid" : "Postpaid") << std::endl;
    std::cout << "Account Balance: " << m_balance << std::endl;
}
int main()
{
    Customer customer;
    customer.display();

    Customer customer1("123", "John", "555-1234", 0.0);
    customer1.display();

    Customer customer2(customer1);
    customer2.credit(25.0);
    customer2.makeCall(5.0);
    customer2.display();

    std::cout << "New Balance: " << customer2.getBalance() << std::endl;
    return 0;
}