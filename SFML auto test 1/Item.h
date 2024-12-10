#pragma once
#include <array>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Item : public sf::Drawable, public sf::Transformable
{
public:
	bool all_items_found = false;
	sf::Texture texture_;
	sf::Sprite sprite_;
	Item();
	//void RandPosChest();
	int Chest() const { return coin_; }
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	int coin_ = 0;
};

