#include<iostream>
#include<string>
enum AccountType {
  Prepaid,
  Postpaid
};

class CustomerBase {
  std::string m_custId;
  std::string m_custName;
  std::string m_phone; 
  double m_balance;
  AccountType m_type;
 public:
  CustomerBase();
  CustomerBase(std::string,std::string,std::string,double);
  CustomerBase(std::string,std::string,std::string);
  CustomerBase(const CustomerBase&);
  virtual void credit(double)=0;           //recharge or billPay
  virtual void makeCall(double)=0;
  double getBalance() const;
  virtual void display() const=0;
};

class PrepaidCustomer : public CustomerBase {
  void recharge(double);
  public:
  PrepaidCustomer();
  PrepaidCustomer(std::string,std::string,std::string,double);
  PrepaidCustomer(std::string,std::string,std::string);
  void credit(double);           //recharge or billPay
  void makeCall(double);
  double getBalance() const;
  void display() const;
};
class PostpaidCustomer : public CustomerBase {
  void billPay(double);
  int m_billDate;
  public:
  PostpaidCustomer();
  PostpaidCustomer(std::string,std::string,std::string,double,int);
  PostpaidCustomer(std::string,std::string,std::string);
  void credit(double);           //recharge or billPay
  void makeCall(double);
  double getBalance() const;
  void display() const;
};

CustomerBase::CustomerBase():m_custId(""), m_custName(""), m_phone(""), m_balance(0), m_type(AccountType::Prepaid) {}
CustomerBase::CustomerBase(std::string id, std::string name, std::string phone, double bal):
m_custId(id),m_custName(name),m_phone(phone),m_balance(bal){}
CustomerBase::CustomerBase(std::string id, std::string name, std::string phone):m_custId(id),m_custName(name),m_phone(phone){}
CustomerBase::CustomerBase(const CustomerBase& ref):
m_custId(ref.m_custId),m_custName(ref.m_custName),m_phone(ref.m_phone),m_balance(ref.m_balance),m_type(ref.m_type){}

void CustomerBase::credit(double amt){
  m_balance+=amt;
}
void CustomerBase::makeCall(double duration){
  if(m_type==Prepaid){
    double rate=1.0*duration;
    m_balance-=rate;
  }
  else if(m_type==Postpaid){
    double rate=0.5*duration;
    m_balance-=rate;
  }
}
double CustomerBase::getBalance() const{
  return m_balance;
}
void CustomerBase::display() const{
  std::cout<<"id"<<m_custId<<"\n";
  std::cout<<"name"<<m_custName<<"\n";
  std::cout<<"phone number"<<m_phone<<"\n";
  std::cout<<"balance "<<m_balance<<"\n";
}

PrepaidCustomer::PrepaidCustomer():CustomerBase(){}
PrepaidCustomer::PrepaidCustomer(std::string id,std::string name,std::string phone,double bal):CustomerBase(id,name,phone,bal){}
PrepaidCustomer::PrepaidCustomer(std::string id,std::string name, std::string phone):CustomerBase(id,name,phone){}
// PrepaidCustomer::PrepaidCustomer(const PrepaidCustomer& other):CustomerBase(other.m_custId,other.m_custName,other.m_phone,other.m_balance,other.m_type){}
void PrepaidCustomer::recharge(double v){
  CustomerBase::credit();
}
void PrepaidCustomer::credit(double amt){
  CustomerBase::credit(amt);
}
void PrepaidCustomer::makeCall(double duration){
  CustomerBase::makeCall(duration);
}
double PrepaidCustomer::getBalance() const{
  return (CustomerBase::getBalance());
}
void PrepaidCustomer::display() const{
  CustomerBase::display();
}

PostpaidCustomer::PostpaidCustomer():CustomerBase(), m_billDate(0){}
PostpaidCustomer::PostpaidCustomer(std::string id, std::string name, std::string phone, double bal, int billDate):CustomerBase(id, name, phone, bal), m_billDate(billDate) {}
PostpaidCustomer::PostpaidCustomer(std::string id, std::string name, std::string phone):CustomerBase(id, name, phone), m_billDate(0) {}
// PostpaidCustomer::PostpaidCustomer(const PostpaidCustomer& pc):CustomerBase(pc.m_custId, pc.m_custName, pc.m_phone, pc.m_balance, pc.m_type), m_billDate(pc.m_billDate) {}

void PostpaidCustomer::billPay(double v1){
  CustomerBase::makeCall();
}

void PostpaidCustomer::credit(double amt){
  CustomerBase::credit(amt);
}
void PostpaidCustomer::makeCall(double duration){
  CustomerBase::makeCall(duration);
}

double PostpaidCustomer::getBalance() const{
  return (CustomerBase::getBalance());
}

void PostpaidCustomer::display() const{
  CustomerBase::display();
  std::cout<<"bill date is"<<m_billDate<<"\n";
}

int main(){
    CustomerBase *c1=new PostpaidCustomer("E002", "Jane Smith", "70000", 70, 124);
    CustomerBase *c2=new PrepaidCustomer("a12", "kjevv", "48451", 45);

    c1->display();
    std::cout<<"\n";
    c2->display();
    return 0;
}