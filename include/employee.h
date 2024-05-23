#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "infomation.h"
#include <memory>
#include <string>
class Employee {
    static std::string CompanyName;

    int id;
    std::string name;
    Infomation info;

  protected:
    double money;

  public:
    static void setCompanyName(const std::string &comName) {
        CompanyName = comName; // 这里用复制赋值
    }
    static std::string &getCompanyName() { return CompanyName; }

    // 有参、默认构造
    Employee(int idd = 0, std::string namee = "null", int age = 0,
             int weight = 0, double moneyy = 0.0)
        : id(idd), name(namee), info(age, weight), money(moneyy) {}

    // 复制构造
    Employee(const Employee &emp)
        : id(emp.id), name(emp.name), info(emp.info), money(emp.money) {}
    // 移动构造
    Employee(Employee &&emp) noexcept {
        id = emp.id;
        name = std::move(emp.name);
        info = std::move(emp.info);
        money = emp.money;
        emp.id = 0;
        emp.name = "null";
        emp.info.infoSet(0, 0);
        emp.money = 0;
    }
    // 复制赋值操作符
    Employee &operator=(const Employee &emp) {
        if (this != &emp) {
            id = emp.id;
            name = emp.name;
            info = emp.info;
            money = emp.money;
        }
        return *this;
    }

    // 移动赋值操作符
    Employee &operator=(Employee &&emp) noexcept {
        if (this != &emp) {
            id = emp.id;
            name = std::move(emp.name);
            info = std::move(emp.info);
            money = emp.money;
            emp.id = 0;
            emp.name = "null";
            emp.info.infoSet(0, 0);
            emp.money = 0;
        }
        return *this;
    }
    // 显示员工信息
    void showInfo() {
        std::cout << "id: " << id << ", name: " << name << ", money: " << money
                  << std::endl;
        info.printInfo();
    }
    // 取消纯函数，可以构建基类对象
    virtual void writeFile() {};
    virtual void pay() {}
    virtual void showType(){}
    virtual ~Employee() {}
};
// 为了不违法 ODR，定义将会在包含本头文件的文件中定义静态变量
// std::string Employee::CompanyName = "Default Company Name";

#endif
