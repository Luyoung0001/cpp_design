#ifndef SALESMAN_H_
#define SALESMAN_H_
#include "employee.h"

class Salesman : virtual public Employee {
  protected:
    int sales;
    double salesRate;

  public:
    // 有参、默认构造
    Salesman(int sal = 0, double salr = 0.0) : sales(sal), salesRate(salr) {
        pay();
    }

    // 复制构造
    Salesman(const Salesman &salm)
        : Employee(salm), sales(salm.sales), salesRate(salm.salesRate) {}
    // 移动构造
    Salesman(Salesman &&salm) noexcept
        : Employee(std::move(salm)), sales(salm.sales),
          salesRate(salm.salesRate) {}
    // 复制赋值
    Salesman &operator=(const Salesman &salm) {
        if (this != &salm) {
            Employee::operator=(salm);
            sales = salm.sales;
            salesRate = salm.salesRate;
        }
        return *this;
    }
    // 移动赋值
    Salesman &operator=(Salesman &&salm) noexcept {
        if (this != &salm) {
            Employee::operator=(std::move(salm));
            sales = salm.sales;
            salesRate = salm.salesRate;
            salm.sales = 0;
            salm.salesRate = 0;
        }
        return *this;
    }
    Salesman(Employee &&emP, int sal = 0, double salR = 0)
        : Employee(std::move(emP)), sales(sal), salesRate(salR) {}

    // 复制构造
    Salesman(const Employee &emP, int sal = 0, double salR = 0)
        : Employee(emP), sales(sal), salesRate(salR) {}

    void setSales(int sl) { sales = sl; }
    int getSales() { return sales; }
    void setSalesRate(double sr) { salesRate = sr; }
    double getSalesRate() { return salesRate; }

    void writeFile() override {}
    void pay() override { money = sales * salesRate; }
    void showType() const override { std::cout << "销售类员工"; }

    void showInfo() const override {
        showType();
        Employee::showInfo();
    }
    ~Salesman() {}
};
#endif