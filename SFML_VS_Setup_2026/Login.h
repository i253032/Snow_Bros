#pragma once
#include"SFML/Graphics.hpp"
#include"Rounded.h"
#include"Manage.h"
using namespace sf;
class Login
{
private:
	Manage* manage;
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
	Clock timer;
	float time;
	Rounded input, username, password, enter, back, username_taken;
	bool took, entered, success;
	Font fonts;
	Text setter;
	int current;
	string inputation[3];
public:
	void Pollevent();
	Login();
	const bool running()const;
	void update();
	void render();
	~Login();
};



