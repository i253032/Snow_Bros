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
void Startup::both_logined_set(const bool yes=false)
{
	both_logined = yes;
}
 bool Startup::both_logined_get()const
{
	 return both_logined;
}
 bool Startup::both_logined = false;
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
				if (login.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					cout << "Login Mode Selected" << endl;
					Logined=new Login();
					while (Logined->running())
					{
						Logined->update();
						Logined->render();
						if (Logined->getting())
						{
							both_logined = true;
							cout << "Both Logined" << endl;
							name[0] = Logined->name_getting(1);
							name[1] = Logined->name_getting(2);
							cout << "First Player : " << name[0] << endl;
							cout << "Second Player : " << name[1] << endl;
							delete Logined;
							Logined = nullptr;
							break;
						}
					}
				}
				if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					cout << "sign Mode Selected" <<endl;
					Signuped=new Signup();
					while (Signuped->running())
					{
						Signuped->update();
						Signuped->render();
					}
					delete Signuped;
					Signuped=nullptr;
				}
				if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					cout << "Guest Mode Selected" <<endl;
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
