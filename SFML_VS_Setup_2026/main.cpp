#include <SFML/Graphics.hpp>
#include"Startup.h"
int main() {
    Startup game;
    while (game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}