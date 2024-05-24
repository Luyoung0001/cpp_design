#include "../include/info.h"
#include "../include/menu.h"
#include <iostream>

using namespace std;
int main() {
    Menu menu;
    int select = 0;
    do {
        menu.select_menu(select);
    } while (select > 0);
    return 0;
}