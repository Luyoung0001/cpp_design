#ifndef MENU_H_
#define MENU_H_
#include "info.h"
class Menu {
    Info info;

  public:
    Menu() { info.addNatrual(); }
    void select_menu(int &select);
    void handle_menu(int &select);
    ~Menu() {}
};
#endif
