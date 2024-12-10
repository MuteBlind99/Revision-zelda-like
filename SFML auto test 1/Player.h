#pragma once
#include <SFML/Graphics.hpp>


class Player:public sf::Drawable ,public sf::Transformable
{
public:

	Player();
	void PlayerMove(sf::Vector2f direction, float dt);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:

	sf::Texture texture_player_;
	sf::Sprite sprite_;
	bool is_running;
	float speed_running = 0.30f;
	float speed_walking = 0.15;
	bool sword_equiped = false;
	const  float speed_ = 50.5f;
};

