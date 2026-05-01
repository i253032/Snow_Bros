#pragma once
#include "SFML/Graphics.hpp"
#include "Rounded.h"
#include "Startup.h"
#include "Saver.h"
#include "Progress.h"
#include <iostream>
using namespace sf;
using namespace std;

class Menu
{
private:
	RenderWindow* window;
	Texture picture;
	Sprite  picture_sprite;
	Event   event;
	Clock   timer;
	float   time;

	Rounded new_game, continue_play, leaderboard, settings, exit_app, warning_box;

	Font body_font;
	Text body;

	bool warning;
	bool start_game;
	int  chosen;

	string names[2];

	// 🆕 Save system lives here — separate file from accounts (Data.txt)
	Saver* saver;
	Progress progress_p1;
	Progress progress_p2;
	bool     progress_loaded;

	void open_startup();
	void load_both_progress();
	void reset_both_progress();

public:
	Menu();
	void Pollevent();
	void update();
	void render();
	const bool running()  const;
	bool       starting() const;
	int        choice()   const;
	string     name_get(int index) const;

	// Getters so future Game class can read/update progress
	Progress progress_get(int index) const;
	void     progress_set(int index, const Progress& p);
	Saver* saver_get();

	~Menu();
};