#pragma once
#include"SFML/Graphics.hpp"
#include"Rounded.h"
#include"Signup.h"
#include"Login.h"
#include<iostream>
using namespace sf;
class Startup
{
private:
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
	Rounded login, sign, guest;
public:
	void Pollevent();
	Startup();
	const bool running()const;
	void update();
	void render();
	~Startup();
};

