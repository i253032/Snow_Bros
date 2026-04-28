#include "Signup.h"
void Signup::render()
{
	window->clear(Color::Blue);
	window->draw(picture_sprite);
	window->display();
}
Signup::Signup()
{
	window = new RenderWindow(VideoMode(1024, 1024), "Sign up");
	picture.loadFromFile("../../SFML_VS_Setup_2026/Assets/Login.png");
	this->picture_sprite.setTexture(picture);
	this->picture_sprite.setPosition({ 0.0f,0.0f });
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
		//case Event::MouseMoved:
		//{
		//	int temp_horizontal = event.mouseMove.x;
		//	int temp_vertical = event.mouseMove.y;
		//}
		//case Event::MouseButtonPressed:
		//{
		//	if (event.mouseButton.button == Mouse::Left)
		//	{
		//		int temp_horizontal = event.mouseButton.x;
		//		int temp_vertical = event.mouseButton.y;
		//	}
		//}

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
