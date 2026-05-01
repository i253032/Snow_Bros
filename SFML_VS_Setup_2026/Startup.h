#pragma once
#include "SFML/Graphics.hpp"
#include "Rounded.h"
#include "Signup.h"
#include "Login.h"
#include <iostream>
using namespace sf;

class Startup
{
private:
    Login* Logined;
    Signup* Signuped;
    RenderWindow* window;
    Texture picture;
    Sprite  picture_sprite;
    Event   event;

    static bool   both_logined;
    static bool   guest_mode;
    static string player_names[2];          // ← NEW: shared name storage

    Rounded login, sign, guest;
public:
    static void   both_logined_set(bool);   // ← static now
    static bool   both_logined_get();       // ← static now
    static bool   guest_get();              // ← NEW
    static string name_get(int index);      // ← NEW

    void Pollevent();
    Startup();
    const bool running() const;
    void update();
    void render();
    ~Startup();
};