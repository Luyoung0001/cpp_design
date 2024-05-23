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
    std::vector<std::shared_ptr<Employee>> employees;

    int num; // vector 中元素数量
    Technician technician;
    Salesman salesman;
    Manager manager;
    ManagerSales managerSales;

  public:
    // setter
    void setTechnician(Technician &&tech) {
        employees.push_back(std::make_shared<Technician>(std::move(tech)));
    }
    void setSalesman(Salesman &&sal) {
        employees.push_back(std::make_shared<Salesman>(std::move(sal)));
    }
    void setManager(Manager &&mana) {
        employees.push_back(std::make_shared<Manager>(std::move(mana)));
    }
    void setManagerSales(ManagerSales &&manS) {
        employees.push_back(std::make_shared<ManagerSales>(std::move(manS)));
    }

    bool addNatrual();
    bool addInfo();
    void showInfo(); // 显示数组元素的信息
    bool writeinfo();
    bool readInfo();
    ~Info() {}
};
#endif