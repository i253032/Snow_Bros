#include "Login.h"
void Login::render()
{
	window->clear(Color::Blue);
	window->draw(picture_sprite);
	if (!login_1)
	{
		window->draw(input);
		window->draw(username);
		window->draw(password);
		window->draw(back);
		window->draw(enter);
		// PLayer name setting
		names.setPosition({ 230.0f,180.0f });
		names.setString("Player : 01");
		window->draw(names);
		setter.setCharacterSize(30);
		setter.setFillColor(Color(32, 94, 201));
		setter.setPosition({ 210.2,255.3 });
		setter.setString("Name :");
		window->draw(setter);
		setter.setPosition({ 210.2,352.3 });
		setter.setString("Username :");
		window->draw(setter);
		setter.setPosition({ 210.2,455.3 });
		setter.setString("Password :");
		window->draw(setter);
		setter.setFillColor(Color::White);
		setter.setPosition({ 214.2,565.3 });
		setter.setString("Back");
		window->draw(setter);
		setter.setPosition({ 382.2,565.3 });
		setter.setString("Enter");
		window->draw(setter);
		setter.setCharacterSize(24);
		setter.setFillColor(Color::White);
		setter.setPosition({ 220.2,300.3 });
		setter.setString(inputation[0]);
		window->draw(setter);
		setter.setPosition({ 220.2,400.3 });
		setter.setString(inputation[1]);
		window->draw(setter);
		setter.setPosition({ 220.2,500.3 });
		setter.setString(inputation[2]);
		window->draw(setter);
		if (success)
		{
			time = timer.getElapsedTime().asSeconds();
			window->draw(username_taken);
			setter.setCharacterSize(24);
			setter.setPosition({ 190.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString(inputation[0] + " ! Account Login successfully!");
			window->draw(setter);
			if (time >= 1.0)
			{
				success = false;
				login_1 = true;
			}
		}
		if (entered)
		{
			time = timer.getElapsedTime().asSeconds();
			window->draw(username_taken);
			setter.setCharacterSize(24);
			if (inputation[0].empty() == true)
				setter.setPosition({ 290.0f,30.0f });
			else
				setter.setPosition({ 190.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString(inputation[0] + " ! All fields must fill!");
			window->draw(setter);
			if (time >= 5.0)
			{
				entered = false;
			}
		}
		if (failure)
		{
			time = timer.getElapsedTime().asSeconds();
			window->draw(username_taken);
			setter.setCharacterSize(24);
			setter.setPosition({ 290.0f,30.0f });			
			setter.setFillColor(Color::Black);
			setter.setString("Error! Should be different accounts");
			window->draw(setter);
			if (time >= 5.0)
			{
				failure_2 = false;
			}
		}
		if (took)
		{
			time = timer.getElapsedTime().asSeconds();
			window->draw(username_taken);
			setter.setCharacterSize(24);
			setter.setPosition({ 190.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString("Error! Wrong username or password");
			window->draw(setter);
			if (time >= 5.0)
			{
				took = false;
			}
		}
	}
	if (login_1)
	{
		waiting.setPosition({ 120.0f,355.1 });
		waiting.setString("You Sucessfully logined");
		window->draw(waiting);
		waiting.setPosition({ 140.0f,405.1 });
		waiting.setString("Waiting for Another");
		window->draw(back);
		window->draw(waiting);
		setter.setFillColor(Color::White);
		setter.setPosition({ 214.2,565.3 });
		setter.setString("Back");
		window->draw(setter);
	}
	if (!login_2)
	{
		names.setPosition({ 964.0f,180.0f });
		names.setString("Player : 02");
		window->draw(names);
		// For window 2
		window->draw(input_2);
		window->draw(username_2);
		window->draw(password_2);
		window->draw(back_2);
		window->draw(enter_2);
		setter.setCharacterSize(30);
		setter.setFillColor(Color(32, 94, 201));
		setter.setPosition({ 964.2,255.3 });
		setter.setString("Name :");
		window->draw(setter);
		setter.setPosition({ 964.2,352.3 });
		setter.setString("Username :");
		window->draw(setter);
		setter.setPosition({ 964.2,455.3 });
		setter.setString("Password :");
		window->draw(setter);
		setter.setFillColor(Color::White);
		setter.setPosition({ 964.2,565.3 });
		setter.setString("Back");
		window->draw(setter);
		setter.setPosition({ 1135.2,565.3 });
		setter.setString("Enter");
		window->draw(setter);
		setter.setCharacterSize(24);
		setter.setFillColor(Color::White);
		setter.setPosition({ 974.2,300.3 });
		setter.setString(inputation[3]);
		window->draw(setter);
		setter.setPosition({ 974.2,400.3 });
		setter.setString(inputation[4]);
		window->draw(setter);
		setter.setPosition({ 974.2,500.3 });
		setter.setString(inputation[5]);
		window->draw(setter);
		if (success_2)
		{
			time_2 = timer_2.getElapsedTime().asSeconds();
			window->draw(username_taken_2);
			setter.setCharacterSize(24);
			setter.setPosition({ 900.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString(inputation[3] + "! Login successfully!");
			window->draw(setter);
			if (time_2>= 1.0)
			{
				success_2 = false;
				login_2 = true;
			}
		}
		if (entered_2)
		{
			time_2 = timer_2.getElapsedTime().asSeconds();
			window->draw(username_taken_2);
			setter.setCharacterSize(24);
			if (inputation[3].empty() == true)
				setter.setPosition({ 1000.0f,30.0f });
			else
				setter.setPosition({ 900.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString(inputation[3] + " ! All fields must fill!");
			window->draw(setter);
			if (time_2 >= 5.0)
			{
				entered_2 = false;
			}
		}
		if (failure_2)
		{
			time_2 = timer_2.getElapsedTime().asSeconds();
			window->draw(username_taken_2);
			setter.setCharacterSize(24);
			setter.setPosition({ 1000.0f,30.0f });
			setter.setPosition({ 900.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString("Error! Should be different accounts!");
			window->draw(setter);
			if (time_2 >= 5.0)
			{
				failure_2 = false;
			}
		}
		if (took_2)
		{
			time_2 = timer_2.getElapsedTime().asSeconds();
			window->draw(username_taken_2);
			setter.setCharacterSize(24);
			setter.setPosition({ 900.0f,30.0f });
			setter.setFillColor(Color::Black);
			setter.setString("Error! Wrong username or password");
			window->draw(setter);
			if (time_2 >= 5.0)
			{
				took_2 = false;
			}
		}
	}
	
	if (login_2)
	{
		setter.setCharacterSize(30);
		waiting.setPosition({ 840.0f,355.1 });
		waiting.setString("You Sucessfully logined");
		window->draw(waiting);
		waiting.setPosition({ 855.0f,405.1 });
		waiting.setString("Waiting for Another");
		window->draw(waiting);
		setter.setFillColor(Color::White);
		setter.setPosition({ 964.2,565.3 });
		setter.setString("Back");
		window->draw(back_2);
		window->draw(setter);
	}
	window->display();
}
string Login::name_getting(int a)
{
	if (a == 2)
		a = 3;
	if (a == 1)
		a = 0;
	return inputation[a];
}
bool Login::getting()const
{
	return login_1 && login_2;
}
Login::Login()
{
	success = took = entered =success_2 = took_2 = entered_2 = login_1=login_2=failure=failure_2=false;
	time =time_2 = 0.0f;
	window = new RenderWindow(VideoMode(1398, 764), "Login");
	picture.loadFromFile("../../SFML_VS_Setup_2026/Assets/Multi_Login.jpg");
	this->picture_sprite.setTexture(picture);
	this->picture_sprite.setPosition({ 0.0f,0.0f });
	this->picture_sprite.setScale({ 0.717f,1.0f });
	input = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	input.setFillColor(Color(43, 60, 79));
	input.setOutlineColor(Color::White);
	input.setOutlineThickness(0.0f);
	input.setPosition({ 200.2,290.6 });
	username = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	username.setFillColor(Color(43, 60, 79));
	username.setOutlineColor(Color::White);
	username.setOutlineThickness(0.0f);
	username.setPosition({ 200.2f,395.8f });
	password = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	password.setFillColor(Color(43, 60, 79));
	password.setOutlineColor(Color::White);
	password.setOutlineThickness(0.0f);
	password.setPosition({ 200.2f,490.8f });
	back = Rounded({ 100.7f,40.0f }, 15.0f, 10);
	back.setFillColor(Color(43, 60, 79));
	back.setOutlineColor(Color(43, 60, 79));
	back.setOutlineThickness(0.0f);
	back.setPosition({ 195.8,565.8 });
	enter = Rounded({ 100.7f,40.0f }, 15.0f, 10);
	enter.setFillColor(Color(43, 60, 79));
	enter.setOutlineColor(Color(43, 60, 79));
	enter.setOutlineThickness(0.0f);
	enter.setPosition({ 368.3,565.8 });
	input_2 = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	input_2.setFillColor(Color(43, 60, 79));
	input_2.setOutlineColor(Color::White);
	input_2.setOutlineThickness(0.0f);
	input_2.setPosition({ 964.2f,290.6 });
	username_2 = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	username_2.setFillColor(Color(43, 60, 79));
	username_2.setOutlineColor(Color::White);
	username_2.setOutlineThickness(0.0f);
	username_2.setPosition({ 964.2f,395.8f });
	password_2 = Rounded({ 250.7f,50.0f }, 15.0f, 10);
	password_2.setFillColor(Color(43, 60, 79));
	password_2.setOutlineColor(Color::White);
	password_2.setOutlineThickness(0.0f);
	password_2.setPosition({ 964.2f,490.8f });
	back_2 = Rounded({ 100.7f,40.0f }, 15.0f, 10);
	back_2.setFillColor(Color(43, 60, 79));
	back_2.setOutlineColor(Color(43, 60, 79));
	back_2.setOutlineThickness(0.0f);
	back_2.setPosition({ 946.2,565.8 });
	enter_2 = Rounded({ 100.7f,40.0f }, 15.0f, 10);
	enter_2.setFillColor(Color(43, 60, 79));
	enter_2.setOutlineColor(Color(43, 60, 79));
	enter_2.setOutlineThickness(0.0f);
	enter_2.setPosition({ 1122.3,565.8 });
	username_taken = Rounded({ 450.7f,55.0f }, 15.0f, 10);
	username_taken.setFillColor(Color::White);
	username_taken.setOutlineColor(Color::White);
	username_taken.setOutlineThickness(0.0f);
	username_taken.setPosition({ 180.5,25.1 });
	username_taken_2 = Rounded({ 450.7f,55.0f }, 15.0f, 10);
	username_taken_2.setFillColor(Color::White);
	username_taken_2.setOutlineColor(Color::White);
	username_taken_2.setOutlineThickness(0.0f);
	username_taken_2.setPosition({ 890.0f,25.1 });
	fonts.loadFromFile("../../SFML_VS_Setup_2026/Assets/Heebo-Regular.ttf");
	player_name.loadFromFile("../../SFML_VS_Setup_2026/Assets/Player_name.TTF");
	wait.loadFromFile("../../SFML_VS_Setup_2026/Assets/Wait.TTF");
	waiting.setFont(wait);
	waiting.setFillColor(Color(37, 61, 122));
	waiting.setCharacterSize(25);
	names.setFont(player_name);
	names.setCharacterSize(45);
	names.setFillColor(Color::Blue);
	setter.setFont(fonts);
	setter.setCharacterSize(30);
	setter.setFillColor(Color(32, 94, 201));
	current = -1;
	manage = new Manage("../../SFML_VS_Setup_2026/Assets/Data.txt");
}
void Login::update()
{
	Pollevent();
}

void Login::Pollevent()
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
			}
			else
			{
				password.setFillColor(Color(43, 60, 79));
			}
			if (back_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				back_2.setFillColor(Color(19, 70, 143));
			}
			else if (back_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				back_2.setFillColor(Color(32, 102, 201));
			}
			if (enter_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				enter_2.setFillColor(Color(19, 70, 143));
			}
			else if (enter_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == false)
			{
				enter_2.setFillColor(Color(32, 102, 201));
			}
			if (input_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				input_2.setFillColor(Color(33, 46, 61));
			}
			else
			{
				input_2.setFillColor(Color(43, 60, 79));
			}
			if (username_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				username_2.setFillColor(Color(33, 46, 61));
			}
			else
			{
				username_2.setFillColor(Color(43, 60, 79));
			}
			if (password_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
			{
				password_2.setFillColor(Color(33, 46, 61));
			}
			else
			{
				password_2.setFillColor(Color(43, 60, 79));
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
						if (login_2)
						{
							if (inputation[1] == inputation[4])
							{
								login_1 = false;
								failure = true;
								timer.restart();
							}
						}
						if (inputation[1] != inputation[4])
						{
							bool first_login = manage->log_in(inputation[1], inputation[2]);
							if (first_login == true)
							{
								success = true;
								timer.restart();
							}
							if (first_login == false)
							{
								took = true;
								timer.restart();
							}
						}
					}
				}
				if (back.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					if (login_1 == true)
					{
						inputation[0] = inputation[1] = inputation[2] = "";
						login_1 = false;
					}else
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
				if (input_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					current = 3;
				}
				if (enter_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					if ((inputation[3].empty() == true || inputation[4].empty() == true) || inputation[5].empty() == true)
					{
						entered_2 = true;
						timer_2.restart();
					}
					else
					{
						if (login_1)
						{
							if (inputation[1] == inputation[4])
							{
								login_2 = false;
								failure_2 = true;
								timer_2.restart();
							}
						}
						if(inputation[1] != inputation[4])
						{
							bool second_login = manage->log_in(inputation[4], inputation[5]);
							if (second_login == true)
							{
								success_2 = true;
								timer_2.restart();
							}
							if (second_login == false)
							{
								took_2 = true;
								timer_2.restart();
							}
						}
					}
				}
				if (back_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					if (login_2 == true)
					{
						inputation[3] = inputation[4] = inputation[5] = "";
						login_2 = false;
					}
					else
						window->close();
				}
				if (username_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					current = 4;
				}
				if (password_2.getGlobalBounds().contains(temp_horizontal, temp_vertical) == true)
				{
					current = 5;
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
				if (inputation[current].empty() == false && typed == 8)
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
bool const Login::running() const
{
	return window->isOpen();
}
Login::~Login()
{
	delete window;
	delete manage;
	manage = nullptr;
	window = nullptr;
}