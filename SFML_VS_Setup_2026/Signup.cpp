#include "Signup.h"
void Signup::render()
{
	window->clear(Color::Blue);
	window->draw(picture_sprite);
	window->draw(input);
	window->draw(username);
	window->draw(password);
	window->draw(back);
	window->draw(enter);
	setter.setFillColor(Color(32, 94, 201));
	setter.setPosition({ 385.2,310.3 });
	setter.setString("Name :");
	window->draw(setter);
	setter.setPosition({ 385.2,420.3 });
	setter.setString("Username :");
	window->draw(setter);
	setter.setPosition({ 385.2,530.3 });
	setter.setString("Password :");
	window->draw(setter);
	setter.setFillColor(Color::White);
	setter.setPosition({ 360.2,655.3 });
	setter.setString("Back");
	window->draw(setter);
	setter.setPosition({ 589.2,655.3 });
	setter.setString("Enter");
	window->draw(setter);
	window->display();
}
Signup::Signup()
{
	window = new RenderWindow(VideoMode(1024, 1024), "Sign up");
	picture.loadFromFile("../../SFML_VS_Setup_2026/Assets/Login.png");
	this->picture_sprite.setTexture(picture);
	this->picture_sprite.setPosition({ 0.0f,0.0f });
	input = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	input.setFillColor(Color(17, 52, 92));
	input.setOutlineColor(Color::White);
	input.setOutlineThickness(0.0f);
	input.setPosition({ 370.7f,346.8f });
	username = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	username.setFillColor(Color(17, 52, 92));
	username.setOutlineColor(Color::White);
	username.setOutlineThickness(0.0f);
	username.setPosition({ 370.7f,455.8f });
	password = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	password.setFillColor(Color(17, 52, 92));
	password.setOutlineColor(Color::White);
	password.setOutlineThickness(0.0f);
	password.setPosition({ 370.7f,570.8f });
	back = Rounded({ 100.7f,60.0f }, 15.0f, 10);
	back.setFillColor(Color(32, 102, 201));
	back.setOutlineColor(Color(32, 102, 201));
	back.setOutlineThickness(0.0f);
	back.setPosition({ 345.8,648.8 });
	enter = Rounded({ 100.7f,60.0f }, 15.0f, 10);
	enter.setFillColor(Color(32, 102, 201));
	enter.setOutlineColor(Color::White);
	enter.setOutlineThickness(0.0f);
	enter.setPosition({ 575.3,648.8 });
	fonts.loadFromFile("../../SFML_VS_Setup_2026/Assets/Heebo-Regular.ttf");
	setter.setFont(fonts);
	setter.setCharacterSize(30);
	setter.setFillColor(Color(32, 94, 201));
}
void Signup::update()
{
	Pollevent();
}

void Signup::Pollevent()
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
			if (back.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				back.setFillColor(Color(19, 70, 143));
			}
			else if (back.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				back.setFillColor(Color(32, 102, 201));
			}
			if (enter.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				enter.setFillColor(Color(19, 70, 143));
			}
			else if (enter.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				enter.setFillColor(Color(32, 102, 201));
			}
		}
		case Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				int temp_horizontal = event.mouseButton.x;
				int temp_vertical = event.mouseButton.y;
			}
		}

		}
	}
}
bool const Signup::running() const
{
	return window->isOpen();
}
Signup::~Signup()
{
	delete window;
	window = nullptr;
}
