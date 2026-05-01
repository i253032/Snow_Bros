#include <SFML/Graphics.hpp>
#include "Menu.h"

int main()
{
    Menu menu;
    while (menu.running())
    {
        menu.update();
        menu.render();
    }
    return 0;
}