#ifndef MANAGER_H_
#define MANAGER_H_
#include "employee.h"
#include <iterator>

class Manager : virtual public Employee {
  protected:
    double monthlyPay;

  public:
    // 有参、默认
    Manager(double moP = 0) : Employee(), monthlyPay(moP) {}
    // 复制构造
    Manager(const Manager &mana)
        : Employee(mana), monthlyPay(mana.monthlyPay) {}
    // 移动构造
    Manager(Manager &&mana) noexcept
        : Employee(std::move(mana)), monthlyPay(mana.monthlyPay) {}
    // 复制赋值
    Manager &operator=(const Manager &mana) {
        if (this != &mana) {
            Employee::operator=(mana);
            monthlyPay = mana.monthlyPay;
        }
        return *this;
    }
    // 移动构造
    Manager &operator=(Manager &&mana) noexcept {
        if (this != &mana) {
            Employee::operator=(std::move(mana));
            monthlyPay = mana.monthlyPay;
            mana.monthlyPay = 0;
        }
        return *this;
    }
    // 完美转发
    Manager(Employee &&emP, double moP)
        : Employee(std::forward<Employee>(emP)), monthlyPay(moP) {}

    void setMonPay(double moP) { monthlyPay = moP; }
    double getMonPay() { return monthlyPay; }

    // override
    void writeFile() override{}
    void pay() override{ money = monthlyPay; }
    void showType()override { std::cout << "经理类员工" << std::endl; }
    ~Manager() {}
};
#endif