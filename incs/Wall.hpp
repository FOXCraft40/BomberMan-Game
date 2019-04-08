/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall class definition
*/

#pragma once

#include "MapTile.hpp"

class PowerUp;
class Display;
class Map;

class Wall : public Entity {
	private:
		bool _breakable;
		PowerUp *_powerUp;
		irr::scene::ISceneNode *_wall;

	public:
		Wall(Display *display, bool breakable, PowerUp *powerUp);
		~Wall();
		void explode(Map *map, MapTile *tile);
		void display(int x, int y);
		bool isBreakable();
		bool containsPowerUp();
		PowerUp *getPowerUp();
};
