#include "../include/info.h"
std::string Employee::CompanyName = "Default Company Name";
bool Info::addInfo() {
    std::cout << "请输入员工类别:(1 技术人员;2 销售人员;3 经理;4 销售经理):";
    int cate = 0;
    std::cin >> cate;
    switch (cate) {
    case 1:
    case 2:
    case 3:
    case 4:
    default:
    }
}
bool Info ::addNatrual() {}
bool Info::readInfo() {}
void Info::showInfo() {}
bool Info ::writeinfo() {}
