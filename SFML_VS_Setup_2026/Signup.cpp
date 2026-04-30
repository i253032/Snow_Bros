#include "Signup.h"
void Signup::render()
{
	username_taken.setPosition({ 345.5,25.1 });
	window->clear(Color::Blue);
	window->draw(picture_sprite);
	window->draw(input);
	window->draw(username);
	window->draw(password);
	window->draw(back);
	window->draw(enter);
	setter.setCharacterSize(30);
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
	setter.setCharacterSize(24);
	setter.setFillColor(Color::White);
	setter.setPosition({ 380.2,360.3 });
	setter.setString(inputation[0]);
	window->draw(setter);
	setter.setPosition({ 380.2,465.3 });
	setter.setString(inputation[1]);
	window->draw(setter);
	setter.setPosition({ 380.2,580.3 });
	setter.setString(inputation[2]);
	window->draw(setter);
	if (success)
	{
		time = timer.getElapsedTime().asSeconds();
		username_taken.setPosition(345.5, 15.1);
		window->draw(username_taken);
		username_taken.setPosition(345.5, 35.1);
		window->draw(username_taken);
		setter.setCharacterSize(24);
		setter.setPosition({ 360.0f,24.0f });
		setter.setFillColor(Color::Black);
		setter.setString("Account created successfully!");
		window->draw(setter);
		setter.setPosition({ 385.0f,60.0f });
		setter.setString("Login Your Account");
		window->draw(setter);
		if (time >= 3.0)
		{
			success = false;
			window->close();
		}
	}
	if (entered)
	{
		time = timer.getElapsedTime().asSeconds();
		window->draw(username_taken);
		setter.setCharacterSize(24);
		setter.setPosition({ 360.0f,37.0f });
		setter.setFillColor(Color::Black);
		setter.setString("All fields must fill!");
		window->draw(setter);
		if (time >= 5.0)
		{
			entered = false;
		}
	}
	if (took)
	{
		time = timer.getElapsedTime().asSeconds();
		window->draw(username_taken);
		setter.setCharacterSize(24);
		setter.setPosition({ 360.0f,37.0f });
		setter.setFillColor(Color::Black);
		setter.setString("Error! Username already taken");
		window->draw(setter);
		if (time >= 5.0)
		{
			took = false;
		}
	}
	window->display();
}
Signup::Signup()
{
	success=took =entered = false;
	time = 0.0f;
	window = new RenderWindow(VideoMode(1024, 1024), "Sign up");
	picture.loadFromFile("../../SFML_VS_Setup_2026/Assets/Login.png");
	this->picture_sprite.setTexture(picture);
	this->picture_sprite.setPosition({ 0.0f,0.0f });
	input = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	input.setFillColor(Color(43, 60, 79));
	input.setOutlineColor(Color::White);
	input.setOutlineThickness(0.0f);
	input.setPosition({ 370.7f,346.8f });
	username = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	username.setFillColor(Color(43, 60, 79));
	username.setOutlineColor(Color::White);
	username.setOutlineThickness(0.0f);
	username.setPosition({ 370.7f,455.8f });
	password = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	password.setFillColor(Color(43, 60, 79));
	password.setOutlineColor(Color::White);
	password.setOutlineThickness(0.0f);
	password.setPosition({ 370.7f,570.8f });
	username_taken = Rounded({ 365.7f,55.0f }, 15.0f, 10);
	username_taken.setFillColor(Color::White);
	username_taken.setOutlineColor(Color::White);
	username_taken.setOutlineThickness(0.0f);
	username_taken.setPosition({ 345.5,25.1 });
	back = Rounded({ 100.7f,60.0f }, 15.0f, 10);
	back.setFillColor(Color(43, 60, 79));
	back.setOutlineColor(Color(43, 60, 79));
	back.setOutlineThickness(0.0f);
	back.setPosition({ 345.8,648.8 });
	enter = Rounded({ 100.7f,60.0f }, 15.0f, 10);
	enter.setFillColor(Color(43, 60, 79));
	enter.setOutlineColor(Color(43, 60, 79));
	enter.setOutlineThickness(0.0f);
	enter.setPosition({ 575.3,648.8 });
	fonts.loadFromFile("../../SFML_VS_Setup_2026/Assets/Heebo-Regular.ttf");
	setter.setFont(fonts);
	setter.setCharacterSize(30);
	setter.setFillColor(Color(32, 94, 201));
	current = -1;
	manage = new Manage("../../SFML_VS_Setup_2026/Assets/Data.txt");
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
			}
			break;
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
			if (input.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				input.setFillColor(Color(33, 46, 61));
			}
			else 
			{
				input.setFillColor(Color(43, 60, 79));
			}
			if (username.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				username.setFillColor(Color(33, 46, 61));				
			}
			else
			{
				username.setFillColor(Color(43, 60, 79));
			}
			if (password.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				password.setFillColor(Color(33, 46, 61));				
			}else
			{
				password.setFillColor(Color(43, 60, 79));
			}
			break;
		}
		case Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				int temp_horizontal = event.mouseButton.x;
				int temp_vertical = event.mouseButton.y;
				current = -1;
				if (input.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					current = 0;
				}
				if (enter.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					if ((inputation[0].empty() == true || inputation[1].empty() == true) || inputation[2].empty() == true)
					{
							entered = true;
							timer.restart();
					}
					else
					{
						bool account_created = manage->sign_up(inputation[0], inputation[1], inputation[2]);
						if (account_created == true)
						{
							success = true;
							timer.restart();
						}
						if (account_created == false)
						{
							took = true;
							timer.restart();
						}
					}
				}
				if (back.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					window->close();
				}
				if (username.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					current = 1;
				}
				if (password.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					current = 2;
				}
			}
			break;
		}
		case Event::TextEntered:
		{
			if (current != -1)
			{
				int typed = (int)event.text.unicode;
				if (typed >= 32 && typed <= 126)
				{
					char character_typed = (char)typed;
					inputation[current] = inputation[current] + character_typed;
				}
				if (inputation[current].empty() == false && typed==8 )
				{
					int pointing = inputation[current].length();
					pointing--;
					inputation[current].erase(pointing, 1);
				}
			}
			break;
		}
		default:
		break;
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
