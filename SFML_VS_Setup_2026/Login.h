#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
class Login
{
private:
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
public:
	void Pollevent();
	Login();
	const bool running()const;
	void update();
	void render();
	~Login();
};

