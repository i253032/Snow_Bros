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
	Clock timer,timer_2;
	float time,time_2;
	Rounded input, username, password, enter, back, username_taken,input_2,username_2,password_2,enter_2,back_2, username_taken_2,waiting_box;
	bool took, entered, success,login_1,login_2,failure,failure_2;
	bool took_2, entered_2, success_2;
	Font fonts,player_name,wait;
	Text setter,names,waiting;
	int current;
	string inputation[6];
public:
	void Pollevent();
	Login();
	const bool running()const;
	void update();
	void render();
	~Login();
};



