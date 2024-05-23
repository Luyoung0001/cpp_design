#ifndef MANAGERSALES_H_
#define MANAGERSALES_H_
#include "employee.h"
#include "manager.h"
#include "salesman.h"
#include <utility>

class ManagerSales : public Manager, public Salesman {
  public:
    // 无参,默认构造
    ManagerSales(int _id = 0, std::string _name = "null", int _weight = 0,
                 int _age = 0, double _monthlyPay = 0, int _sales = 0,
                 double _salesRate = 0)
        : Employee(_id, _name, _weight, _age), // 显式初始化 Employee
          Manager(_monthlyPay), Salesman(_sales, _salesRate) {}

    // 复制构造
    ManagerSales(const ManagerSales &manS)
        : Employee(manS), Manager(manS), Salesman(manS) {}

    // 移动构造，没有冲突的资源
    ManagerSales(ManagerSales &&manS) noexcept
        : Employee(std::move(manS)), Manager(std::move(manS)),
          Salesman(std::move(manS)) {}
    // 复制赋值
    ManagerSales &operator=(const ManagerSales &manS) {
        if (this != &manS) {
            Employee::operator=(manS);
            Manager::operator=(manS);
            Salesman::operator=(manS);
        }
        return *this;
    }
    // 移动赋值
    ManagerSales &operator=(ManagerSales &&manS) noexcept {
        if (this != &manS) {
            Employee::operator=(std::move(manS));
            Manager::operator=(std::move(manS));
            Salesman::operator=(std::move(manS));
        }
        return *this;
    }

    void writeFile() override {}
    void pay() override {
        money = monthlyPay + salesRate * sales;
        std::cout << "money:" << money;
    }
    void showType() const override { std::cout << "销售经理类员工"; }
    void showInfo() const override {
        showType();
        Employee::showInfo();
    }
    ~ManagerSales() {}
};

#endif
