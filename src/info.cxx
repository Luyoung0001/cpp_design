#include "../include/info.h"
#include "../include/employee.h"
#include "../include/technician.h"
#include "../include/salesman.h"
std::string Employee::CompanyName = "Default Company Name";
Employee makeEmployee() {
    int id, age, weight;
    std::string name;
    std::cout << "请输入员工编号:";
    std::cin >> id;
    std::cout << "请输入员工名字:";
    std::cin >> name;
    std::cout << "员工年龄:";
    std::cin >> age;
    std::cout << "员工体重:";
    std::cin >> weight;
    return Employee(id, name, age, weight); // RVO
}
bool Info::addInfo() {

    std::cout << "请输入员工类别:(1 技术人员;2 销售人员;3 经理;4 销售经理):";
    int cate = 0;
    std::cin >> cate;
    // Employee
    int hour;
    double hourlyRate;

    // Salesman
    int sales;
    double salesRate;

    // Manager
    double monthlyPay;

    // ManagerSales

    switch (cate) {
    case 1:
        std::cout << "技术人员信息初始化......" << std::endl;

        std::cout << "请输入技术人员工作时间:";
        std::cin >> hour;
        std::cout << "请输入技术人员的时薪(元):";
        std::cin >> hourlyRate;

        setTechnician(Technician(makeEmployee(), hour, hourlyRate));
        break;
    case 2:
        std::cout << "销售人员信息初始化......" << std::endl;

        std::cout << "请输入销售人员本月销售额(元):";
        std::cin >> sales;
        std::cout << "请输入销售人员提成比例:";
        std::cin >> salesRate;

        setSalesman(Salesman(makeEmployee(), sales, salesRate));
        break;

    case 3:
        std::cout << "经理人员信息初始化......" << std::endl;

        std::cout << "请输入经理人员本月固定工资(元):";
        std::cin >> monthlyPay;

        setManager(Manager(makeEmployee(), monthlyPay));
        break;
    case 4:
        std::cout << "销售经理信息初始化......" << std::endl;

        std::cout << "请输入销售经理本月固定工资(元):";
        std::cin >> monthlyPay;
        std::cout << "请输入销售经理下属部门本月销售总额(元):";
        std::cin >> sales;
        std::cout << "请输入销售经理的销售提成比例:";
        std::cin >> salesRate;

        // 构建两个基类
        // setTechnician();
        break;
    default:
        break;
    }
}
bool Info ::addNatrual() {}
bool Info::readInfo() {}
void Info::showInfo() {}
bool Info ::writeinfo() {}
