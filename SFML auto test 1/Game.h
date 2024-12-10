
#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "Item.h"
#include "Player.h"

class Game
{
public:
	Game();
	void GameLoop();
	bool GameEnd();
	void DrawMap();
	void DrawPlayer();
	void DrawCoin();
	void Event();
	void CheckMove();
private:
	std::array<int, 64>field_array_ = { 0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0 };


	sf::RenderWindow window_;

	sf::Texture texture_map;
	sf::Sprite sprite_map;
	sf::Texture texture_player_;
	sf::Sprite sprite_player_;
	sf::Texture texture_coin;
	sf::Sprite sprite_coin;
	sf::Font font_end_game_;
	sf::Text text_end_game_;
	sf::Event event_;

	//Item item_;
	Player player_;


	sf::Clock clock_;
	float dt_ = 0.f;
	float colldown_click_ = 0.f;
	
};
#endif

