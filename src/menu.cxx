#include "../include/menu.h"
void Menu::handle_menu(int &select) {
    switch (select) {
    case 1:
        info.addInfo();
        break;
    case 2:
        info.showInfo();
        break;
    case 3:
        info.writeinfo();
        break;
    case 4:
        info.readInfo();
        break;
    case 5:
        select = 0;
        break;
    default:
        std::cout << "您输入的编号不正确，请你重新输入:";
        this->handle_menu(select);
    }
}
void Menu::select_menu(int &select) {
    std::cout << "**********\n";
    std::cout << "1. 添加信息\n";
    std::cout << "2. 预览信息\n";
    std::cout << "3. 写入文件\n";
    std::cout << "4. 读取信息\n";
    std::cout << "5. 退出程序\n";
    std::cout << "**********\n";
    std::cout << "请选择 1-5:";
    int sel;
    std::cin >> sel;
    select = sel;
    this->handle_menu(select);
}