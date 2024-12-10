#include "Item.h"

#include <ctime>
#include <SFML/Graphics/RenderTarget.hpp>

Item::Item()
{
	texture_.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0089.png");

	sprite_.setTexture(texture_);
	sprite_.setScale(2, 2);
}

//void Item::RandPosChest()
//{
//	srand(time(NULL));
//	coin_ = rand() % field_array_.size();
//}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, states);
}


