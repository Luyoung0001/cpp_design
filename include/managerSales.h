#ifndef MANAGERSALES_H_
#define MANAGERSALES_H_
#include "manager.h"
#include "salesman.h"

class ManagerSales : public Manager, public Salesman {
  public:
    // 无参构造
    ManagerSales() : Employee(), Manager(), Salesman() {}
    // 复制构造
    ManagerSales(const ManagerSales &manS) : Manager(manS), Salesman(manS) {}

    // 移动构造
    ManagerSales(ManagerSales &&manS)
        : Manager(std::move(manS)), Salesman(std::move(manS)) {}
    // 复制赋值
    ManagerSales &operator=(const ManagerSales &manS) {
        if (this != &manS) {
            Employee::operator=(manS); // 如果 Employee 是虚基类
            Manager::operator=(manS);
            Salesman::operator=(manS);
        }
        return *this;
    }
    // 移动赋值
    ManagerSales &operator=(ManagerSales &&manS) {
        if (this != &manS) {
            Employee::operator=(std::move(manS)); // 如果 Employee 是虚基类
            Manager::operator=(std::move(manS));
            Salesman::operator=(std::move(manS));
        }
        return *this;
    }

    void pay() { money = monthlyPay + salesRate * sales; }
    void showType() { std::cout << "销售经理类员工" << std::endl; }
};

#endif