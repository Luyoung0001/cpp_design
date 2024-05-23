#ifndef INFO_H_
#define INFO_H_
#include "employee.h"
#include "manager.h"
#include "managerSales.h"
#include "salesman.h"
#include "technician.h"
#include "vector"
#include <utility>
class Info {
    std::vector<Employee> employees;
    int num; // vector 中元素数量
    Technician technician;
    Salesman salesman;
    Manager manager;
    ManagerSales managerSales;

  public:
    // setter

    void setTechnician(Technician &&tech) {
        technician = std::forward<Technician>(tech);
        employees.emplace_back(std::move(technician));
    }
    void setSalesman(Salesman &&sal) {
        salesman = std::forward<Salesman>(sal);
        employees.emplace_back(std::move(salesman));
    }
    void setManager(Manager &&mana) {
        manager = std::forward<Manager>(mana);
        employees.emplace_back(std::move(manager));
    }
    void setManaSal(ManagerSales &&manS) {
        managerSales = std::forward<ManagerSales>(manS);
        employees.emplace_back(std::move(managerSales));
    }

    bool addNatrual();
    bool addInfo();
    void showInfo(); // 显示数组元素的信息
    bool writeinfo();
    bool readInfo();
    ~Info() {}
};
#endif