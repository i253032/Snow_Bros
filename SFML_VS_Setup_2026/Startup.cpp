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
Startup::Startup()
{
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

			}
			if (login.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				login.setFillColor(Color(0, 0, 0, 0));
			}
			if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				sign.setFillColor(Color(0, 0, 0, 60));
			}
			if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				sign.setFillColor(Color(0, 0, 0, 0));
			}
			if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				guest.setFillColor(Color(0, 0, 0, 60));
			}
			if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
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
					std::cout << "Login Mode Selected" <<std:: endl;
				}
				if (sign.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					std::cout << "sign Mode Selected" <<std:: endl;
				}
				if (guest.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					std::cout << "Guest Mode Selected" <<std:: endl;
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
