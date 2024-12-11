#include "Game.h"

#include <iostream>

Game::Game()
{
	texture_map.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0000.png");

	sprite_map.setTexture(texture_map);
	sprite_map.setScale(2, 2);

	//texture_player_.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0098.png");

	//sprite_player_.setTexture(texture_player_);
	//sprite_player_.setPosition( 50, 50);
	/*player_.setScale(2, 2);
	player_.setPosition(16, 16);*/

	texture_coin.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0089.png");

	sprite_coin.setTexture(texture_coin);
	sprite_coin2.setTexture(texture_coin);
	/*sprite_coin.setPosition(3 * 50,3 * 50);*/
	sprite_coin.setScale(2, 2);
	sprite_coin2.setScale(2, 2);

	window_.create(sf::VideoMode(texture_map.getSize().x * sprite_map.getScale().x*8, texture_map.getSize().y * sprite_map.getScale().x *8), "Dungeon test");
	std::cout << window_.getSize().x << "(x) " << window_.getSize().y << "(y)" << '\n';
	/*font_end_game_.loadFromFile("asset\\mickey_mouse\\MickeyMouse_PERSONAL_USE_ONLY.otf");
	text_end_game_.setFont(font_end_game_);*/

	//item_.setPosition(32 * 4, 32 * 4);

	sprite_coin.setPosition(32 * 4, 32 * 4);
	sprite_coin2.setPosition(32 * 2, 32 * 1);

	Sprite_Coin_Vector.emplace_back(sprite_coin);
	Sprite_Coin_Vector.emplace_back(sprite_coin2);
}

void Game::GameLoop()
{
	while (window_.isOpen())
	{
		window_.clear();

		DrawMap();
		DrawPlayer();
		//Boucle simple Sprite_Coin_Vector
		for (auto i : Sprite_Coin_Vector)
		{
			window_.draw(i);
		}

		//window_.draw(item_);
		//DrawCoin();

			Event();
			CheckMove();

			
		
		//GameEnd();
		

		colldown_click_ += dt_;
		dt_ = clock_.restart().asSeconds();
		//std::cout << sprite_coin.getPosition().x << " / " << sprite_coin.getPosition().y << std::endl;
		window_.display();
	}
	

}

bool Game::GameEnd()
{
	while (window_.pollEvent(event_))
	{
		if (event_.type == sf::Event::Closed)
		{
			window_.close();
		}
	}
	/*if (item_.all_items_found)
	{
		text_end_game_.setPosition((sprite_map.getGlobalBounds().width * 8) + 200, 200);
		text_end_game_.setString("WIN");
		text_end_game_.setFillColor(sf::Color::Yellow);
		text_end_game_.setScale(2, 2);
		text_end_game_.setOrigin(text_end_game_.getGlobalBounds().width, text_end_game_.getGlobalBounds().height);
		window_.draw(text_end_game_);
	}
	else
	{
		text_end_game_.setPosition((sprite_map.getGlobalBounds().width * 8) + 200, 200);
		text_end_game_.setString("LOSE");
		text_end_game_.setFillColor(sf::Color::Red);
		text_end_game_.setScale(2, 2);
		text_end_game_.setOrigin(text_end_game_.getGlobalBounds().width, text_end_game_.getGlobalBounds().height);
		window_.draw(text_end_game_);
	}*/

	return NULL;
}

void Game::DrawMap()
{
	for (int row_size = 0; row_size <8; row_size++)//Y
	{
		for (int col_size = 0; col_size <8; col_size++)//X
		{

			switch (field_array_[8 * row_size + col_size])
			{
			case 0:

				texture_map.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0000.png");
				sprite_map.setPosition(col_size * sprite_map.getScale().x * 16, row_size * sprite_map.getScale().y * 16);


				window_.draw(sprite_map);

				break;

			case 2:
				texture_player_.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0098.png");
				sprite_player_.setTexture(texture_player_);

				player_.setPosition(col_size * sprite_map.getScale().x * 16, row_size * sprite_map.getScale().y * 16);
				//sprite_player_.setScale(2, 2);

				window_.draw(player_);
				break;

			case 1:
				texture_coin.loadFromFile("C:\\Users\\forna\\source\\repos\\SFML auto test 1\\asset\\Tiles\\tile_0089.png");
				sprite_coin.setTexture(texture_coin);

				sprite_coin.setPosition(col_size * sprite_map.getScale().x*16, row_size * sprite_map.getScale().y * 16);
				//sprite_coin.setScale(2, 2);

				window_.draw(sprite_coin);
				break;
			}

		}

	}
}

void Game::DrawPlayer() 
{
	
	window_.draw(player_);
}

void Game::DrawCoin()
{
	//sprite_coin.setOrigin(1,0);

	for (auto i : Sprite_Coin_Vector)
	{
		window_.draw(i);
	}
}

void Game::Event()
{
	while (window_.pollEvent(event_))
	{
		if (event_.type == sf::Event::Closed)
		{
			window_.close();
		}

		/*if(event_.type == sf::Event::KeyPressed)
		{
			CheckMove();

		}*/
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		//{
		//	//
		//	player_.CheckMove(sf::Vector2f(0, -1), dt);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		//{
		//	player_.MoveHero(sf::Vector2f(0, 1), dt);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		//{
		//	player_.MoveHero(sf::Vector2f(1, 0), dt);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		//{
		//	player_.MoveHero(sf::Vector2f(-1, 0), dt);
		//}
	}
}

void Game::CheckMove()
{
	sf::Vector2i move_player (0,0);

	int x = move_player.x / (texture_map.getSize().x * sprite_map.getScale().x);
	int y = move_player.y / (texture_map.getSize().y * sprite_map.getScale().y);

	if (colldown_click_ >= 1.f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player_.setPosition(player_.getPosition().x,player_.getPosition().y- (sprite_map.getScale().y* 16));
			colldown_click_ = 0;
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{

			player_.setPosition(player_.getPosition().x, player_.getPosition().y + (sprite_map.getScale().y * 16));
			colldown_click_ = 0;
		}

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

			player_.setPosition(player_.getPosition().x- (sprite_map.getScale().x*16), player_.getPosition().y);
			colldown_click_ = 0;
		}

	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

			player_.setPosition(player_.getPosition().x+ (sprite_map.getScale().x * 16), player_.getPosition().y) ;
			colldown_click_ = 0;
		}

		
	}

	for (int idx = 0; idx < Sprite_Coin_Vector.size(); ++idx)
	{
		if (player_.getPosition() == Sprite_Coin_Vector[idx].getPosition())
		{
			Sprite_Coin_Vector.erase(Sprite_Coin_Vector.begin() + idx);
		}
	}


	if (Sprite_Coin_Vector.empty())
	{
		std::cout << "End" << std::endl;
	}


	//setPosition(getPosition() * direction);

	
		//int idx = sprite_player_.getPosition();


		//if (item_.field_array_.at(idx) == 0)
		//{

		//	if (idx == item_.Chest())
		//	{
		//		item_.all_items_found = true;
		//		item_.field_array_[idx] = 2;
		//	}
		//	else
		//	{

		//		/*item_.SubPlayerTry();*/
		//		item_.field_array_[idx] = 1;
		//	}
		//}

}
