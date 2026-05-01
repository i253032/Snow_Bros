#include "Menu.h"

Menu::Menu()
{
	warning = false;
	start_game = false;
	time = 0.0f;
	chosen = -1;
	names[0] = "";
	names[1] = "";
	saver = new Saver("../../SFML_VS_Setup_2026/Assets/Progress.txt");
	progress_loaded = false;
	window = new RenderWindow(VideoMode(1365, 768), "Snow Bros - Main Menu");

	picture.loadFromFile("../../SFML_VS_Setup_2026/Assets/Menu.png");
	picture_sprite.setTexture(picture);
	picture_sprite.setPosition({ 0.0f, 0.0f });

	// ONE font — only for the warning text
	body_font.loadFromFile("../../SFML_VS_Setup_2026/Assets/Heebo-Regular.ttf");
	body.setFont(body_font);
	body.setCharacterSize(24);
	body.setFillColor(Color::Black);

	// ---- Transparent buttons placed over the labels already in the image ----
	// (Tweak x/y/size to perfectly cover the labels in YOUR Menu.png)

	new_game = Rounded({ 185.0f, 35.0f }, 15.0f, 10);
	new_game.setFillColor(Color::Transparent);
	new_game.setOutlineColor(Color::White);
	new_game.setOutlineThickness(0.0f);
	new_game.setPosition(585.8, 341.3);

	continue_play = Rounded({ 155.0f, 35.0f }, 15.0f, 10);
	continue_play.setFillColor(Color::Transparent);
	continue_play.setOutlineColor(Color::White);
	continue_play.setOutlineThickness(0.0f);
	continue_play.setPosition(585.8f, 375.0f);

	leaderboard = Rounded({ 220.0f, 35.0f }, 15.0f, 10);
	leaderboard.setFillColor(Color::Transparent);
	leaderboard.setOutlineColor(Color::White);
	leaderboard.setOutlineThickness(0.0f);
	leaderboard.setPosition(585.8f, 410.0f);

	settings = Rounded({ 145.0f, 35.0f }, 15.0f, 10);
	settings.setFillColor(Color::Transparent);
	settings.setOutlineColor(Color::White);
	settings.setOutlineThickness(0.0f);
	settings.setPosition(595.0f, 455.0f);

	exit_app = Rounded({ 100.0f, 35.0f }, 15.0f, 10);
	exit_app.setFillColor(Color::Transparent);
	exit_app.setOutlineColor(Color::White);
	exit_app.setOutlineThickness(0.0f);
	exit_app.setPosition(585.8f, 490.0f);

	// White warning pill
	warning_box = Rounded({ 660.0f, 55.0f }, 15.0f, 10);
	warning_box.setFillColor(Color::White);
	warning_box.setOutlineColor(Color::White);
	warning_box.setOutlineThickness(0.0f);
	warning_box.setPosition({ 350.0f, 25.0f });
}
void Menu::load_both_progress()
{
	if (Startup::guest_get() == true)
	{
		// Guests don't read/write Progress.txt — fresh in-memory only
		progress_p1 = Progress(names[0]);
		progress_p2 = Progress(names[1]);
		progress_loaded = true;
		cout << "Guest mode — fresh progress in memory." << endl;
		return;
	}

	bool ok_1 = saver->load(names[0], progress_p1);
	bool ok_2 = saver->load(names[1], progress_p2);

	if (ok_1 == false)
	{
		progress_p1 = Progress(names[0]);   // first time → defaults
		cout << names[0] << " has no save yet — defaults." << endl;
	}
	else
	{
		cout << names[0] << " loaded — Lvl " << progress_p1.level_get()
			<< ", Gems " << progress_p1.gems_get()
			<< ", Score " << progress_p1.score_get() << endl;
	}

	if (ok_2 == false)
	{
		progress_p2 = Progress(names[1]);
		cout << names[1] << " has no save yet — defaults." << endl;
	}
	else
	{
		cout << names[1] << " loaded — Lvl " << progress_p2.level_get()
			<< ", Gems " << progress_p2.gems_get()
			<< ", Score " << progress_p2.score_get() << endl;
	}

	progress_loaded = true;
}

void Menu::reset_both_progress()
{
	progress_p1 = Progress(names[0]);
	progress_p2 = Progress(names[1]);

	if (Startup::guest_get() == false)
	{
		saver->save(progress_p1);
		saver->save(progress_p2);
		cout << "Both players' progress reset on disk." << endl;
	}
}
// Helper — opens Startup window, then returns to Menu
void Menu::open_startup()
{
	Startup* auth = new Startup();
	while (auth->running())
	{
		auth->update();
		auth->render();
	}
	delete auth;
	auth = nullptr;

	// Auth done → we're back in Menu. NOW load progress.
	if (Startup::both_logined_get() == true)
	{
		names[0] = Startup::name_get(0);
		names[1] = Startup::name_get(1);
		cout << "Player 1 : " << names[0] << endl;
		cout << "Player 2 : " << names[1] << endl;

		load_both_progress();
	}
}

void Menu::render()
{
	window->clear(Color::Blue);
	window->draw(picture_sprite);

	// Only invisible buttons — image already shows the text labels
	window->draw(new_game);
	window->draw(continue_play);
	window->draw(leaderboard);
	window->draw(settings);
	window->draw(exit_app);

	if (warning)
	{
		time = timer.getElapsedTime().asSeconds();
		window->draw(warning_box);
		body.setString("Please Login / Create Account / Setup as Guest first!");
		body.setPosition({ 365.0f, 38.0f });
		window->draw(body);
		if (time >= 2.0)
		{
			warning = false;
			open_startup();
		}
	}

	window->display();
}
void Menu::update()
{
	Pollevent();
}

void Menu::Pollevent()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				window->close();
			}
			break;

		case Event::MouseMoved:
		{
			int mx = event.mouseMove.x;
			int my = event.mouseMove.y;

			if (new_game.getGlobalBounds().contains(mx, my) == true)
			{
				new_game.setFillColor(Color(0, 0, 0, 60));
			}
			else if (new_game.getGlobalBounds().contains(mx, my) == false)
			{
				new_game.setFillColor(Color(0, 0, 0, 0));
			}
			if (continue_play.getGlobalBounds().contains(mx, my) == true)
			{
				continue_play.setFillColor(Color(0, 0, 0, 60));
			}
			else if (continue_play.getGlobalBounds().contains(mx, my) == false)
			{
				continue_play.setFillColor(Color(0, 0, 0, 0));
			}
			if (leaderboard.getGlobalBounds().contains(mx, my) == true)
			{
				leaderboard.setFillColor(Color(0, 0, 0, 60));
			}
			else if (leaderboard.getGlobalBounds().contains(mx, my) == false)
			{
				leaderboard.setFillColor(Color(0, 0, 0, 0));
			}
			if (settings.getGlobalBounds().contains(mx, my) == true)
			{
				settings.setFillColor(Color(0, 0, 0, 60));
			}
			else if (settings.getGlobalBounds().contains(mx, my) == false)
			{
				settings.setFillColor(Color(0, 0, 0, 0));
			}
			if (exit_app.getGlobalBounds().contains(mx, my) == true)
			{
				exit_app.setFillColor(Color(0, 0, 0, 60));
			}
			else if (exit_app.getGlobalBounds().contains(mx, my) == false)
			{
				exit_app.setFillColor(Color(0, 0, 0, 0));
			}
			break;
		}

		case Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				int mx = event.mouseButton.x;
				int my = event.mouseButton.y;

				// ---- EXIT always works ----
				if (exit_app.getGlobalBounds().contains(mx, my) == true)
				{
					cout << "Exit Selected" << endl;
					chosen = 5;
					window->close();
					break;
				}

				// ---- Any other option requires auth ----
				bool clicked_option = false;

				// --- NEW GAME ---
				if (new_game.getGlobalBounds().contains(mx, my) == true)
				{
					clicked_option = true;
					if (Startup::both_logined_get() == true)
					{
						reset_both_progress();          // wipe old save, start fresh
						cout << "New Game starting..." << endl;
						chosen = 1;
						start_game = true;
						window->close();
						break;
					}
				}

				// --- CONTINUE ---
				if (continue_play.getGlobalBounds().contains(mx, my) == true)
				{
					clicked_option = true;
					if (Startup::both_logined_get() == true)
					{
						if (Startup::guest_get() == true)
						{
							cout << "Guests cannot Continue (no save)." << endl;
						}
						else if (progress_p1.level_get() <= 1 && progress_p1.score_get() == 0
							&& progress_p2.level_get() <= 1 && progress_p2.score_get() == 0)
						{
							cout << "No saved progress yet   ... start a New Game first." << endl;
						}
						else
						{
							cout << "Continuing from Lvl " << progress_p1.level_get()
								<< " / Lvl " << progress_p2.level_get() << endl;
							chosen = 2;
							start_game = true;
							window->close();
							break;
						}
					}
				}
				if (leaderboard.getGlobalBounds().contains(mx, my) == true)
				{
					clicked_option = true;
					if (Startup::both_logined_get() == true)
					{
						cout << "Leaderboard Selected" << endl;
						chosen = 3;
					}
				}
				if (settings.getGlobalBounds().contains(mx, my) == true)
				{
					clicked_option = true;
					if (Startup::both_logined_get() == true)
					{
						cout << "Settings Selected" << endl;
						chosen = 4;
					}
				}

				// Clicked something but NOT logged in → warn + open Startup
				if (clicked_option == true && Startup::both_logined_get() == false)
				{
					warning = true;
					timer.restart();
					// After Startup closes we just return to Menu (no auto-start!)
				}
			}
			break;
		}
		default:
			break;
		}
	}
}

const bool Menu::running() const
{
	return window->isOpen();
}
bool Menu::starting() const
{
	return start_game;
}
int Menu::choice() const
{
	return chosen;
}
string Menu::name_get(int index) const
{
	if (index == 0)
	{
		return names[0];
	}
	if (index == 1)
	{
		return names[1];
	}
	return "";
}

Menu::~Menu()
{
	delete saver;
	saver = nullptr;
	delete window;
	window = nullptr;
}
Progress Menu::progress_get(int index) const
{
	if (index == 0)
	{
		return progress_p1;
	}
	if (index == 1)
	{
		return progress_p2;
	}
	return Progress();
}

void Menu::progress_set(int index, const Progress& p)
{
	if (index == 0)
	{
		progress_p1 = p;
	}
	if (index == 1)
	{
		progress_p2 = p;
	}
}

Saver* Menu::saver_get()
{
	return saver;
}

