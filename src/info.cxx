#include "../include/info.h"
#include "../include/employee.h"
#include "../include/manager.h"
#include "../include/managerSales.h"
#include "../include/salesman.h"
#include "../include/technician.h"
#include <chrono>
#include <fstream>
#include <iterator>
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

    int id, age, weight;
    std::string name;

    switch (cate) {
    case 1:
        std::cout << "技术人员信息初始化......" << std::endl;

        std::cout << "请输入技术人员工作时间:";
        std::cin >> hour;
        std::cout << "请输入技术人员的时薪(元):";
        std::cin >> hourlyRate;
        setTechnician(Technician(makeEmployee(), hour, hourlyRate));
        num++;
        break;
    case 2:
        std::cout << "销售人员信息初始化......" << std::endl;

        std::cout << "请输入销售人员本月销售额(元):";
        std::cin >> sales;
        std::cout << "请输入销售人员提成比例:";
        std::cin >> salesRate;

        setSalesman(Salesman(makeEmployee(), sales, salesRate));
        num++;
        break;

    case 3:
        std::cout << "经理人员信息初始化......" << std::endl;

        std::cout << "请输入经理人员本月固定工资(元):";
        std::cin >> monthlyPay;

        setManager(Manager(makeEmployee(), monthlyPay));
        num++;
        break;
    case 4:
        std::cout << "销售经理信息初始化......" << std::endl;
        std::cout << "请输入销售经理本月固定工资(元):";
        std::cin >> monthlyPay;
        std::cout << "请输入销售经理下属部门本月销售总额(元):";
        std::cin >> sales;
        std::cout << "请输入销售经理的销售提成比例:";
        std::cin >> salesRate;
        std::cout << "请输入员工编号:";
        std::cin >> id;
        std::cout << "请输入员工名字:";
        std::cin >> name;
        std::cout << "员工年龄:";
        std::cin >> age;
        std::cout << "员工体重:";
        std::cin >> weight;
        setManagerSales(ManagerSales(id, name, weight, age, monthlyPay, sales, salesRate));
        num++;
        break;
    default:
        std::cout << "您输入的编号不正确，请你重新输入:";
        this->addInfo();
    }
    return true;
}
bool Info ::addNatrual() {
    std::string comName;
    std::cout << "请输入公司名称:";
    std::cin >> comName;
    Employee::setCompanyName(comName);
    return true;
}
bool Info::readInfo() {
    // 从本地文件读取信息
    std::ifstream file("info.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return false; // 如果文件打开失败，返回 false
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return true; // 文件读取成功
}
void Info::showInfo() {
    // 遍历 vector
    for (auto emp : employees) {
        emp->showInfo();
    }
}
bool Info ::writeinfo() {
    // vector 持久化到本地
    std::ofstream file("info.txt", std::ios::app);
    if (!file.is_open()) {
        return false;
    }
    // 保存原始的cout缓冲区
    std::streambuf *originalCoutBuffer = std::cout.rdbuf();

    std::cout.rdbuf(file.rdbuf());

    // 重定向到文件
    for (auto emp : employees) {
        emp->showInfo();
    }
    std::cout.rdbuf(originalCoutBuffer);
    return true;
}
