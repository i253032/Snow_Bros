#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
class Signup
{
private:
	RenderWindow* window;
	Texture picture;
	Sprite picture_sprite;
	Event event;
public:
	void Pollevent();
	Signup();
	const bool running()const;
	void update();
	void render();
	~Signup();
};

