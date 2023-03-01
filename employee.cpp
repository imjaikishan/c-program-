// // #include <iostream>
// // #include <string>

// // class IEmployee
// // {
// // public:
// //     virtual void payroll() = 0;
// //     virtual void appraisal() = 0;
// // };

// // class Employee : public IEmployee
// // {
// // protected:
// //     std::string m_empid;
// //     std::string m_name;
// //     double m_salary;
// //     int m_exp;

// // public:
// //     Employee(std::string id, std::string name, double salary, int exp)
// //         : m_empid(id), m_name(name), m_salary(salary), m_exp(exp)
// //     {
// //     }

// //     virtual void display()
// //     {
// //         std::cout << "Employee ID: " << m_empid << "\n";
// //         std::cout << "Name: " << m_name << "\n";
// //         std::cout << "Salary: " << m_salary << "\n";
// //         std::cout << "Experience: " << m_exp << " years\n";
// //     }

// //     virtual void payroll() = 0;
// //     virtual void appraisal() = 0;
// // };

// // class Engineer : public Employee
// // {
// // private:
// //     int m_projCode;

// // public:
// //     Engineer(std::string id, std::string name, double salary, int exp, int code)
// //         : Employee(id, name, salary, exp), m_projCode(code)
// //     {
// //     }

// //     void payroll()
// //     {
// //         std::cout << "Paying salary to Engineer " << m_name << " with ID " << m_empid << "\n";
// //     }

// //     void appraisal()
// //     {
// //         std::cout << "Performing appraisal for Engineer " << m_name << " with ID " << m_empid << "\n";
// //     }

// //     void display()
// //     {
// //         std::cout << "Engineer\n";
// //         Employee::display();
// //         std::cout << "Project Code: " << m_projCode << "\n";
// //     }
// // };

// // class Manager : public Employee
// // {
// // private:
// //     int m_projCode;
// //     int m_reportees;

// // public:
// //     Manager(std::string id, std::string name, double salary, int exp, int code, int reportees)
// //         : Employee(id, name, salary, exp), m_projCode(code), m_reportees(reportees)
// //     {
// //     }

// //     void payroll()
// //     {
// //         std::cout << "Paying salary to Manager " << m_name << " with ID " << m_empid << "\n";
// //     }

// //     void appraisal()
// //     {
// //         std::cout << "Performing appraisal for Manager " << m_name << " with ID " << m_empid << "\n";
// //     }

// //     void display()
// //     {
// //         std::cout << "Manager\n";
// //         Employee::display();
// //         std::cout << "Project Code: " << m_projCode << "\n";
// //         std::cout << "Number of Reportees: " << m_reportees << "\n";
// //     }
// // };

// // int main()
// // {
// //     Employee *emp = new Engineer("merc", "halt", 6000, 6, 102);
// //     emp->display();
// //     emp->payroll();
// //     emp->appraisal();
// //     delete emp;

// //     std::cout << "\n";

// //     emp = new Manager("", "Jane", 80000, 10, 201, 5);
// //     emp->display();
// //     emp->payroll();
// //     emp->appraisal();
// //     delete emp;

// //     return 0;
// // }

// #include <iostream>
// #include <string>

// class IEmployee
// {
// public:
//     virtual void payroll() = 0;
//     virtual void appraisal() = 0;
// };

// class Employee : public IEmployee
// {
// private:
//     std::string m_empid;
//     std::string m_name;
//     double m_salary;
//     int m_exp;

// public:
//     Employee(std::string id, std::string name, double salary, int exp)
//     {
//         setEmpId(id);
//         setName(name);
//         setSalary(salary);
//         setExp(exp);
//     }


//     void setEmpId(std::string id) { m_empid = id; }
//     std::string getEmpId() const { return m_empid; }

//     void setName(std::string name) { m_name = name; }
//     std::string getName() const { return m_name; }

//     void setSalary(double salary) { m_salary = salary; }
//     double getSalary() const { return m_salary; }

//     void setExp(int exp) { m_exp = exp; }
//     int getExp() const { return m_exp; }


//     virtual void display()
//     {
//         std::cout << "Employee ID: " << getEmpId() << "\n";
//         std::cout << "Name: " << getName() << "\n";
//         std::cout << "Salary: " << getSalary() << "\n";
//         std::cout << "Experience: " << getExp() << " years\n";
//     }

//     virtual void payroll() = 0;
//     virtual void appraisal() = 0;
// };

// class Engineer : public Employee
// {
// private:
//     int m_projCode;

// public:
//     Engineer(std::string id, std::string name, double salary, int exp, int code)
//         : Employee(id, name, salary, exp), m_projCode(code)
//     {
//     }

//     void payroll()
//     {
//         std::cout << "Paying salary to Engineer " << getName() << " with ID " << getEmpId() << "\n";
//     }

//     void appraisal()
//     {
//         std::cout << "Performing appraisal for Engineer " << getName() << " with ID " << getEmpId() << "\n";
//     }

//     void display()
//     {
//         std::cout << "Engineer\n";
//         Employee::display();
//         std::cout << "Project Code: " << m_projCode << "\n";
//     }
// };

// class Manager : public Employee
// {
// private:
//     int m_projCode;
//     int m_reportees;

// public:
//     Manager(std::string id, std::string name, double salary, int exp, int code, int reportees)
//         : Employee(id, name, salary, exp), m_projCode(code), m_reportees(reportees)
//     {
//     }

//     void payroll()
//     {
//         std::cout << "Paying salary to Manager " << getName() << " with ID " << getEmpId() << "\n";
//     }

//     void appraisal()
//     {
//         std::cout << "Performing appraisal for Manager " << getName() << " with ID " << getEmpId() << "\n";
//     }

//     void display()
//     {
//         std::cout << "Manager\n";
//         Employee::display();
//         std::cout << "Project Code: " << m_projCode << "\n";
//         std::cout << "Number of Reportees: " << m_reportees << "\n";
//     }
// };

// int main()
// {
//     Employee *emp = new Engineer("E001", "John", 50000, 5, 101);
//     emp->display();
//     emp->payroll();
//     emp->appraisal();
//     delete emp;

//     std::cout << "\n";

//     emp = new Manager("M001", "Jane", 80000, 10, 201, 5);
//     emp->display();
//     emp->payroll();
//     emp->appraisal();
//     delete emp;

//     return 0;
// }
// #include<iostream>
// #include<string>
// class Employee{
// std::string m_empid;
// std::string m_name;
// double m_salary;
// int m_exp;
// public:
// Employee();
// Employee(std::string,std::string,double,int);
// virtual void display();
// virtual void payroll();
// virtual void appraisal();
// };

// class Engineer : public Employee{
// int m_projcode;

// public:
// Engineer(std::string,std::string,double,int,int);
// void display();
// void payroll();
// void appraisal();
// };


// Employee::Employee(): m_empid("1"),m_name("abcd"),m_salary(1000),m_exp(500){}
// Employee::Employee(std::string empid,std::string name,double salary,int exp):m_empid(empid),m_name(name),m_salary(salary),m_exp(exp){}
// void Employee::display(){
//     std::cout<<m_empid<<","<<m_name<<","<<m_salary<<","<<m_exp<<"\n";
// }
// void Employee::payroll(){
//     std::cout<<"payroll is"<<m_salary<<"\n";
// }
// void Employee::appraisal(){
//     std::cout<<"yes, appraisal by 20%"<<"\n";
// }
// Engineer::Engineer(std::string empid,std::string name,double salary,int exp, int projcode):Employee(empid,name,salary,exp),m_projcode(projcode){}
// void Engineer::display(){
//     Employee::display();
//     std::cout<<m_projcode<<"\n";
// }
// void Engineer::payroll(){
//     Employee::payroll();
//     std::cout<<"for derived class"<<"\n";
// }
// void Engineer::appraisal(){
//     Employee::appraisal();
//     std::cout<<"for derived class no appraisal"<<"\n";
// }
// int main() {
//     Employee emp("E001", "John Doe", 50000, 5);
//     Engineer eng("E002", "Jane Smith", 70000, 7, 12345);

//     std::cout << "Employee:\n";
//     emp.display();
//     emp.payroll();
//     emp.appraisal();

//     std::cout << "\nEngineer:\n";
//     eng.display();
//     eng.payroll();
//     eng.appraisal();

//     return 0;
// }
#include<iostream>
#include<string>

class IEmployee {
  public:
  virtual void payroll()=0;
  virtual void appraisal()=0;
};

class Employee:public IEmployee {
  std::string m_empid;
  std::string m_name;
  double m_salary;
  int m_exp;
  public:
  Employee(std::string id, std::string name, double salary,int exp);
  virtual void display();
};
class Engineer : public Employee {
  int m_projCode;
  public:
  Engineer(std::string id, std::string name,double salary,int exp,int code);
  void payroll();
  void appraisal();
  void display();
};
// // class Manager : public Employee {
//   int m_projCode;
//   int m_reportees;
//   public:
//   Manager(std::string id, std::string name, 
//      double salary,int exp,int code,int reprtees);
//   void payroll();
//   void appraisal();
//   void display();
// };
void IEmployee::payroll(){
    std::cout<<"salary is your payroll"<<"\n";
}
void IEmployee::appraisal(){
    std::cout<<"10% appraisal to all"<<"\n";
}
Employee::Employee(std::string id, std::string name, double salary,int exp):m_empid(id),m_name(name),m_salary(salary),m_exp(exp){}
void Employee::display(){
    IEmployee::payroll();
    // std::cout<<"\n";
    // IEmployee::appraisal();
}

Engineer::Engineer(std::string id, std::string name,double salary,int exp,int code):Employee(id,name,salary,exp),m_projCode(code){}
void Engineer::payroll(){
    std::cout<<"iemployee payroll method inherited"<<"\n";
    IEmployee::payroll();
}

void Engineer::appraisal(){
    std::cout<<"iemployee appraisal method inherited"<<"\n";
    IEmployee::appraisal(); 
    }

void Engineer::display(){
    std::cout<<"engineer display method inherited"<<"\n";
    Employee::display();
    std::cout<<"code is"<<m_projCode<<"\n";
    IEmployee::appraisal();
}

int main(){
    Employee *e1=new Engineer("E002", "Jane Smith",7000,5,45);
    // Employee e2("aaa0i","mvib",400,4);
    // e2::display();
    e1->display();
    return 0;
}