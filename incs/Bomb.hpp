/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bomb class definition
*/

#pragma once

#include <chrono>
#include "MapTile.hpp"

class Player;
class Map;

class Bomb : public Entity {
	private:
		unsigned int _power;
		Player 	*_owner;
		std::chrono::system_clock::time_point _end;
		irr::scene::ISceneNode *_graphicalObj;

		void drawFire(MapTile *tile);
		void explode(Map *map, MapTile *tile);
		void propagateFireXn(Map *map, MapTile *tile);
		void propagateFireX(Map *map, MapTile *tile);
		void propagateFireYn(Map *map, MapTile *tile);
		void propagateFireY(Map *map, MapTile *tile);

	public:
		Bomb(Display *display, unsigned int power, Player *owner);
		~Bomb();
		void update(Map *map, MapTile *tile);
		void display(int x, int y);
		unsigned int getPower();
};
