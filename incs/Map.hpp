/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map class definition
*/

#pragma once

#include <vector>
#include <string>
#include "MapTile.hpp"
#include "PowerUpType.hpp"

class Game;
class Display;
class PowerUp;

class Map {
	private:
		Game *_game;
		Display *_display;
		unsigned int _width;
		unsigned int _height;
		std::vector<MapTile> _map;
		std::vector<irr::scene::ISceneNode *> _cubes;

		void displayGround(void);
		void displayCube(int i, int x, std::string const obj,
			std::string const png);
		void displayEntity(void);
		void fill();
		void generateWallCircles();
		void breakCircles();
		void breakCircle(MapTile *tile, int randomised);
		void randomiseBreakables();
		PowerUpType pickPowerUpType(int i);
		PowerUp *randomPowerUp();
		void removeVertex();
		void removeTemporary();

	public:
		Map(Game *game, Display *display,
			unsigned int width, unsigned int height);
		~Map();
		MapTile &getTile(unsigned int x, unsigned int y);
		bool canMove(int x, int y, bool wall_pass);
		bool isThereBomb(int x, int y);
		bool isThereFire(int x, int y);
		void update(void);
		void display(void);
		void generate();
		unsigned int getWidth();
		unsigned int getHeight();
};
