/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** PowerUp abstract class definition
*/

#pragma once

#include "PowerUpType.hpp"
#include "MapTile.hpp"

class Display;
class Player;

class PowerUp : public Entity {
	private:
		PowerUpType _PowerUpType;
		irr::scene::ISceneNode *_powerUp;

		void displayLifeUp(int x, int y);
		void displaySpeedUp(int x, int y);
		void displaySpeedDown(int x, int y);
		void displayBombUp(int x, int y);
		void displayBombDown(int x, int y);
		void displayPowerUp(int x, int y);
		void displayPowerDown(int x, int y);
		void displayWallPass(int x, int y);

	public:
		PowerUp(Display *display, PowerUpType type);
		~PowerUp();
		void applyToPlayer(Player *player, MapTile *tile);
		PowerUpType getPowerUpType();
		void display(int x, int y);
};
