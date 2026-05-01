#include "Startup.h"
void Startup::render()
{
	window->clear(Color::Blue);
	window->draw(picture_sprite);
	window->draw(login);
	window->draw(sign);
	window->draw(guest);
	window->display();
}
#include "Startup.h"

// --- Static member definitions ---
bool   Startup::both_logined = false;
bool   Startup::guest_mode = false;
string Startup::player_names[2];

void Startup::both_logined_set(bool yes)
{
	both_logined = yes;
}
bool Startup::both_logined_get()
{
	return both_logined;
}
bool Startup::guest_get()
{
	return guest_mode;
}
string Startup::name_get(int index)
{
	if (index == 0)
	{
		return player_names[0];
	}
	if (index == 1)
	{
		return player_names[1];
	}
	return "";
}
Startup::Startup()
{
	
	Logined = nullptr;
	Signuped = nullptr;
	window = new RenderWindow(VideoMode(1365, 768), "Snow Bros");
	picture.loadFromFile("../../SFML_VS_Setup_2026/Assets/Start.png");
	this->picture_sprite.setTexture(picture);
	this->picture_sprite.setPosition({ 0.0f,0.0f });
	login=Rounded({ 177.0f,100.0f },15.0f,10);
	login.setFillColor(Color::Transparent);
	login.setOutlineColor(Color::White);
	login.setOutlineThickness(0.0f);
	login.setPosition(371.0f, 373.0f);

	 sign=Rounded({ 177.0f,100.0f }, 15.0f, 10);
	sign.setFillColor(Color::Transparent);
	sign.setOutlineColor(Color::White);
	sign.setOutlineThickness(0.0f);
	sign.setPosition(603.0f, 373.0f);


	guest=Rounded({ 183.0f,100.0f }, 15.0f, 10);
	guest.setFillColor(Color::Transparent);
	guest.setOutlineColor(Color::White);
	guest.setOutlineThickness(0.0f);
	guest.setPosition(835.0f, 373.0f);
}
void Startup::update()
{
	Pollevent();
}
void Startup::Pollevent()
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
				break;
			}
		case Event::MouseMoved:
		{
			int temp_horizontal = event.mouseMove.x;
			int temp_vertical = event.mouseMove.y;
			if (login.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				login.setFillColor(Color(0, 0, 0, 60));

			}else if (login.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				login.setFillColor(Color(0, 0, 0, 0));
			}
			if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				sign.setFillColor(Color(0, 0, 0, 60));
			}else if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				sign.setFillColor(Color(0, 0, 0, 0));
			}
			if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				guest.setFillColor(Color(0, 0, 0, 60));
			}else if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				guest.setFillColor(Color(0, 0, 0, 0));
			}
			break;
		}
		case Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				int temp_horizontal = event.mouseButton.x;
				int temp_vertical = event.mouseButton.y;

				// ---- LOGIN ----
				if (login.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					cout << "Login Mode Selected" << endl;
					Logined = new Login();
					while (Logined->running())
					{
						Logined->update();
						Logined->render();
						if (Logined->getting())
						{
							both_logined = true;
							guest_mode = false;
							player_names[0] = Logined->name_getting(1);
							player_names[1] = Logined->name_getting(2);
							cout << "First Player : " << player_names[0] << endl;
							cout << "Second Player : " << player_names[1] << endl;
							delete Logined;
							Logined = nullptr;
							window->close();           // ← auto-close Startup
							break;
						}
					}
					if (Logined != nullptr)
					{
						delete Logined;
						Logined = nullptr;
					}
				}

				// ---- SIGN UP ----
				if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					cout << "Sign Mode Selected" << endl;
					Signuped = new Signup();
					while (Signuped->running())
					{
						Signuped->update();
						Signuped->render();
					}
					delete Signuped;
					Signuped = nullptr;
					// Sign-up done → user still needs to login → keep Startup open
				}

				// ---- GUEST ----
				if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					cout << "Guest Mode Selected" << endl;
					both_logined = true;
					guest_mode = true;
					player_names[0] = "Player 01";
					player_names[1] = "Player 02";
					window->close();                    // ← auto-close Startup
				}
				break;
			}
		}

		}
	}
}
bool const Startup::running() const
{
	return window->isOpen();
}
Startup::~Startup()
{
	delete window;
	window = nullptr;
}
