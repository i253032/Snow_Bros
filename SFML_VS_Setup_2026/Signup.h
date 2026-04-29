#pragma once
#include"SFML/Graphics.hpp"
#include"Rounded.h"
#include<iostream>
using namespace sf;
class Signup
{
private:
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
	Rounded input,username,password,enter ,back;
	Font fonts;
	Text setter;
public:
	void Pollevent();
	Signup();
	const bool running()const;
	void update();
	void render();
	~Signup();
};

