#pragma once
#include"SFML/Graphics.hpp"
#include<cmath>
using namespace sf;
using namespace std;
class Rounded : public Shape
{
private:
	Vector2f size;
	float round;
	int points;
public:
	Rounded()
	{

		this->size = {0,0
	};;
		this->round = 0;;
		this->points = 0;;
	}
	Rounded(Vector2f size, float round, int points)
	{
		this->size = size;;
		this->round = round;;
		this->points = points;;
	}
	virtual std::size_t getPointCount()const override
	{
		return points * 4;
	}
	virtual sf::Vector2f getPoint (std::size_t i) const override
	{
		int corner = i / points;
		float angle = (i - corner) * (90.0f / (points - 1)) * 3.14159265 / 180.0f;
		sf::Vector2f center;
		if (corner == 0)
		{
			center = { size.x - round, round };
		}else if (corner == 1)
		{
			center = { round, round };
		} else if (corner == 2)
		{
			center = {round,size.y - round };
		}else 
		{
			center = { size.x - round, size.y-round };
		}
		return { center.x + round * cos(angle),center.y - round * sin(angle) };
	}
};