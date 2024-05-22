#ifndef INFO_H_
#define INFO_H_
#include "employee.h"
#include "manager.h"
#include "managerSales.h"
#include "salesman.h"
#include "technician.h"
#include "vector"
class Info {
    std::vector<Employee> employees;
    Technician technician;
    Salesman salesman;
    Manager manager;
    ManagerSales managerSales;

  public:
    bool addNatrual();
    bool addInfo();
    void showInfo(); // 显示数组元素的信息
    bool writeinfo();
    bool readInfo();
    ~Info() {}
};
#endif