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
	Login* Logined;
	Signup* Signuped;
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
	static bool both_logined;
	Rounded login, sign, guest;
	string name[2];
public:
	void both_logined_set(const bool);
	bool both_logined_get()const;
	void Pollevent();
	Startup();
	const bool running()const;
	void update();
	void render();
	~Startup();
};

