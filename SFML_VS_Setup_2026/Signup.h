#pragma once
#include"SFML/Graphics.hpp"
#include"Rounded.h"
#include"Manage.h"
#include<iostream>
using namespace sf;
using namespace std;
class Signup
{
private:
	Manage* manage;
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
	Rounded input,username,password,enter ,back;
	Font fonts;
	Text setter;
	int current;
	string inputation[3];
public:
	void Pollevent();
	Signup();
	const bool running()const;
	void update();
	void render();
	~Signup();
};

