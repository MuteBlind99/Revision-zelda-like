#include "Player.h"

Player::Player()
{
	texture_player_.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0098.png");

	sprite_.setTexture(texture_player_);
	//sprite_.setPosition(16, 16);
	sprite_.setScale(2, 2);
}

void Player::PlayerMove(sf::Vector2f direction, float dt)
{
	const float speed = is_running ? speed_running : speed_walking;
	/*if (true)
	{


	}
	else
	{

	}*/
	sprite_.setPosition(sprite_.getPosition() + speed_ * direction * dt);

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}
