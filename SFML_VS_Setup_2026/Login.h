#pragma once
#include"SFML/Graphics.hpp"
#include"Rounded.h"
using namespace sf;
class Login
{
private:
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
	Rounded input, username, password, enter, back;
	Font fonts;
	Text setter;
public:
	void Pollevent();
	Login();
	const bool running()const;
	void update();
	void render();
	~Login();
};



